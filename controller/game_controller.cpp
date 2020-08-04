/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/game_controller.h"

GameController::GameController() {

}

GameController::GameController(GameModel model, GameView view, boost::filesystem::path storageLocation){
    this->model = std::move(model);
    this->view = view;
    this->dataDir = std::move(storageLocation);
}

GameModel &GameController::getModel() {
    return model;
}
Directions::Direction convertAction(Actions::Action action){
    switch(action){
        case Actions::Action::N:
           return Directions::NORTH;
        case Actions::Action::E:
            return Directions::EAST;
        case Actions::Action::S:
            return Directions::SOUTH;
        case Actions::Action::W:
            return Directions::WEST;
        default:
            return Directions::NORTH;
    }
}
void GameController::handleAction(Actions::Action action, vector<string> cmdString) {
    switch(action) {
        case Actions::Action::N :
        case Actions::Action::E :
        case Actions::Action::S :
        case Actions::Action::W : {
            Directions::Direction direction = convertAction(action);
            map<Directions::Direction, Exit> ex = model.getRoomExitsMap(model.getCurrentRoomId());
            auto it = ex.find(direction);
            if (it != ex.end()) {
                if (it->second.getRoomIsOpen()){
                    move(it->second.getToRoom());
                    exits();
                }else {
                    move(-1);
                }
            }
            break;
        }
        case Actions::Action::LOOK:
            look();
            break;
        case Actions::Action::SAVE:
            if(cmdString.size() == 3 && (cmdString[1] == "ascii" || cmdString[1] == "binary")) {
                save(cmdString[1] == "ascii", cmdString[2]);
            }else{
                string msg = "incorrect save command format.\n";
                msg += "save <save-format> <path>\n";
                msg += "<save-format> ascii or binary \n";
                msg += "<path> -- folder path (folders created if they dont exist)";
                view.inValidOption(msg);
            }
            break;
        case Actions::Action::QUIT:
            quit();
            break;
        case Actions::Action::EXITS:
            exits();
            break;
        case Actions::Action::WEAR:
            wear(cmdString);
            break;
        case Actions::Action::REMOVE:
            remove(cmdString);
            break;
        case Actions::Action::DROP:
            drop(cmdString);
            break;
        case Actions::Action::AREAS:
            areas();
            break;
        case Actions::Action::PICKUP:
            pickup(cmdString);
            break;
        case Actions::Action::OPEN:
        case Actions::Action::CLOSE: {
            doorOpenORClose(cmdString, action);
            break;
        }
        case Actions::Action::INVENTORY:
            inventory();
            break;
        default:
            view.inValidOption();
            break;
    }
}

void GameController::inventory(){
    view.onInventory(model.getCharacter()->getItemSlots());
}
void GameController::doorOpenORClose(vector<string> input, Actions::Action action){
    list<string> values = Directions::getEnumValues();
    Directions d;
    Directions::Direction direction;
    map<Directions::Direction, Exit> exitsMap = model.getRoomExitsMap(model.getCurrentRoomId());
    for (string& s: values){
        size_t found = s.find(input[1]);
        if (found == 0){
            direction = d.getFromString(s);
        }
    }
    auto it = exitsMap.find(direction);
    if (it != exitsMap.end()) {
        if ((it->second.getRoomIsOpen() && action == Actions::OPEN) || (!it->second.getRoomIsOpen() && action == Actions::CLOSE)){
            view.inValidOption();
        } else if ((it->second.getRoomIsOpen() && action == Actions::CLOSE)) {
            model.openOrCloseDoor(it->second, action);
            view.roomClosed();
            exits();
        } else if (!it->second.getRoomIsOpen() && action == Actions::OPEN) {
            model.openOrCloseDoor(it->second, action);
            view.roomOpened();
            exits();
        }
    }
}

void GameController::move(int roomId){
    if (roomId > 0) {
        model.setCurrentRoom(roomId);
        model.updateMoveCount(-1);
        view.onRoomChange(model.getRoomById(roomId));
    } else{
        view.roomClosed();
    }
}

void GameController::wear(const vector<string>& input){
    Slots playerSlots = model.getCharacter()->getItemSlots();
    unordered_map<string, Item> slots = playerSlots.getSlots();
    map<int, Item> inventory = playerSlots.getInventory();
    string wearPos;
    string item;
    int positionKey = -1;
    Item itemToequip;
    if (input.size() > 1){

        for (auto e: inventory) {
            size_t found = Helper::partialMatch(item, e.second.getName());
            if (found == 0){
                itemToequip = e.second;
                positionKey = e.first;
                wearPos = Item::wearPositionToString(itemToequip.getWearPosition());
            }
        }

        if(!itemToequip.getName().empty()){
            for (auto e : slots){
                if(e.second.getName().empty() && boost::iequals(wearPos, e.first)){
                    model.wearItem(itemToequip, positionKey);
                    view.itemEquiped(itemToequip);
                    view.onInventory(model.getCharacter()->getItemSlots());
                }else if(!e.second.getName().empty() && boost::iequals(wearPos, e.first)){
                    view.slotFull();
                }
            }


        }else{
            cout << item << endl;
            view.itemNotFound();
        }
    } else {
        view.inValidOption();
    }
}

