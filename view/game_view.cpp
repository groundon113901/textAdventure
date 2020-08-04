/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/game_view.h"


GameView::GameView() {

}

void GameView::welcomePlayer(){
    cout << "-----------------------------------------" << endl;
    cout << "Welcome to Taxt Adventure" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
}

vector<string> GameView::loginScreen() {
    vector<string> credentials;
    InputReader reader;
    cout << "Login" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Username:" << endl;
    credentials.emplace_back(reader.readInput());
    cout << "Password:" << endl;
    credentials.emplace_back(reader.readInput());
    return credentials;
}

void GameView::onInventory(Slots playerSlots){
    playerSlots.toString();
}

void GameView::itemNotFound(){
    cout << "Item not Found" << endl;
}

void GameView::slotFull(){
    cout << "Slot already has item" << endl;
}

void GameView::itemEquiped(Item itemEquiped){
    cout << "Item: " << itemEquiped.getName() << " removed from inventory and equipped to character" << endl;
    cout << endl;
}

void GameView::itemRemoved(Item itemRemoved){
    cout << "Item: " << itemRemoved.getName() << " removed from character and added to inventory" << endl;
    cout << endl;
}
void GameView::itemDropped(Item itemRemoved){
    cout << "Item: " << itemRemoved.getName() << " dropped from inventory on to room floor" << endl;
    cout << endl;
}

void GameView::itemPickedUp(Item itemPickedUp) {
    cout << "Item: " << itemPickedUp.getName() << " added to inventory" << endl;
    cout << endl;
}

void GameView::loginFailed() {
    cout << "Incorrect username or password" << endl;
}

void GameView::onRoomChange(Room room) {
    cout << "You entered: " << endl;
    onLook(room);
}

void GameView::roomClosed(){
    cout << "Door is closed" << endl;
}

void GameView::roomOpened(){
    cout << "Door is opened" << endl;
}
void GameView::onAreas(map<int, Area> areas) {
    int count = 1;
    for (auto e : areas){
        cout << count << " " << e.second.getName()<< endl;
        count++;
    }
}
void GameView::onLook(Room room) {
    cout << endl << room.getName() << endl;
    cout << "---------------------" << endl;
    cout << room.getDescription() << endl << endl;

    auto items = room.getItems();
    if(items.size() > 0){
        cout << "Items: ";
        size_t count = 0;


        for(auto item : items){
            if(count != items.size() - 1){
                cout << item.getName() << ", ";
                count++;
            }else{
                cout << item.getName() << "." << endl << endl;
            }
        }
    }
}

void GameView::inValidOption(){
    cout << "Invalid option entered" << endl;
}

void GameView::inValidOption(string msg){
    cout << "Invalid option entered:" << msg << endl;
}

void GameView::onExits(GameModel model){
    map<Directions::Direction, Exit> exitsMap = model.getRoomExitsMap(model.getCurrentRoomId());
    size_t count = 1;
    cout << "Exits: ";
    for (auto e : exitsMap){
        Exit exit = e.second;
        string closedOrOpen;
        Room toRoom = model.getRoomById(exit.getToRoom());
        if (exit.getRoomIsOpen()){
            closedOrOpen = "Open";
        } else {
            closedOrOpen = "Closed";
        }
        cout << exit.getDirectionToString() << ": " << toRoom.getName() << boolalpha << " [" << closedOrOpen << "]";
        if (count < exitsMap.size()){
            cout << ", ";
        } else {
            cout << ".";
        }
        count++;
    }
    cout << endl;
}

void GameView::gameSaved() {
    cout << endl << "GAME SAVED!" << endl;
}


