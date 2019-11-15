/*****************************************
 ** File:    Train.cpp
 ** Project: CMSC 202 Project 3, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/11/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Train.cpp program for Project 3.
 ** This file creates the train and puts in Cars of various
 ** types into the train, it then decides whether the arrangement
 ** of cars is valid or invalid. There are function to put in and 
 ** remove cars from specific places in the train or remove all
 ** instances of a certain car from the train.
 **
 ***********************************************/
#include <cstdlib>
#include "Train.h"

using namespace std;

//Default constructor for the train
Train::Train():m_number(1234){
  m_head = NULL;
  m_len = 0;
}

//Overloaded constructor for the train that takes in the train's number
Train::Train(int Number){
  setNumber(Number);
  m_head = NULL;
  m_len = 0;
}

//Deconstructor that destroys train objects
Train::~Train(){
Car* curr, *next;
  
  curr = m_head;
  while(curr != NULL){
  next = curr->getNext();
  delete curr;
  curr = next;
  }
}

//Output stream that displays the train information
void Train::display(ostream& printRef) const{
  //if the the head of the train is empty it returns a message
  if(m_head == NULL)
    {
      printRef << "The train is empty" << endl;
    }
  else{
    Car* temp = m_head; //temporary head pointer
    string cargoOut;  //name of the cargo
    printRef << "Train " << m_number << ": ";
    while (temp != NULL){
      //switch statement used to get correct cargo name
      switch(temp->getCargo())
	{
	case 0:
	  cargoOut = "BIO";
	    break;
	case 1:
          cargoOut = "POI";
            break;
	case 2:
          cargoOut = "COM";
            break;
	case 3:
          cargoOut = "OXI";
            break;
	case 4:
          cargoOut = "RAD";
            break;
	case 5:
          cargoOut = "ENGINE";
            break;
	case 6:
          cargoOut = "CABOOSE";
            break;
	}
      //at the caboose get rid of the arrow
      if(cargoOut != "CABOOSE"){
	printRef << cargoOut << "->";
	temp = temp->getNext();
	}
      else if(cargoOut == "CABOOSE"){
	printRef << cargoOut;
        temp = temp->getNext();
      }
    }
  }
}
//function that looks at the cargo in the train and
//returns whether or not the train is valid 
bool Train::isValid() const{
  int listPos = 1;//start of the list
  //int dangerBio = 0; // determines if train is dangerous
  //int dangerCom = 0; // determines if train is dangerous
  //int dangerBioRad = 0; // determines if train is dangerous
  Car* curr;// current Car
  ///Car* iter;// iterator for list 
  curr = m_head;
  //if the head isn't a Locomotive train is already not valid
  if (m_head->getCargo() != LOCOMOTIVE){
    return false;
  }
  while(listPos < m_len){
  curr = curr->getNext();
  listPos++;
  }
  // if end of the train isn't caboose then the train is not valid
  if(curr->getCargo() != CABOOSE){
    return false;
  }
  //AREA FOR VALID/INVALID CASES BUT SEG FAULTS
  //5 Biological case
  //iter = m_head;
  //while (iter != NULL){
    //iter = iter->getNext();
    //if(iter->getCargo() == BIOLOGICAL){
      //dangerBio++;
      //}else{
      //dangerBio = 0;
      //}
    //if(dangerBio >= 5){
      //return false;
      //}
    // }
  //3 Combustible case
  //iter = m_head;
  //while (iter != NULL){
    //iter = iter->getNext();
    //if(iter->getCargo() == COMBUSTIBLE){
      //dangerCom++;
      //}else{
      //dangerCom = 0;
      //}
    //if(dangerCom >= 3){
      //return false;
      //}
    // }
  // Oxidizer/Combustible case and vice versa
  //iter = m_head;
  //while (iter != NULL){
    //iter = iter->getNext();
    //if(iter->getCargo() == OXIDIZER && iter->getNext()->getCargo() == 
       //COMBUSTIBLE){
      //return false;
      //}
    //if(iter->getCargo() == COMBUSTIBLE && iter->getNext()->getCargo() ==
       //OXIDIZER){
      //return false;
      //}
    //}
  return true;
}
  
//adds a car with a certain cargo type to the 
//train at the correct index in the train
int Train::addCar(const CARGO_TYPE& carRef, int carPos){ 
  //special case for if head is getting put in
  if (carPos == 0 && m_head == NULL){
    m_head = new Car(carRef);
    m_len++;
    return m_len;
    }else{
    //cases for other areas of the train
    Car* curr; //current Car
    int listPos = 1; //list position
    curr = m_head;
    while(listPos != carPos){
      curr = curr->getNext();
      listPos++;
    }
    curr->setNext(new Car(carRef));
    m_len++;
    return  m_len;
  }
}

//function that removes a car from 
//the train at a certain index
int Train::removeCar(int carRev){
  if (m_head == NULL){
    cout << "List is empty can't remove anything" << endl;
    return m_len;
  }
  Car* curr; //current Car;  
  int listPos = 1; //start of thee list
  //case for if removing the head of train and it is the only
  //thing there
  if(carRev == 0 && m_len > 1){
    m_head->setCargo(m_head->getNext()->getCargo());
    curr = m_head->getNext();
    m_head->setNext(m_head->getNext()->getNext());
    m_len--;
    return m_len;
  }else if(carRev == 0 && m_len == 1){
    m_head = NULL;
    m_len--;
    return m_len;
  }
  curr = m_head;
  while(listPos != carRev){
    curr = curr->getNext();
    listPos++;
  }
  curr->setNext(curr->getNext()->getNext());
  m_len--;
  return m_len;
}


//function that removes all instances of a 
//certain cargo type from the train
int Train::removeCar(CARGO_TYPE carType){
  //if the head is empty then nothing can be removed
  if (m_head == NULL){
    cout << "List is empty can't remove anything" << endl;
    return m_len;
  }
  Car* curr;
  Car* prev;
  curr = m_head;

  //if they want to remove the head make the next element the head
  if (carType == LOCOMOTIVE){
    m_head = m_head->getNext();
    m_len--;
    return m_len;
  }else{
    while(curr != NULL){
      if(curr->getCargo() == carType)
	{
	  prev->setNext(curr->getNext());
	  curr = prev;
	  m_len--;
	}
      prev = curr;
      //takes out the link for the item getting removed
      curr = curr->getNext();
    }
  }
  cout << m_len;
  return m_len;
}


//getter method for getting the current length of the train
int Train::getLength() const{
  return m_len;
}

//getter method for getting the train's name/number
int Train::getNumber() const{
  return m_number;
}

//setter method for setting the train number to the member variable
void Train::setNumber(int numTrain){
  m_number = numTrain;
}

//calls the display fuction to print the train and order of the cars
std::ostream &operator<<(std::ostream& streamRef, const Train& trainRef){
  trainRef.display(streamRef);
  return streamRef;
}

