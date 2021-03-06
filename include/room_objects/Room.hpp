/* ..............................................
  @ file Room.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Item.hpp"
#include "Door.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include "Colors.hpp"
#include "Teleporter.hpp"
#include "Enemy.hpp"

using std::fstream;
using std::string;

/* ..............................................
  @brief 
  
.............................................. */
class Room
{
protected:
  static const int MAX_DOORS = 4;
  static const int MAX_TELEPORTERS = 96;
  static const int MAX_HEIGHT = 28;
  static const int MAX_WIDTH = 148;
  static const int MAX_ITEMS = MAX_WIDTH * MAX_HEIGHT;
  static const int MAX_ENEMIES = 20;
  char walls[MAX_HEIGHT][MAX_WIDTH];
  Item *items[MAX_ITEMS];
  Door *doors[MAX_DOORS];
  Enemy *enemies[MAX_ENEMIES];
  Teleporter *teleporters[MAX_TELEPORTERS];
  string type;
  string name;
  string description;
  int itemsArrayIndex;
  int tileColor;

public:
  // CONSTRUCTOR/DESTRUCTORS
  Room();
  Room(string roomFile);
  ~Room();

  // SETTERS
  void setWalls(string roomFile);
  void setItems();
  void setItem(Item *item, int itemIndex);
  void setType(string type);
  void setName(string name);
  void setDescription(string description);
  void setDoor(Door *door, int doorIndex);
  void setEnemy(Enemy *enemy, int enemyIndex);
  void setTeleporter(Teleporter *teleporter, int teleporterIndex);
  void setTileColor(int color);

  // GETTERS
  int getMaxHeight();
  int getMaxWidth();
  int getMaxItems();
  int getMaxDoors();
  int getMaxTeleporters();
  int getMaxEnemies();
  char getWall(int height, int width);
  Item **getItems();
  Item *getItem(int itemIndex);
  string getType();
  string getName();
  string getDescription();
  Door *getDoor(int doorIndex);
  Door **getDoors();
  Enemy **getEnemies();
  int getItemsSize();
  Teleporter *getTeleporter(int teleporterIndex);
  Teleporter **getTeleporters();
  int getTileColor();
};

#endif
