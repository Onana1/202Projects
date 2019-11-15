/*****************************************
 ** File:    Letter.cpp
 ** Project: CMSC 202 Project 4, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/24/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Letter.cpp program for Project 4.
 ** This file creates the Letter object and inherits from
 ** the Mail class. This file also returns the object as a
 ** string.
 ***********************************************/
#include "Letter.h"
#include "Mail.h"

using namespace std;

//default constructor for a letter
Letter::Letter():Mail(0, "John Wick", "Joe Barnes", 15.5, .05){
}

//overloaded constructor for a letter
Letter::Letter(int lettCarr, string lettSend, string lettRecip, float lettSize
	       , float lettBaseCost):Mail(lettCarr, lettSend, lettRecip,
					  lettSize, lettBaseCost){
}

//deconstructor for a letter object
Letter::~Letter(){
} 

//to string method that returns a string representation of a letter
string Letter::toString(){
  stringstream mailStr; //string stream object
  mailStr << "LETTER" << endl;
  mailStr << "To: " << m_recipient << endl;
  mailStr << "From: " << m_sender << endl;
  mailStr << "Size: " << m_size << " square inches";
  return mailStr.str();
}
