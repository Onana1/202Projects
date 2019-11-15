/*****************************************
 ** File:    Mail.cpp
 ** Project: CMSC 202 Project 4, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/24/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Mail.cpp program for Project 4.
 ** This file creates the Mail object and has the setter 
 ** and getter functions for the object and its sub classes.
 ** This file also overloads the << so the object can be
 ** printed.
 ***********************************************/
#include "Mail.h"

using namespace std;

//default constructor for the mail
Mail::Mail(){
}

//overloaded constructor for the mail
Mail::Mail(int carNum, string mailSend, string mailRecip, 
	   float mailSize, float mailBaseCost){
  m_carrier = carNum;
  m_sender = mailSend;
  m_recipient = mailRecip;
  m_size = mailSize;
  m_baseCost = mailBaseCost;
}

//getter method that gets which carrier the mail belongs to
int Mail::getCarrier(){
  return m_carrier;
}

//getter method that returns the sender of the mail
string Mail::getSender(){
  return m_sender;
}

//getter method that returns the recipient of the mail
string Mail::getRecipient(){
  return m_recipient;
}

//getter method that returns the size of the mail(lbs or sq in.)
float Mail::getSize(){
  return m_size;
}

//getter method that returns the base cost of that mail type
float Mail::getBaseCost(){
  return m_baseCost;
}

//function that overloads the << operator so mail objects can be printed
ostream& operator<<(ostream& outStream, Mail& mailRef){
  return outStream << mailRef.toString();
}
