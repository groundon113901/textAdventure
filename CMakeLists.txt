cmake_minimum_required(VERSION 2.8)  # CMake version check
project(text_adventure)               # Create project "text adventure"
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
set(CMAKE_CXX_FLAGS "-Wall -pedantic -std=c++17")

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES text_adventure.cpp
        utility/helpers.cpp
        core/game_object.cpp
        core/game_engine.cpp
        controller/game_controller.cpp
        controller/input_reader.cpp
        core/data_writer.cpp
        core/data_reader.cpp
        model/user/user.cpp
        model/characters/character.cpp
        model/characters/player_character.cpp
        model/characters/enemy.cpp
        model/locations/area.cpp
        model/locations/room.cpp
        model/items/item.cpp
        model/item_slots/slots.cpp
        model/items/armour.cpp
        model/items/weapon.cpp
        model/items/shield.cpp
        model/combat/attack.cpp
        model/combat/spell.cpp
        model/locations/exit.cpp
        model/game/game_model.cpp
        view/game_view.cpp
        )

find_package(Boost COMPONENTS filesystem system program_options serialization REQUIRED)
find_package (Threads REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(LIBS_TO_LINK
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
)



#add compile flags
add_definitions(${CXX_COMPILE_FLAGS})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(text_adventure ${SOURCE_FILES})
target_link_libraries(text_adventure ${LIBS_TO_LINK})