/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_GAMEVIEW_H
#define TEXT_ADVENTURE_GAMEVIEW_H

#include <iostream>
#include <vector>
#include <memory>
#include "../../model/enums/actions.h"
#include "../../controller/headers/input_reader.h"
#include "../../model/locations/headers/room.h"
#include "../../model/locations/headers/area.h"
#include "../../model/game/headers/game_model.h"


class GameView {

public:
    GameView();
    void welcomePlayer();
    vector<string> loginScreen();
    void loginFailed();

    /* Room */
    void onRoomChange(Room room);
    void onLook(Room room);

    void onExits(GameModel model);

    void onAreas(map<int, Area> area);

    void roomClosed();
    void inValidOption();
    void inValidOption(string msg);

    void roomOpened();
    void gameSaved();
    void onInventory(Slots playerSlots);
    void itemNotFound();
    void itemRemoved(Item itemRemoved);
    void itemDropped(Item itemRemoved);
    void itemEquiped(Item itemEquiped);
    void slotFull();

    void itemPickedUp(Item item);
};


#endif //TEXT_ADVENTURE_GAMEVIEW_H
