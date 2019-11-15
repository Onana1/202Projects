/*****************************************
 ** File:   main.cpp
 ** Project: CMSC 202 Project 3, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/11/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the main.cpp program for Project 3.
 ** This file is the driver program that a vector of trains by
 ** usinging in command line arguments to read in a file of cars 
 ** then it puts the cars into the trains or removes cars from trains
 ** and displays the train and whether or not it is a safe train or not.
 **
 ***********************************************/
#include <vector>
#include "Car.h"
#include "Train.h"
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
  string nameTrain; //name of the the train from file
  string addOrRemove; // whether car is getting added or removed from file
  string typeCarg; //type of cargo from the file
  CARGO_TYPE vecCarType; //cargo enum variable holder
  vector<Train*> myTrains; //vector of multiple trains

  // take file from command line arguments
  for (int i = 1; i <= argc; i++)
  {
    string fn = argv[i];
    ifstream f;
    f.open(fn.c_str());
    // keeps reading in until the file is empty
    while (getline(f, nameTrain, ',')){
      // change the string name into an int
      int numTrain = atoi(nameTrain.c_str());
      // puts train objects into vectors 
      if(myTrains.empty()){
	Train* newTrain = new Train(numTrain);
	myTrains.push_back(newTrain);
      }else{
	for(unsigned int i = 0; i < myTrains.size(); i++){
	  if(myTrains[i]->getNumber() != numTrain){
	      Train* newTrain = new Train(numTrain);
	      myTrains.push_back(newTrain);
	    }
	}
      }
      getline(f, addOrRemove, ',');
      // does the adding of nodes
      if(addOrRemove == "add"){
	getline(f, typeCarg);
	if (typeCarg == "LOCOMOTIVE")
	  vecCarType = LOCOMOTIVE;
	if (typeCarg == "BIOLOGICAL")
	  vecCarType = BIOLOGICAL;
	if (typeCarg == "COMBUSTIBLE")
	  vecCarType = COMBUSTIBLE;
	if (typeCarg == "POISONOUS")
	  vecCarType = POISONOUS;
	if (typeCarg == "RADIOACTIVE")
	  vecCarType = RADIOACTIVE;
	if (typeCarg == "OXIDIZER")
	  vecCarType = OXIDIZER;
	if (typeCarg == "CABOOSE")
	  vecCarType = CABOOSE;
	// actually adds the cars into the train
	for(unsigned int i = 0; i < myTrains.size(); i++){
	  if (myTrains[i]->getNumber() == numTrain){
	    myTrains[i]->addCar(vecCarType, myTrains[i]->getLength());
	  }
	}
      }
      // does the removing of nodes
      if(addOrRemove == "remove"){
	getline(f, typeCarg);
        if (typeCarg == "LOCOMOTIVE")
          vecCarType = LOCOMOTIVE;
        if (typeCarg == "BIOLOGICAL")
          vecCarType = BIOLOGICAL;
        if (typeCarg == "COMBUSTIBLE")
          vecCarType = COMBUSTIBLE;
        if (typeCarg == "POISONOUS")
          vecCarType = POISONOUS;
        if (typeCarg == "RADIOACTIVE")
          vecCarType = RADIOACTIVE;
        if (typeCarg == "OXIDIZER")
          vecCarType = OXIDIZER;
        if (typeCarg == "CABOOSE")
          vecCarType = CABOOSE;
	// looks for cars and removes them
        for(unsigned int i = 0; i < myTrains.size(); i++){
          if (myTrains[i]->getNumber() == numTrain){
            myTrains[i]->removeCar(vecCarType);
	  }
	}
      }
    }
    // prints out the trains 
    for(unsigned int i = 0; i < myTrains.size(); i++){
      cout << *myTrains[i];
      }
    // prints out whether or not the train is valid
    for(unsigned int i = 0; i < myTrains.size(); i++){
      if(myTrains[i]->isValid() == false){
	cout << " (invalid)";
      }else{
	cout << " (valid)";
      }
    }
    // deletes the trains in the vector
    for(unsigned int i = 0; i < myTrains.size(); i++){
      delete myTrains[i];
    }
    // closes the file
    f.close();
  }
  return 0;
}