void GameController::remove(const vector<string>& input){
    Slots playerSlots = model.getCharacter()->getItemSlots();
    unordered_map<string, Item> items = playerSlots.getSlots();
    int invetoryCount = model.getCharacter()->getItemSlots().getInventoryCount();
    string item;
    Item itemToRemove;

    if (input.size() > 1 || invetoryCount >= 10) {
        item = Helper::stringFromVector(input);
        for (auto e: items) {
            string name = e.second.getName();
            boost::to_lower(name);
            boost::to_lower(item);
            size_t found = Helper::partialMatch(item, e.second.getName());
            if (found == 0){
                itemToRemove = e.second;
            }
        }
        if(!itemToRemove.getName().empty()){
            model.removeItem(itemToRemove);
            view.itemRemoved(itemToRemove);
            view.onInventory(model.getCharacter()->getItemSlots());
        }else{
            cout << item << endl;
            view.itemNotFound();
        }
    } else {
        view.inValidOption();
    }
}

void GameController::drop(const vector<string>& input){
    Slots playerSlots = model.getCharacter()->getItemSlots();
    map<int, Item> inventory = playerSlots.getInventory();
    string item;
    Item itemToRemove;
    int positionKey = -1;
    if (input.size() > 1){
        item = Helper::stringFromVector(input);
        for (auto e: inventory) {
            size_t found = Helper::partialMatch(item, e.second.getName());
            if (found == 0){
                itemToRemove = e.second;
                positionKey = e.first;
            }
        }
        if(!itemToRemove.getName().empty()){
            model.dropItem(positionKey);
            model.insertRoomItem(model.getCurrentRoomId(), itemToRemove);
            view.itemDropped(itemToRemove);
            view.onInventory(model.getCharacter()->getItemSlots());
        }else{
            cout << item << endl;
            view.itemNotFound();
        }
    } else {
        view.inValidOption();
    }
}

void GameController::pickup(const vector<string>& input){
    vector<Item> items = model.getRoomById(model.getCurrentRoomId()).getItems();
    Slots playerSlots = model.getCharacter()->getItemSlots();
    map<int, Item> inventory = playerSlots.getInventory();
    string item;
    Item itemToAdd;

    if (input.size() > 1){
        item = Helper::stringFromVector(input);
        for (auto e: items) {
            size_t found = Helper::partialMatch(item, e.getName());
            if (found == 0){
                itemToAdd = e;
            }
        }
        if(!itemToAdd.getName().empty()){
            model.pickupItem(itemToAdd);
            model.removeRoomItem(model.getCurrentRoomId(), itemToAdd);
            view.itemPickedUp(itemToAdd);
            view.onInventory(model.getCharacter()->getItemSlots());
        }else{
            cout << item << endl;
            view.itemNotFound();
        }
    } else {
        view.inValidOption();
    }
}

void GameController::save(bool isAscii, const boost::filesystem::path& where){
    DataWriter writer = DataWriter(where);
    //Set new default save location
    model.isAscii(isAscii);
    dataDir = where;
    if(isAscii){
        writer.writeAscii(model);
    } else {
        writer.writeBinary(model);
    }

    view.gameSaved();
}

void GameController::look(){
    view.onLook(model.getRoomById(model.getCurrentRoomId()));
    exits();
}

void GameController::areas(){
    view.onAreas(model.getAreas());
}

void GameController::exits(){
    view.onExits(model);
}

void GameController::quit(){
    cout << "Saving..." << endl;
    //Save in default format and dir (which is set on load and manual save)
    save(model.isAscii(), dataDir);
    cout << "Quitting..." << endl;
    exit(EXIT_SUCCESS);
}

bool GameController::isLoggedIn() {
    return model.getCurrentUser()->getId() != -1;
}

void GameController::attemptLogin(vector<string> input) {
    User* user = model.getUserByUsername(input[0]);
    if(user->getId() != -1){
        size_t pwdHash = hash<string>{}(input[1]);
        if(user->comparePwd(pwdHash)){
            model.setCurrentUser(*user);
        };
    }
}

User* GameController::getCurrentUser() {
    return model.getCurrentUser();
}

[[noreturn]] void GameController::moveRegen(GameModel&) {
    for(;;){
        this_thread::sleep_for(chrono::seconds(1));
        model.updateMoveCount(1);
    }
}

void GameController::startMoveRegen() {
   thread(&GameController::moveRegen, this, ref(model)).detach();

}




