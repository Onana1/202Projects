/*****************************************
 ** File:    proj1.cpp
 ** Project: CMSC 202 Project 1, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    7/22/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu 
 **
 ** This file contains the main program for Project 1.
 ** This program acquires a file from the user then reads the file
 ** and turns the contents into a 2D array of characters, where the 
 ** characters are used to create a 2D array of floats representing
 ** temperatures based on the corresponding value each charachter holds
 ** and the input from the user.
 **
 ***********************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


const int MIN_BASE_TEMP = -130; // num of the minimum base temperature
const int MAX_BASE_TEMP = 134;  // num of the maximum base temperature
const int MAX_ROW = 6;          // maximum index of rows in the arrays
const int MAX_LAND_COL = 6;     // maximum index of columns in char arrays
const int MAX_MODEL_COL = 5;    // maximum index of columns in model grid
const char LAND_RURAL = 'R';    // char representing Rural 
const char LAND_SUB_URBAN = 'S'; // char representing Suburban Residential 
const char LAND_COMM = 'C';     // char representing Commercial
const char LAND_URBAN = 'U';    // char representing UrbanResidential
const char LAND_DOWNTOWN = 'D'; // char representing Downtown
const char LAND_PARK = 'P';     // char representing Parks
const char LAND_FARM = 'F';     // char representing Rural Farmland

using namespace std;

// function prototypes
void getFile(string fileName, char arra[][6], int landRows);
void printGrid(char arr[][6], int numRows);
void printGrid(double arr[][6], int numRows);
void modelTemp(double currTemp, char arra[][6], double arr[][5], int numRows);

// main
// displays the main menu of the program, and calls the other functions based
// on what the user selected
int main() {
  
  double modelGrid[MAX_ROW][MAX_MODEL_COL] = {}; // array for model temp grid
  char landGrid[MAX_ROW][MAX_LAND_COL] = {};     // array for land chars
  string nameFile;   // name of the user-input file
  double numTemp;    // num of user-input base temp
  int numMain;       // num of user-input menu choice
  
  // main menu of the program
  do{
    cout << "What would you like to do?:" << endl;
    cout << "1. Load Land Cover File" << endl;
    cout << "2. Model Temperatures Based on Land Cover" << endl;
    cout << "3. Exit" << endl;
    cin >> numMain;

    // takes users number to the correct operation
    switch(numMain)
    {
    case 1:
      cout << "What is the name of the file to import?" << endl;
      cin >> nameFile;
      // call to getFile
      getFile(nameFile, landGrid, MAX_ROW);
      break;
    case 2:
      do {
      cout << "What is the base temperature?" << endl;
      cin >> numTemp;
      // input validation for the temperature
      } while (numTemp < MIN_BASE_TEMP || numTemp > MAX_BASE_TEMP);
      // call to get the model temperature grid
      modelTemp(numTemp, landGrid, modelGrid, MAX_ROW);
      break;
    case 3:
      cout << "Thank you for Using the Urban Heat Island Model" << endl;
    }
  } while ((numMain <= 2 && numMain >= 1) || (numMain != 3));
  
  return 0;
}

// getFile
// Given a file name, reads the file and creates a 2D array of characters
void getFile(string fileName, char arra[][6], int landRows){
  ifstream inputStream; // declaration of input stream
  char landLet;         // area where characters from the files are stored
  
// opens the file 
  inputStream.open(fileName.c_str());
  
  // checks if the file is open 
  if (inputStream.is_open()){
    cout << "File successfully loaded" << endl;
    
    // puts the characters from the file into a 2D array
    for (int i = 0; i < landRows; i++){
      for (int j = 0; j < 5; j++){
	inputStream >> landLet;
	arra[i][j] = landLet;
	  }
    }
    // prints out the array of characters 
    printGrid(arra, MAX_ROW);
  }
  // outputs that the file wasn't opened
  else {
    cout << "The file " << fileName << " was not opened" << endl;
  }
  // closes the file
  inputStream.close();
}

// printGrid
// takes in a 2D array of characters and iterates through to print its content
void printGrid(char arr[][6], int numRows){
  // loop where the char array is iterated
  for ( int i = 0; i < MAX_ROW; i++ ) {
    for ( int j = 0; j < 5; j++ )
      // spaces out and prints the characters 
      cout << setw(4) << arr[i][j]; 
    cout << endl;
  }
  return;
}

// printGrid
// takes in a 2D array of doubles and iterates through to print its contents
void printGrid(double arr[][5], int numRows){
  // forces every printout to go to one decimal point 
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  
  // iterates over the array
  for ( int i = 0; i < MAX_ROW; i++ ) {
    for ( int j = 0; j < 5; j++ )
      // sets distances and prints out values
      cout << setw(6) << arr[i][j];
    cout << endl;
  }
  return;
}

// modelGrid
// takes in a base temperature value and 2D array of doubles and characters
// uses the char array to fill the array of doubles with the modified values
// of the base temperature
void modelTemp(double currTemp, char arra[][6], double arr[][5], int numRows){
  // iterates over array 
  for (int i = 0; i < numRows; i++){
    for (int j = 0; j < 5; j++){
      // compares a char to a position in the char array then multiplies
      // the base temp by a modifier that corresponds to the specific char
      // and puts that value into the model grid array
      if (arra[i][j] == LAND_RURAL){
	  arr[i][j] = currTemp*1.01;
	}
      else if (arra[i][j] == LAND_SUB_URBAN){
	  arr[i][j] = currTemp*1.03;
	}
      else if (arra[i][j] == LAND_COMM){
          arr[i][j] = currTemp*1.05;
	}
      else if (arra[i][j] == LAND_URBAN){
          arr[i][j] = currTemp*1.04;
	}
      else if (arra[i][j] == LAND_DOWNTOWN){
          arr[i][j] = currTemp*1.09;
	}
      else if (arra[i][j] == LAND_PARK){
          arr[i][j] = currTemp*1.02;
	}
      else if (arra[i][j] == LAND_FARM){
          arr[i][j] = currTemp*1.00;
	}
    }
  }
  // prints out the model grid array 
  printGrid(arr, MAX_ROW);

  return;
}
