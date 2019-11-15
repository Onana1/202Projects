/*****************************************
 ** File:    driver.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    5/8/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the driver.cpp program for Project 5.
 ** This file creates the StarWars object and has the setter
 ** and getter functions for the object and its sub classes.
 ** This file also overloads the << so the object can be
 ** printed.
 ***********************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Tqueue.cpp"
#include "Ship.h"
#include "StarWars.h"
#include "Imperial.h"
#include "Rebel.h"
using namespace std;

int main (int argc, char* argv[]) {
  if(argc != 3){
    cout << "Program requires two file: proj5_imperial.txt and proj5_rebel.txt" << endl;
    cout << "Try: ./proj5 proj5_imperial.txt proj5_rebel.txt" << endl;
    return -1;
  }

  StarWars newStarWars;
  char* files[] = {argv[1],argv[2]};
  newStarWars.Start(files);
  return 0;
}
