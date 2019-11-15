/*****************************************
 ** File:    FedEx.cpp
 ** Project: CMSC 202 Project 4, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    4/24/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the FedEx.cpp program for Project 4.
 ** This file creates the FedEx object and delivers the mail.
 ** It also calculates how much money FedEx made from deliveries and
 ** sends the print out of a ups object to an output stream.
 ***********************************************/
#include "FedEx.h"
#include "Carrier.h"

using namespace std;

//default constructor for a FedEx object
FedEx::FedEx():Carrier(){
  m_max_capacity = 5;
  m_delivery_rate = .7;
}

//deconstructor for a FedEx object
FedEx::~FedEx(){
  //goes through vector and deletes mail pointer
  for(unsigned int i = 0; i<m_storage.size(); i++){
    delete m_storage[i];
    //sets pointer to null
    m_storage[i] = NULL;
  }
}

//delivery function that goes through mail vector and delivers the mail
int FedEx::deliver(){
  float fedCost = 0; //total money made from fedex deliveries
  if (m_storage.empty()){
    return 0;
  }else{
    //goes through the storage and delivers the mail
    for (unsigned int i = 0; i < m_storage.size(); i++)
      {
        cout << "Delivered:" << endl;
        cout << "--------------------" << endl;
        cout << *m_storage[i] << endl;
        cout << "--------------------" << endl <<endl;
	//does calculation for the cost of each mail
	fedCost = (fedCost + (m_storage[i]->getBaseCost()*
			      m_storage[i]->getSize()*m_delivery_rate));
      }
    //caps the decimal place at 2
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Deliveries completed. FedEx total earned: $" << fedCost << endl;
    return 1;
  }
}

//print function that streams out contents of the Fedex truck
ostream& FedEx::print(ostream& outStream) const{
  outStream << "FedEx Truck Contents:" << endl <<
    "--------------------" << endl;
  //goes through the storage and sends the mail to a stream
  for (unsigned int i = 0; i < m_storage.size(); i++)
    {
      outStream << *m_storage[i] << endl <<
	"--------------------" << endl;
    } 
  return outStream;
}
