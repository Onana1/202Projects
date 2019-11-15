/*****************************************
 ** File:    Package.cpp
 ** Project: CMSC 202 Project 4, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/24/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Package.cpp program for Project 4.
 ** This file creates the Package object and inherits from  
 ** the Mail class. This file also returns the object as a
 ** string.
 ***********************************************/
#include "Package.h"
#include "Mail.h"


using namespace std;
//default constructor for a package object
Package::Package():Mail(0, "John Wick", "Joe Barnes", 15.5, .05){
}

//overloaded constructor for a package object
Package::Package(int packCarr, string packSend, string packRecip, 
		 float packSize, float packBaseCost):Mail(packCarr, packSend,
							  packRecip, packSize,
							  packBaseCost){
}

//deconstructor for a package object
Package::~Package(){
  //no allocated memery for mail
}

//to string method that returns a string representation of a package
string Package::toString(){
  stringstream mailStr; //string string object
  mailStr << "PACKAGE" << endl;
  mailStr << "To: " << m_recipient << endl;
  mailStr << "From: " << m_sender << endl;
  mailStr << "Weight: " << m_size << " lbs";
  return mailStr.str();
}
