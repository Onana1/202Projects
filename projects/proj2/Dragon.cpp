/*****************************************
 ** File:    Dragon.cpp
 ** Project: CMSC 202 Project 2, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    3/28/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Dragon.cpp program for Project 2.
 ** This file has the setter and getter mutators from the h file
 ** and builds a dragon using a dragon constructor with other other 
 ** types of data such as its size and type, this program also controls 
 ** whether a dragon wins or loses its battles and whether or not it
 ** grows.
 **
 ***********************************************/
#include <ctime>
#include "Dragon.h"

using namespace std;
//constructor that builds a dragon
Dragon::Dragon(string name, string type, bool isHatched, dragonSize curSize,
	       dragonSize maxSize, int rarity){
}
//GetName
//Getter method to get dragon's name
string Dragon::GetName(){
  return m_name;
}

//SetName
//Setter method that sets the name of the dragon name
void Dragon::SetName(string name){
  m_name = name;
}

//GetType
//Getter method to get the dragon's type
string Dragon::GetType(){
  return m_type;
}

//SetType
//Setter method to set the dragon's type
void Dragon::SetType(string Type){
  m_type = Type;
}

//GetIsHatched
//Getter method to get whether or not if the dragon is an egg
bool Dragon::GetIsHatched(){
  return m_isHatched;
}

//GetIsHatch
//Setter for whether or not the dragon hatched
void Dragon::HatchDragon(){
  if (m_isHatched != true)
    m_isHatched = 1;
  else
    m_isHatched = true;
}

//GetCurSize
//getter that gets the dragons current size
dragonSize Dragon::GetCurSize(){
  return m_curSize;
}

//SetCurSize
//setter that sets the dragons current size
void Dragon::SetCurSize(dragonSize curSize){
  m_curSize = curSize;
}

//GetMaxSize
//getter that gets the max size a dragon can be
dragonSize Dragon::GetMaxSize(){
  return m_maxSize;
}

//SetMaxSize
//setter method that sets the max size a dragon can be
void Dragon::SetMaxSize(dragonSize maxSize){
  m_maxSize = maxSize;
}

//GetRarity
//getter that gets the rarity of that dragon's egg
int Dragon::GetRarity(){
  return m_rarity;
}

//SetRarity
//setter that sets the rarity of that dragon's egg
void Dragon::SetRarity(int rarity){
  if (rarity >= 1 && rarity <= 10)
    m_rarity = rarity;
}

//AttemptGrow
//function that tries to promote a dragon to the next size if
//it is not at its max size
bool Dragon::AttemptGrow(){
  if (m_curSize < m_maxSize) 
    return true;
  else{
    return false;
  }
}

//AttackDragon
//method for whether a dragon lives  or survives a battle
bool Dragon::AttackDragon(Dragon& enemyDrag){
  int e = static_cast<int>(rand())% enemyDrag.GetMaxSize() + 2;
  //random number that is within the dragons max size for enemy dragons
  if (m_curSize < e)
    return false;
  else
    return true;
}  

//BreathAttack
//the string for a special breath attack that a dragon performs
string Dragon::BreathAttack(){
  string dragBreath = "Your " +  m_name + " breaths " + m_type; //used as 
  // the breath line for the specail attack
  return dragBreath;
}
