/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/data_writer.h"

DataWriter::DataWriter(boost::filesystem::path dataDir) {
    this->savePath = dataDir;
    if(!boost::filesystem::exists(savePath)){
        boost::filesystem::create_directory(savePath);
    }
}

void DataWriter::writeAscii(GameModel &pModel) {
    asciiWritePlayers(pModel.getUsers());
    asciiWriteAreas(pModel.getAreas());
    asciiWriteRooms(pModel.getRooms());
    asciiWriteExits(pModel.getExits());
    asciiWriteItems(pModel.getItems());
}

void DataWriter::asciiWritePlayers(map<string, User> users) {
    ofstream file(savePath / "players.txt");

    for(auto & userPair : users){
        User user = userPair.second;

        file << user.getId() << "\t";
        file << user.getUsername() << "\t";
        file << user.getPasswordHash() << "\t";
        PlayerCharacter character = *user.getCharacter();
        file << character.getLocationNo() << "\t";

        Slots slots = character.getItemSlots();
        file << slots.getEquipmentIdToString(Item::WRISTS) << "\t";
        file << slots.getEquipmentIdToString(Item::ARMS) << "\t";
        file << slots.getEquipmentIdToString(Item::HANDS) << "\t";
        file << slots.getEquipmentIdToString(Item::LEGS) << "\t";
        file << slots.getEquipmentIdToString(Item::FEET) << "\t";
        file << slots.getEquipmentIdToString(Item::HEAD) << "\t";
        file << slots.getEquipmentIdToString(Item::TORSO) << "\t";
        file << slots.getEquipmentIdToString(Item::SHIELD) << "\t";
        file << slots.getEquipmentIdToString(Item::WEAPON) << "\t";

        int invCount = slots.getInventoryCount();
        file << invCount << "\t";

        map<int, Item> inventory = slots.getInventory();
        for(auto & item : inventory){
            file << item.second.getId() << "\t";
        }

        file << character.getGold() << "\t";
        file << character.getIntelligence() << "\t";
        file << character.getWisdom() << "\t";
        file << character.getStrength() << "\t";
        file << character.getDexterity() << "\t";
        file << character.getConstitution() << "\t";
        file << character.getMaxHp() << "\t";
        file << character.getMaxMana() << "\t";
        file << character.getMoves() << endl;

    }

    file.close();

}

void DataWriter::writeBinary(GameModel& pModel){
    pModel.mergeCurrentUser();
    ofstream out(savePath / "gamedata", ios::out | ios::binary);
    boost::archive::binary_oarchive archive(out);
    if(out.good()) {
        archive & pModel;
    }
    out.close();
}


void DataWriter::asciiWriteAreas(map<int, Area> areas) {
    ofstream file(savePath / "areas.txt");

    for(auto & areaPair : areas){
        Area area = areaPair.second;

        file << area.getId() << "\t";
        file << area.getName() << "\t";
        file << area.getDescription() << endl;
    }


    file.close();
}

void DataWriter::asciiWriteRooms(map<int, Room> rooms) {
    ofstream file(savePath / "rooms.txt");

    for(auto & roomPair : rooms){
        Room room = roomPair.second;

        file << room.getId() << "\t";
        file << room.getAreaRoomId() << "\t";
        file << room.getAreaId() << "\t";
        file << room.getName() << "\t";
        file << room.getDescription() << "\t";
        file << room.getItemCount() << "\t";
        for(auto item : room.getItems()){
            file << item.getId() << "\t";
        }

        file << endl;
    }

    file.close();
}

void DataWriter::asciiWriteExits(map<pair<int, int>, Exit> exits) {
    ofstream file(savePath / "exits.txt");
    vector<string> boolStr {"false", "true"};
    for(auto & exitPair : exits){
        Exit exit = exitPair.second;

        string dirString = exit.getDirectionToString();
        transform(dirString.begin(), dirString.end(), dirString.begin(), ::toupper);

        file << exit.getFromRoom() << "\t";
        file << exit.getToRoom() << "\t";
        file << dirString << "\t";
        file << boolStr[exit.getRoomIsOpen()] << endl;
    }

    file.close();
}

void DataWriter::asciiWriteItems(map<int, Item> items) {
    ofstream file(savePath / "items.txt");

    for(auto & itemPair : items){
        Item item = itemPair.second;

        file << item.getId() << "\t";
        file << Item::wearPositionToString(item.getWearPosition()) << "\t";
        file << item.getName() << "\t";
        file << item.getDescription() << "\t";
        file << item.getValue() << endl;
    }

    file.close();
}