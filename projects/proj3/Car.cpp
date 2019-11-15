/*****************************************
 ** File:    Car.cpp
 ** Project: CMSC 202 Project 3, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/11/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Car.cpp program for Project 3.
 ** This file creates the car objects and sets their type
 ** of cargo and also sets the next node that the car is pointing
 ** to in the Train. It also returns the cargo type of a certain car 
 ** and destroys Car objects.
 **
 ***********************************************/
#include "Car.h"

using namespace std;

//Default constructor for a Car
Car::Car():m_cargo(OXIDIZER){
  setNext(NULL);
}

//Overloaded constructor for a Car of a certain type
Car::Car(CARGO_TYPE Part){
  setCargo(Part);
  setNext(NULL);
}

//deconstructor for car objects
Car::~Car(){
  delete m_next;
}

//Getter method for getting the cargo type
CARGO_TYPE Car::getCargo() const{
  return m_cargo;
}

//Setter method for setting the cargo to a type 
void Car::setCargo(CARGO_TYPE Part){
  m_cargo = Part;
}

//getter method for the next node in the train
Car* const Car::getNext() const{
  return m_next;
}

//setter method for the next node in the train
void Car::setNext(Car* cptr){
  m_next = cptr;
}

