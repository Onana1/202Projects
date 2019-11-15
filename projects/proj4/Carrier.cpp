/*****************************************
 ** File:    Carrier.cpp
 ** Project: CMSC 202 Project 4, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/24/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Carrier.cpp program for Project 4.
 ** This file creates the Carrier objects and has the setter
 ** and getter functions for the object and its sub classes.
 ** This file also overloads the << so the object can be
 ** printed.
 ***********************************************/
#include "Carrier.h"

using namespace std;

//default constructor for creating a Carrier
Carrier::Carrier(){
  m_max_capacity = 5;
  m_delivery_rate = .7;
}

//method that inserts a mail pointer into the mail storage vector
int Carrier::insert(Mail* insMail){
  int u = m_max_capacity; //max capacity into a single variable
  if (m_storage.size() <= (unsigned)u){
    m_storage.push_back(insMail);
    return 1;
  }
  else{
    //if the storage sizez is bigger than max capacity then don't insert
    cout << "This Carrier is full" << endl;
    return 0;
  }
}

//setter method for setting the max capacity of the carrier
void Carrier::setMaxCapacity(int carCap){
  m_max_capacity = carCap;
}
//setter method for setting the delivery rate of the carrier
void Carrier::setRate(float carRate){
  m_delivery_rate = carRate;
}

vector<Mail*> Carrier::getVector(){
  return m_storage;
}

//function that overloads << operator so it is usable on a carrier object
ostream &operator<<(ostream& outStream, const Carrier& carRef){
  return carRef.print(outStream);
}
