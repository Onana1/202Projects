/*****************************************
 ** File:    StarWars.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    5/8/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the StarWars.cpp program for Project 5.
 ** This file creates the StarWars object and has the setter
 ** and getter functions for the object and its sub classes.
 ** This file also overloads the << so the object can be
 ** printed.
 ***********************************************/
#include "StarWars.h"

//default constructor for a StarWars object, also seeds random
StarWars::StarWars(){
  srand(time(NULL));
}

//deconstructor for StarWars object
StarWars::~StarWars(){
}

//function that loads the ships from a file and puts them into thier
//corresponding vectors
bool StarWars::loadShips(char* files[]){
  string impName;
  string impType;
  string impAttack;
  string impDefense;
  
  string fi = files[0]; //string that is file name
  ifstream f; //file stream object
  f.open(fi.c_str());
  if(f.is_open() == false){
    cout << "The file did not open" << endl;
    return 0;
  }

  while(getline(f, impName, ',')){

    //gets the sender, recipient, and weight from the file
    getline(f, impType, ',');

    getline(f, impAttack, ',');
    int numImpAttack = atoi(impAttack.c_str());
    getline(f, impDefense);
    int numImpDefense = atoi(impDefense.c_str());
    
    //pushes the imperial object into the vector
    m_imperialShips.push_back(new Imperial(impName, impType, numImpAttack,
					   numImpDefense));
  }
  f.close();
    
  string rebName;
  string rebType;
  string rebAttack;
  string rebDefense;

  string fr = files[1]; //string that is file name
  ifstream fs; //file stream object
  fs.open(fr.c_str());
  if(fs.is_open() == false){
    cout << "The file did not open" << endl;
    return 0;
  }

  while(getline(fs, rebName, ',')){

    //gets the sender, recipient, and weight from the file
    getline(fs, rebType, ',');

    getline(fs, rebAttack, ',');
    int numRebAttack = atoi(rebAttack.c_str());
      getline(fs, rebDefense);
    int numRebDefense = atoi(rebDefense.c_str());

    //pushes the rebel object into the vector
    m_rebelShips.push_back(new Rebel(rebName, rebType, numRebAttack,
				     numRebDefense));
  }
  fs.close();
  return 1;
}

//start function that calls all of the other function and runs the game
void StarWars::Start(char* files[]){
  loadShips(files);
  int numTeams;
  //input validation for ships on team
  do {
    cout << "How many ships would you like on a team?" << endl;
    cin >> numTeams;
  }while (numTeams < 1);
  
  createTeams(numTeams);
  battle();
}

//function that takes in how many ships the user wants on a team and 
//fills a Tqueue randomly up to that number for both teams 
void StarWars::createTeams(int numShips){
  int numRebIn = rand() % m_rebelShips.size();
  int numImpIn = rand() % m_imperialShips.size();
  
  //gets random ships from the vector
  while (m_myShips.size() < numShips){
    m_myShips.enqueue(m_rebelShips[numRebIn]);
  }
  
  while (m_enemyShips.size() < numShips){
    m_enemyShips.enqueue(m_imperialShips[numImpIn]);
  }
}

//function that manages the battling between the rebels and imperials
void StarWars::battle(){
  cout << "The battle begins..." << endl;
  int startFirst = rand() % 2;
  if (startFirst == 0){
    while (m_myShips.isEmpty() == 0 && m_enemyShips.isEmpty() == 0){
      //rebel ships attack the imperials first
      cout << "The Rebel " << m_myShips.queueFront()->getName() 
	   << " attacks the Imperial " <<
	m_enemyShips.queueFront()->getName() << endl;
      
      if ((m_myShips.queueFront())->attack(m_enemyShips.queueFront()) == 1){
	cout << "The " << m_enemyShips.queueFront()->getName() 
	     << " was destroyed." << endl;
	m_enemyShips.dequeue();
      
      }else if((m_myShips.queueFront())->attack(m_enemyShips.queueFront()) 
	       == 0){
	cout << "The " << m_enemyShips.queueFront()->getName() 
	     << " was damaged." << endl;
	//changes the defense of the ship
	m_enemyShips.queueFront()->setDefense((m_enemyShips.queueFront()->
					       getDefense()) - (m_myShips.
								queueFront()->
								getAttack()));
	
	// then imperials attack rebels
	cout << "The Imperial " << m_enemyShips.queueFront()->getName() << 
	  " attacks the Rebel " <<
	  m_myShips.queueFront()->getName() << endl;

	if ((m_enemyShips.queueFront())->attack(m_myShips.queueFront()) == 1){
	  cout << "The " << m_myShips.queueFront()->getName()
	       << " was destroyed." << endl;
	  m_myShips.dequeue();
	}
	else if((m_enemyShips.queueFront())->attack(m_myShips.queueFront())
		== 0){
	  cout << "The " << m_myShips.queueFront()->getName()
	       << " was damaged." << endl;
	  //changes the defense of the ship
	  m_myShips.queueFront()->setDefense((m_myShips.queueFront()->
					      getDefense()) - (m_enemyShips.
							       queueFront()->
							       getAttack()));
	}
      }
    }
  }
  else{
    while (m_myShips.isEmpty() == 0 && m_enemyShips.isEmpty() == 0){
      //imperials attack rebels first
      cout << "The Imperial " << m_enemyShips.queueFront()->getName() 
	   << " attacks the Rebel " <<
        m_myShips.queueFront()->getName() << endl;

      if ((m_enemyShips.queueFront())->attack(m_myShips.queueFront()) == 1){
	cout << "The " << m_myShips.queueFront()->getName()
             << " was destroyed." << endl;
        m_myShips.dequeue();
      }else if((m_enemyShips.queueFront())->attack(m_myShips.queueFront())
               == 0){
	cout << "The " << m_myShips.queueFront()->getName()
             << " was damaged." << endl;
	//changes the defense of the ship
        m_myShips.queueFront()->setDefense((m_myShips.queueFront()->
                                               getDefense()) - (m_enemyShips.
                                                                queueFront()->
                                                                getAttack()));
        
	//then rebels attack imperials
	cout << "The Rebel " << m_myShips.queueFront()->getName() 
	     << " attacks the Imperial " <<
	  m_enemyShips.queueFront()->getName() << endl;

	if ((m_myShips.queueFront())->attack(m_enemyShips.queueFront()) == 1){
	  cout << "The " << m_enemyShips.queueFront()->getName()
	       << " was destroyed." << endl;
          m_enemyShips.dequeue();
        }
        else if((m_myShips.queueFront())->attack(m_enemyShips.queueFront())
                == 0){
	  cout << "The " << m_enemyShips.queueFront()->getName()
	       << " was damaged." << endl;
	  //changes the defense of the ships
          m_enemyShips.queueFront()->setDefense((m_enemyShips.queueFront()->
                                              getDefense()) - (m_myShips.
                                                               queueFront()->
                                                               getAttack()));
	}
      }
    }
  }

  //if your ship Tqueue is empty you lose otherwise you win
  if (m_myShips.isEmpty() == 1){
    cout << "You Lose!!!" << endl;
  }else{
    cout << "You Win!!!" << endl;
  }
}
