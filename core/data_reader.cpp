/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/data_reader.h"

DataReader::DataReader() {

}

DataReader::DataReader(boost::filesystem::path dir) {
    this->dataDir = dir;
}

vector<vector<string>> DataReader::readLines(boost::filesystem::path filePath) {

    vector<vector<string>> results;

    ifstream infile(filePath);
    string line;

    while (getline(infile, line)) {
        vector<string> values;
        split(values, line, is_any_of("\t"));
        results.push_back(values);
    }

    return results;
}

map<int, Item> DataReader::loadItems() {

    map<int, Item> items;
    boost::filesystem::path itemPath = this->dataDir / "items.txt";

    for(vector<string> item : readLines(itemPath)){
        int id = stoi(item[0]);
        Item::WearPosition eqType = Item::positionFromString(item[1]);
        string name = item[2];
        string desc = item[3];
        int value = stoi(item[4]);
        items.insert( pair<int, Item>(id, Item(id, name, desc, value, eqType)));
    }

    return items;
}

map<int, Room> DataReader::loadRooms(GameModel *pModel) {
    map<int, Room> rooms;
    bool hasItems = false;
    boost::filesystem::path roomPath = this->dataDir / "rooms.txt";
    vector<vector<string>> roomLines = readLines(roomPath);


    for(vector<string> room : roomLines){
        int id = stoi(room[0]);
        int areaRoomNo = stoi(room[1]);
        int areaNo = stoi(room[2]);
        string name = room[3];
        string desc = room[4];
        vector<Item> roomItems;

        if(room.size() > 5){
            //Add Items
            if(stoi(room[5]) != 0) {
                int roomsSize = stoi(room[5]) + 5;
                for (int i = 5; i < roomsSize; i++) {
                    roomItems.emplace_back(pModel->getItemById(stoi(room[i])));
                }
            }
            hasItems = true;
        }

        Room roomObj = Room(id, name, desc, areaRoomNo, areaNo, roomItems);

        roomObj.setRoomExits(pModel->generateRoomExitsMap(roomObj.getId()));

        rooms.insert(pair<int, Room>(id, roomObj));
    }


    if(!hasItems){
        scatterItems(&rooms, pModel);
    }
    return rooms;
}

void DataReader::scatterItems(map<int, Room> *pRooms, GameModel *pModel) {
    map<int, Item> tempItems = pModel->getItems();
    map<int, int> itemDropCounts;
    while(!tempItems.empty()) {
        int randomRoomMove = Helper::randomZeroToN(pRooms->size() - 1);
        auto randRoom = pRooms->begin();
        std::advance(randRoom, randomRoomMove);

        int randomItemMove = Helper::randomZeroToN(tempItems.size() - 1);
        auto randItem = tempItems.begin();
        std::advance(randItem, randomItemMove);

        auto itemCountPair = itemDropCounts.find(randItem->second.getId());

        if(itemCountPair == itemDropCounts.end()){
            vector<Item> roomItems = randRoom->second.getItems();
            randRoom->second.addItem(randItem->second);
            itemDropCounts.insert(pair<int,int>(randItem->second.getId(), 1));
        }else{
                vector<Item> roomItems = randRoom->second.getItems();
                randRoom->second.addItem(randItem->second);
                itemCountPair->second++;

                if(itemCountPair->second == 3){
                    tempItems.erase(itemCountPair->first);
                    itemDropCounts.erase(itemCountPair->first);
                }
        }
    }
}

map<pair<int, int>, Exit> DataReader::loadExits() {
    map<pair<int, int>, Exit> exits;
    boost::filesystem::path exitPath = this->dataDir / "exits.txt";

    for(vector<string> exit : readLines(exitPath)){

        int from = stoi(exit[0]);
        int to = stoi(exit[1]);
        Directions::Direction direction = Directions::getFromString(exit[2]);
        bool isOpen = (exit[3] == "true");

        exits.insert(pair<pair<int, int>, Exit>(pair<int, int>(from, to), Exit(from, to, direction, isOpen)));
    }
    return exits;
}

map<int, Area> DataReader::loadAreas(map<int, Room> gameRooms){
    map<int, Area> areas;
    boost::filesystem::path areaPath = this->dataDir / "areas.txt";
    for(vector<string> area : readLines(areaPath)){
        int id = stoi(area[0]);
        string name = area[1];
        string desc = area[2];
        map<int, Room> rooms = Room::getRooms(gameRooms, id);
        areas.insert(pair<int, Area>(id, Area(id, name, desc, rooms)));
    }
    return areas;
}

map<string, User> DataReader::loadUsers(GameModel *pModel) {
    map<string, User> users;
    boost::filesystem::path userPath = this->dataDir / "players.txt";

    for(vector<string> values : readLines(userPath)){


        int id = stoi(values[0]);
        int itemCount = stoi(values[13]);
        int hp = stoi(values[20 + itemCount]);
        int mana = stoi(values[21 + itemCount] );
        int gold = stoi(values[14 + itemCount]);
        int intelligence = stoi(values[15 + itemCount]);
        int wisdom = stoi(values[16 + itemCount]);
        int strength = stoi(values[17 + itemCount]);
        int constitution = stoi(values[19 + itemCount]);
        int dexterity = stoi(values[18 + itemCount]);
        int location = stoi(values[3]);
        int moves = stoi(values[22 + itemCount]);



        map<int, Item> inventory;
        for(int i = 14; i < 14 + itemCount; i ++){
            inventory.insert(pair<int, Item>(stoi(values[i]), pModel->getItemById(stoi(values[i]))));
        }

        vector<Item> wearableItems = vector<Item>();

        for(int i = 4; i < 13; i++){
            if(values[i] != "NULL"){
                wearableItems.emplace_back(pModel->getItemById(stoi(values[i])));
            }else{
                wearableItems.emplace_back(Item());
            }
        }
        Slots slots = Slots(inventory, wearableItems[5], wearableItems[1], wearableItems[0], wearableItems[2],
                wearableItems[6], wearableItems[3] , wearableItems[4], wearableItems[8],
                wearableItems[7]);

        string name = values[1];

        //Get password as a size_t
        istringstream iss(values[2]);
        size_t pwd;
        iss >> pwd;

        PlayerCharacter playerCharacter = PlayerCharacter(id, hp, mana, gold, intelligence, wisdom, constitution,
                strength, dexterity, location, moves, slots);



        User user = User(id, name, pwd, playerCharacter);
        users.insert(pair<string, User>(name, user));
    }

    return users;
}

GameModel DataReader::loadAsciiDataSet() {
    GameModel model = GameModel();
    model.isAscii(true);
    model.setItems(loadItems());
    model.setExits(loadExits());
    model.setRooms(loadRooms(&model));
    model.setAreas(loadAreas(model.getRooms()));
    model.setUsers(loadUsers(&model));
    return model;
}

GameModel DataReader::loadBinaryDataSet(){
    ifstream in( dataDir / "gamedata", ios::in | ios::binary);
    boost::archive::binary_iarchive archive(in);
    GameModel model;
    if(in.good()){
        archive & model;
    }
    in.close();

    return model;
}

