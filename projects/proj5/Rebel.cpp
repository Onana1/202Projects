/*****************************************
 ** File:    Rebel.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    5/8/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Rebel.cpp program for Project 5.
 ** This file creates the Rebel object and has the setter
 ** and getter functions for the object and its sub classes.
 ** This file also overloads the << so the object can be
 ** printed.
 ***********************************************/
#include "Rebel.h"

//function that attacks the enemy ship and determines whether the ship gets
//damaged or destroyed
bool Rebel::attack(Ship* enemy){
  if (getAttack() > enemy->getDefense()){
    //returns that the ship was destroyed
    //cout << "The " << enemy->getName() << " was destroyed." << endl;
    return 1;
  }else{
    //returns that the sihip was damaged
    //cout << "The " << enemy->getName() << " was damaged." << endl; 
    return 0;
  }
}

//to string function that prints out the imperial object
ostream& Rebel::toString(ostream& os){
  os << "Rebel " << getName() << endl;
  return os;
}

