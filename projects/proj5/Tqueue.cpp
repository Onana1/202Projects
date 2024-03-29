/*****************************************
 ** File:    Tqueue.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    5/8/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Tqueue.cpp program for Project 5.
 ** This file creates the Tqueue object and has the setter
 ** and getter functions for the object and its sub classes.
 ** This file also overloads operators so the object can be
 ** used with [] or =.
 ***********************************************/
#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue.
  //If queue is at capacity, doubles size and copies everything starting at 0
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  //If queue is less than half capacity, halves capacity
  //and copies everything starting at 0 
  void dequeue(); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Returns front item in queue (does not remove it)
  T& queueFront();    // Retrieve front (does not remove it)
  //Name: getBack()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_back
  int getBack();
  //Name: getFront()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_front
  int getFront();
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (not capacity but m_back - m_front)
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T>& operator=( const Tqueue<T> &y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
  //Name: displayTqueue (Test function)
  //Precondition: Existing Tqueue
  //Postcondition: Used to display all members in the Tqueue
  void displayTqueue();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
  int m_capacity; //Capacity of the queue
};

//**** Add class definition below ****

//default constructor that creates a Tqueue
template <class T>
Tqueue<T>::Tqueue(){
  m_capacity = 1;
  m_front = 0;
  m_back = 0;
  m_data = new T[m_capacity];
}

//copy constructor for a Tqueue object
template <class T>
Tqueue<T>::Tqueue( const Tqueue<T>& x ){
  m_capacity = x.m_capacity;
  m_front = x.m_front;
  m_back = x.m_back;
  m_data = new T[m_capacity];
  //copies the queue into another one
  for (int i = 0;  i<x.m_capacity; i++)
    {
      m_data[i] = x.m_data[i];
    }
}

//deconstructor for a Tqueue object
template <class T>
Tqueue<T>::~Tqueue(){
  if (m_data != NULL){
    delete [] m_data;
    m_data = NULL;
  }
}

//function that adds data to the Tqueue and makes it larger if the data goes 
//above capacity
template <class T>
void Tqueue<T>::enqueue(T data){
  if (m_back == m_capacity){
    //doubles the capacity of the queue
    m_capacity = m_capacity + m_capacity;

    T* m_data2 = new T[m_capacity];
    for (int i = 0; i < size(); i++){
      m_data2[i] = m_data[i];
    }
    delete [] m_data;
    m_data = m_data2;
  } 
  m_data[m_back] = data;
  m_back++;
}

//function that takes out the first element int the Tqueue and if the data in
//the queue is less that the capacity the capacity becomes halved
template <class T>
void Tqueue<T>::dequeue(){
  if (m_data != NULL){
    m_front++;
    if (size() <= m_capacity/2){
   
      //int counter = 0;
      int i;
      //halves the capacity of the queue
      m_capacity = m_capacity/2;
      T* m_data2 = new T[m_capacity];
      for (i = 0; i < m_capacity; i++){ 
	m_data2[i] = m_data[i+m_front];
      }
      delete [] m_data;
      m_data = m_data2;
      // while (m_data[counter] != 0){
      //counter++;
      //}
      m_back = i;
      m_front = 0;
    }
  }
}

//function that gets the first element in the Tqueue
template <class T>
T& Tqueue<T>::queueFront(){
  return m_data[m_front];
}

//function that returns the position of the back of the Tqueue
template <class T>
int Tqueue<T>::getBack(){
  return m_back;
}

//function that returns the position of the front of the Tqueue
template <class T>
int Tqueue<T>::getFront(){
  return m_front;
}

//function that checks whether or not the Tqueue is empty
template <class T>
int Tqueue<T>::isEmpty(){
  if (m_data[m_front] == 0){
    return 1;
  }
  else 
    return 0;
}

//function that returns the size of the Tqueue
template <class T>
int Tqueue<T>::size(){
  return m_back - m_front;
}

//overloaded assignment operator function
template <class T>
Tqueue<T>& Tqueue<T>::operator=( const Tqueue<T> &y){
  if ( this != &y ){
    m_capacity = y.m_capacity;
    m_front = y.m_front;
    m_back = y.m_back;
    m_data = new T[m_capacity];
    //allows the = operatir to be used to set a T pointer
    for (int i = 0; i<y.m_capacity; i++)
      {
	m_data[i] = y.m_data[i];
      }
  }
  //returns current object
  return *this;
}

//overloaded brackets operator function
template <class T>
T& Tqueue<T>::operator[] (int x){
  return m_data[x];
}

//test function that displays the Tqueue
template <class T>
void Tqueue<T>::displayTqueue(){
  for (int i = 0; i< size(); i++){
    cout << "array[" << i << "] = " << m_data[i+m_front] << endl;
  }
}
 
// This is the type of code you should test your Tqueue with
// Once you have coded all of the functions, compile just Tqueue and test it
/*
//int main () {
  cout << "newQ" << endl;
  Tqueue<int> newQ;
  newQ.displayTqueue();
  newQ.enqueue(10);
  cout << "empty: "<< newQ.isEmpty() << endl;
  newQ.dequeue();
  cout << "empty: "<< newQ.isEmpty() << endl;
  newQ.displayTqueue();
  newQ.enqueue(20);
  newQ.displayTqueue();
  newQ.enqueue(30);
  newQ.displayTqueue();

  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.enqueue(40);
  newQ.displayTqueue();
  
  newQ.enqueue(40);
  newQ.displayTqueue();
  newQ.enqueue(50);
  newQ.displayTqueue();
  cout << "newQ2 using assignment operator" << endl;
  Tqueue<int> newQ2;
  newQ2 = newQ;
  newQ2.displayTqueue();
  cout << "newQ3 using copy constructor" << endl;
  Tqueue<int> newQ3(newQ2);
  newQ3.displayTqueue();
  cout << endl << "newQ after two dequeue" << endl;
  newQ.dequeue();
  newQ.dequeue();
  newQ.displayTqueue();
  cout << endl;
  cout << "newQ4 using copy with deletes" << endl;
  Tqueue<int> newQ4(newQ);
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.displayTqueue();
  newQ3 = newQ4;
  newQ3.displayTqueue();

  Tqueue<int> newQ5;
  for(int i = 0;i<400;i++){
    newQ5.enqueue(i);
  }
  cout << "size()=" << newQ5.size() << endl;
  newQ5.displayTqueue();
  return 0;
}
*/
#endif
