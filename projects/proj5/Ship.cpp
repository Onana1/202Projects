/*****************************************
 ** File:    Ship.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    5/8/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Ship.cpp program for Project 5.
 ** This file creates the Ship object and has the setter
 ** and getter functions for the object and its sub classes.
 ** This file also overloads the << so the object can be
 ** printed.
 ***********************************************/
#include "Ship.h"

//default constructor for creating a ship object
Ship::Ship(string name, string type, int attack, int defense){
  m_name = name;
  m_type = type;
  m_attack = attack;
  m_defense = defense;
}

//getter method that returns the name of the ship
string Ship::getName(){
  return m_name;
}

//setter method that sets the name of the ship
void Ship::setName(string name){
  m_name = name;
}

//getter method that returns the type of the ship
string Ship::getType(){
  return m_type;
}

//setter method that sets the type of the ship 
void Ship::setType(string type){
  m_type = type;
}

//getter method that returns the attack of the ship
int Ship::getAttack(){
  return m_attack;
}

//setter method that sets the attack of the ship
void Ship::setAttack(int attack){
  m_attack = attack;
}

//getter method that returns the defense of the ship
int Ship::getDefense(){
  return m_defense;
}

//setter method that sets the defense of the ship
void Ship::setDefense(int defense){
  m_defense = defense;
}

//overloaded << operator that calls a ship objects toString
ostream& operator<<(ostream& os, Ship& b){
  return os << b.toString(os);
}
