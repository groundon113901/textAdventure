//
// Created by james on 19/05/2020.
/*
 *  Text Adventure
 *  By James Cranston (s3609326) & Justin Gerussi (s3644927)
 *
 */
#ifndef TEXT_ADVENTURE_DATA_WRITER_H
#define TEXT_ADVENTURE_DATA_WRITER_H


#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include "../../model/game/headers/game_model.h"

using byte = char;

class DataWriter {
private:
    boost::filesystem::path savePath;

public:
    DataWriter(boost::filesystem::path);
    void writeAscii(GameModel&);
    void asciiWritePlayers(map<string, User>);
    void asciiWriteAreas(map<int, Area>);
    void asciiWriteRooms(map<int, Room>);
    void asciiWriteExits(map<pair<int, int>, Exit>);
    void asciiWriteItems(map<int, Item>);

    void writeBinary(GameModel&);


};


#endif //TEXT_ADVENTURE_DATA_WRITER_H