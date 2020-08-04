/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef SIMPLE_EXAMPLE_SLOTS_H
#define SIMPLE_EXAMPLE_SLOTS_H


#include <map>
#include <unordered_map>
#include <boost/serialization/access.hpp>
#include "../../items/headers/item.h"

class Slots {

private:
    std::map<int, Item> inventory;
    Item head;
    Item arms;
    Item hands;
    Item torso;
    Item wrists;
    Item legs;
    Item feet;
    Item weapon;
    Item shield;
public:
    Slots(map<int, Item> inventory, Item head, Item arms, Item wrists, Item hands, Item torso, Item legs, Item feet,
          Item weapon, Item shield);
    Slots();
    void wear(Item item, int positionKey);
    void remove(Item item);
    void store(Item item);
    void drop(int positionKey);
    string getEquipmentIdToString(Item::WearPosition);
    map<int, Item> getInventory();
    int getInventoryCount();
    unordered_map<string, Item> getSlots();
    void toString();

    void deleteItem(Item::WearPosition pos);

    void setInventory(map<int, Item> inven);

    void addItem(Item item);

    friend class boost::serialization::access;
    template<typename Archive>
    void serialize(Archive& archive, const unsigned version){
        archive & inventory & head & arms & torso & wrists & legs & feet & weapon & shield;
    }
    
};


#endif //SIMPLE_EXAMPLE_SLOTS_H
