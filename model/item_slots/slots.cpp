/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#include "headers/slots.h"

#include <utility>
#include <iostream>
#include <boost/algorithm/string.hpp>


Slots::Slots(map<int, Item> inventory, Item head, Item arms, Item wrists, Item hands, Item torso, Item legs, Item feet,
             Item weapon, Item shield)
             : inventory(std::move(inventory)),
               head(std::move(head)),
               arms(std::move(arms)),
               hands(std::move(hands)),
               torso(std::move(torso)),
               wrists(std::move(wrists)),
               legs(std::move(legs)),
               feet(std::move(feet)),
               weapon(std::move(weapon)),
               shield(std::move(shield)) {

}

Slots::Slots(){}

void Slots::wear(Item item, int positionKey) {
    string wearPos = Item::wearPositionToString(item.getWearPosition());
    unordered_map<string, Item> slots = getSlots();
    drop(positionKey);
    addItem(item);
}

void Slots::remove(Item item) {
    unordered_map<string, Item> slots = getSlots();
    for (auto e : slots){
        if (e.second.getId() == item.getId()){
            deleteItem(item.getWearPosition());
            inventory.insert(pair<int, Item>(inventory.size() + 1, item));
        }
    }
}

void Slots::store(Item item) {
    if(inventory.size() < 10){
        inventory.insert(pair<int, Item>(item.getId(), item));
    }
}

void Slots::drop(int positionKey) {
    inventory.erase(positionKey);
    if (!inventory.empty()) {
        for (const auto &e: inventory) {
            if (e.first > positionKey) {
                inventory.extract(e.first).key() = e.first - 1;
            }
        }
    }
}
void Slots::addItem(Item item){
    switch (item.getWearPosition()){
        case Item::HEAD:
            head = item;
            break;
        case Item::ARMS:
            arms = item;
            break;
        case Item::HANDS:
            hands = item;
            break;
        case Item::TORSO:
            torso = item;
            break;
        case Item::WRISTS:
            wrists = item;
            break;
        case Item::LEGS:
            legs = item;
            break;
        case Item::FEET:
            feet = item;
            break;
        case Item::WEAPON:
            weapon = item;
            break;
        case Item::SHIELD:
            shield = item;
            break;
    }
}
void Slots::deleteItem(Item::WearPosition pos){
    switch (pos){
        case Item::HEAD:
             head = Item();
             break;
        case Item::ARMS:
             arms = Item();
            break;
        case Item::HANDS:
             hands = Item();
            break;
        case Item::TORSO:
             torso = Item();
            break;
        case Item::WRISTS:
             wrists = Item();
            break;
        case Item::LEGS:
             legs = Item();
            break;
        case Item::FEET:
             feet = Item();
            break;
        case Item::WEAPON:
             weapon = Item();
            break;
        case Item::SHIELD:
             shield = Item();
            break;
    }
}
string Slots::getEquipmentIdToString(Item::WearPosition pos) {
    int result;
    switch(pos){
        case Item::HEAD:
            result = head.getId();
            break;
        case Item::TORSO:
            result = torso.getId();
            break;
        case Item::ARMS:
            result = arms.getId();
            break;
        case Item::WRISTS:
            result = wrists.getId();
            break;
        case Item::HANDS:
            result = hands.getId();
            break;
        case Item::SHIELD:
            result = shield.getId();
            break;
        case Item::WEAPON:
            result = weapon.getId();
            break;
        case Item::LEGS:
            result = legs.getId();
            break;
        case Item::FEET:
            result = feet.getId();
            break;
    }
    if(result == -1){
        return "NULL";
    }
    return to_string(result);
}

int Slots::getInventoryCount() {
    return inventory.size();
}

map<int, Item> Slots::getInventory() {
    return inventory;
}

void Slots::setInventory(map<int, Item> inven){
    inventory = std::move(inven);
}
unordered_map<string, Item> Slots::getSlots(){
    unordered_map<string, Item> slots;
    slots.insert(pair<string, Item>("Shield", shield));
    slots.insert(pair<string, Item>("Weapon", weapon));
    slots.insert(pair<string, Item>("Feet", feet));
    slots.insert(pair<string, Item>("Legs", legs));
    slots.insert(pair<string, Item>("Torso", torso));
    slots.insert(pair<string, Item>("Hands", hands));
    slots.insert(pair<string, Item>("Wrists", wrists));
    slots.insert(pair<string, Item>("Arms", arms));
    slots.insert(pair<string, Item>("Head", head));
    return slots;
}

void Slots::toString(){
    cout << "Player has in Inventory: " << endl;
    if (!inventory.empty()) {
        for (auto e: inventory) {
            cout << e.second.getName() << ": " << e.second.getDescription() << ", Value:" << e.second.getValue() << endl;
        }
    }else {
        cout << "Empty" << endl;
    }
    cout << endl;
    cout << "Player has equipped: " << endl;
    unordered_map<string, Item> slots = getSlots();
    for (auto e: slots){
        cout << e.first << ": ";
        if (!e.second.getName().empty()) {
            cout << e.second.getName() << ": " << e.second.getDescription() << ", Value:" << e.second.getValue() <<endl;
        }else {
            cout << "Empty" << endl;
        }
    }
}


