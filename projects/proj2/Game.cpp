/*****************************************
 ** File:    Game.cpp
 ** Project: CMSC 202 Project 2, Spring 2018
 ** Author:  Nana Owusu
 ** Date:    3/28/18
 ** Section: 7791
 ** E-mail:  onana1@gl.umbc.edu
 **
 ** This file contains the Game.cpp program for Project 2.
 ** This file welcomes the user to the game and loads the 
 ** dragons into a vector, where the user can then try to find
 ** an egg and then try and hatch that egg into a dragon, where they
 ** are put in a vector and can use those dragons to fight other  
 ** dragons.
 **
 ***********************************************/

#include <ctime>
#include "Game.h"

using namespace std;

//Game
//Creates a game for the user
Game::Game(){
  //constructor of the game that introduces game and loads dragons
  string playName; //name of the person playing
  cout << "Welcome to Dragon Wars" << endl;
  cout << "What is your name" << endl;
  getline(cin, playName);
  m_name = playName;
  LoadDragons();
  //seeding the randomizer with time
  srand(time(NULL));
  }

//LoadDragons
//Loads all the dragons from the dragons text file
void Game::LoadDragons(){
  string line; //the entire line of a file 
  string dName; //name of the dragon from the file
  string dType; //name of the type from the file
  string dMax; //max size of the dragon from the file in string form
  string dRare; // rarity of the dragon from the file in string form
  bool dHatch = false; //makes the dragon not hatched
  ifstream inputStream; //input stream to get data from the file
  vector<Dragon> dragonList; //declaration of a vector filled with drag objects
  dragonSize dragonMax; //enumeration of the dragons max size
 
  // getting the data from the file
  inputStream.open(PROJ2_DRAGONS.c_str());
  if (inputStream.is_open()){
    // stopping at commas and putting information into variables
    while (getline(inputStream, dName,',')){
	getline(inputStream, dType,',');
	getline(inputStream, dMax,',');
	getline(inputStream, dRare);
	// getting a dragonsize type for the max to corresponding number
	if (dMax == "1")
	  dragonMax = tiny;
	if (dMax == "2")
	  dragonMax = small;
	if (dMax == "3")
	  dragonMax = medium;
	if (dMax == "4")
	  dragonMax = large;
	if (dMax == "5")
	  dragonMax = huge;
	
	//making the rarity from the file into an int
	int dragonRare = atoi(dRare.c_str()); //integer of rarirty
	//construction of a dragon
	Dragon dragonData(dName, dType, dHatch, tiny, dragonMax, dragonRare);
	dragonData.SetName(dName);
	dragonData.SetType(dType);
	dragonData.HatchDragon();
	dragonData.SetCurSize(tiny);
	dragonData.SetMaxSize(dragonMax);
	dragonData.SetRarity(dragonRare);
	
	//putting dragons into vector
	dragonList.push_back(dragonData);
	//copying vector into member vector
	m_dragons = dragonList;
    
    }   
  }else{
    cout << "File Failed" << endl;
  }
  DisplayAllDragons();
}

//DisplayAllDragons
//function that displays all the dragons in the game
void Game::DisplayAllDragons(){
  cout << setw(20) <<"Name" << setw(20) << "Type" << setw(20) << "Max Size" 
       << setw(20) << "Rarity" <<endl;
  for (vector<Dragon>::iterator it = m_dragons.begin(); 
       it != m_dragons.end(); ++it){
    cout << setw(20)<<(*it).GetName()<<setw(20)<< (*it).GetType()<<setw(20) 
	 << (*it).GetMaxSize()+1 << setw(20) << (*it).GetRarity()
         << endl;
    cout << endl;
  }
}

//MainMenu
//outputs the main menu to the user and returns the action that the user 
//selects
int Game::MainMenu(){
  int numMain; //number from the menu that the user selects
  do{
    cout << "What would you like to do?" << endl;
    cout << "1. Search for an egg" << endl;
    cout << "2. Try to hatch egg" << endl;
    cout << "3. Display all dragons and eggs" << endl;
    cout << "4. Attack!" << endl;
    cout << "5. Quit" << endl;
    cin >> numMain;
  } while (numMain < 1  &&  numMain > 5);
    return numMain;
}

//SearchEgg
//gets the users choice of what rarity they want and searches for that egg
//and if found puts the egg into the users vector of dragons
void Game::SearchEgg(){
  int a; //random integer
  int b; //random integer
  int x = 0; //used to go through an array
  int numRare; //rarity that the user wants to searcch for
  int numChance; //amount of chance that a rarity has to be found
  string dragEgg; //name of the dragon egg found
  int count = 0; //counter
  do{
    cout << "What rarity egg would you like to search for?" << endl;
    cout << "Enter a rarity (1 = very common and 10 = very rare)" << endl;
    cin >> numRare;
  } while (numRare < 1 || numRare > 10 ); 
  a = static_cast<int>(rand())% 100 + 1;
  if (numRare == 1)
    numChance = 92;
  else if (numRare == 2)
    numChance = 82;
  else if (numRare == 3)
    numChance = 73;
  else if (numRare == 4)
    numChance = 64;
  else if (numRare == 5)
    numChance = 55;
  else if (numRare == 6)
    numChance = 46;
  else if (numRare == 7)
    numChance = 37;
  else if (numRare == 8)
    numChance = 28;
  else if (numRare == 9)
    numChance = 19;
  else if (numRare == 10)
    numChance = 10;

  if (a <= numChance){
    for (vector<Dragon>::iterator it = m_dragons.begin();
	 it != m_dragons.end(); ++it){
      if ((*it).GetRarity() == numChance)
	count++;
    }
    b = static_cast<int>(rand())% count + 0;
    string eggArray[count];
    for (vector<Dragon>::iterator it = m_dragons.begin();
	 it != m_dragons.end(); ++it){
      if ((*it).GetRarity() == 1){
	eggArray[x]=(*it).GetName();
	x++;
      }
    }
    dragEgg = eggArray[b];
    cout << "You found a " << dragEgg << " egg!" << endl;
    for (vector<Dragon>::iterator it = m_dragons.begin();
	 it != m_dragons.end(); ++it){
      if (dragEgg == (*it).GetName())
	m_myDragons.push_back(*it);
    }
  }
  else{
    cout << "Sorry you did not find a dragon of that rarity." << endl;
 }
  StartGame();
}

//HatchEgg
//Tries to hatch an egg from the users vector
void Game::HatchEgg(){
  int eggCount = 0;
  int eggPick;
  int c = static_cast<int>(rand())% 100 + 1;
  cout << "Which dragon would you like to try and hatch?" << endl;
  cin >> eggPick;
  for (vector<Dragon>::iterator it = m_myDragons.begin();
       it != m_myDragons.end(); ++it){
    eggCount++;
    if (eggCount == eggPick-1){
      if (c <= 50){
	if ((*it).GetIsHatched() == true)
	  cout << "The dragon did not hatch or is already hatched" << endl;
	(*it).GetIsHatched() == true;
	cout << "Your " << (*it).GetName() << " egg has hatched into a dragon!"
	     << endl;
      }else{
	cout << "The dragon did not hatch or is already hatched" << endl;
      }
    }
  }
}

//DisplayMyDragons
//function that displays the users dragons from a vector
void Game::DisplayMyDragons(){
  int counter = 1;
  cout << "****************" << endl;
  cout << m_name << "'s Dragons" << endl;
  cout << setw(15) <<"Name" << setw(10) << "Type" << setw(10) << "Egg/Dragon"
       << setw(10) << "Current Size" << setw(10) << "Max Size" << endl;
  for (vector<Dragon>::iterator it = m_myDragons.begin();
       it != m_myDragons.end(); ++it){
    cout << setw(2) << counter << "." << setw(20) <<( *it).GetName() <<setw(10)
	 << (*it).GetType() <<setw(10);
    if ((*it).GetIsHatched() == true)
      cout << "dragon";
    else
      cout << "egg";
    
    cout << setw(10) << (*it).GetCurSize() << setw(10) << (*it).GetMaxSize()+1
         << endl;
    cout << endl;
  }
  StartGame();
}

//Attack
//function where the users dragon attacks a random dragon and the 
//players dragon gets removed if they lose the battle
void Game::Attack(){
  int dragNum = 0; //amount of all dragons that can battle
  int dragRand = 0; //number of vector stopper for iterator at a random number
  int dragPick = 0; //numer of the enemy dragon that is selected 
  int playerDrag = 0; //num of the players dragon that is selected
  int breathChance = 0; //chance of dragon breathing
  Dragon *playerDragFight; //pointer to the players dragon thats battling
  string fightChoice; // letter of whether or not the player wants to fight
  string foundDrag; // name of the dragon that was found randomly
  string playerDragName; //name of the players dragon
  cout << "Attack" << endl;
  for (vector<Dragon>::iterator it = m_dragons.begin();
       it != m_dragons.end(); ++it){
    dragNum++;
  }
  int d = static_cast<int>(rand())% dragNum;
  for (vector<Dragon>::iterator it = m_dragons.begin();
       it != m_dragons.end(); ++it){
    dragRand++;
    if (dragRand == d){
      cout << "You found a " << (*it).GetName() << " to fight!" << endl;
      foundDrag == (*it).GetName();
    }
    do{
      cout << "Do you want to fight it? (y/n)" << endl;
      cin >> fightChoice;
    }while (fightChoice != "y" || fightChoice != "n");
    
    //player choice on whether to battle or run
    if (fightChoice == "y"){
      DisplayMyDragons();
      cout << "Which dragon would you like to fight with?" << endl;
      cin >> dragPick;
      for (vector<Dragon>::iterator it = m_myDragons.begin();
	   it != m_myDragons.end(); ++it){
	playerDrag++;
	if (dragPick == playerDrag-1){
	  cout << "Your " << (*it).GetName() << " attacks the " << foundDrag 
	       << "!" << endl;
	  playerDragName = (*it).GetName();
	  for(unsigned int i = 0; i < m_myDragons.size(); i++)
	    if (dragPick - 1  == int(i))
	      playerDragFight = &m_myDragons[i];
	}
      }
      //chance of whether the dragon will breath
      breathChance = static_cast<int>(rand())% 100 + 1;
      //if dragon breaths the dragon wins and grows
      if (breathChance <= 5){
	for (vector<Dragon>::iterator it = m_myDragons.begin();
             it != m_myDragons.end(); ++it){
          if ((*it).GetName() == playerDragName){
	    string breathOut = playerDragFight->BreathAttack();
	    cout << breathOut << endl;
	    cout << "Your " << playerDragName << " defeats the enemy "
		 << foundDrag << "!" << endl;
            if (playerDragFight->AttemptGrow() == true){
              if ((*it).GetCurSize() == tiny){
                (*it).SetCurSize(small);
                cout << "Your dragon grew a bit larger" << endl;
              }else if ((*it).GetCurSize() == small){
                (*it).SetCurSize(medium);
                cout << "Your dragon grew a bit larger" << endl;
              }else if ((*it).GetCurSize() == medium){
                (*it).SetCurSize(large);
                cout << "Your dragon grew a bit larger" << endl;
              }else if ((*it).GetCurSize() == large){
                (*it).SetCurSize(huge);
                cout << "Your dragon grew a bit larger" << endl;
              }else if ((*it).GetCurSize() == huge)
                cout << "Your dragon cannot grow any larger" << endl;
	    }
	  }
	}
	//if dragon loses the dragon gets deleted from vector
      }else if ((playerDragFight->AttackDragon(*it) == false)){
	for (vector<Dragon>::iterator it = m_myDragons.begin();
	     it != m_myDragons.end(); ++it){
	  if ((*it).GetName() == playerDragName){
	    cout << "The " << foundDrag << " defeated your " 
		 << playerDragName << endl;  
	    m_myDragons.erase(it);
	  }}
	//if dragon does not breath and win regularly it grows
      }else
	for (vector<Dragon>::iterator it = m_myDragons.begin();
             it != m_myDragons.end(); ++it){
	  if ((*it).GetName() == playerDragName){
	    cout << "Your " << playerDragName << " defeats the enemy "
                 << foundDrag << "!" << endl;
	    if (playerDragFight->AttemptGrow() == true){
	      if ((*it).GetCurSize() == tiny){
		(*it).SetCurSize(small);
		cout << "Your dragon grew a bit larger" << endl;
	      }else if ((*it).GetCurSize() == small){
                (*it).SetCurSize(medium);
		cout << "Your dragon grew a bit larger" << endl;
	      }else if ((*it).GetCurSize() == medium){
                (*it).SetCurSize(large);
		cout << "Your dragon grew a bit larger" << endl;
	      }else if ((*it).GetCurSize() == large){
                (*it).SetCurSize(huge);
		cout << "Your dragon grew a bit larger" << endl;
	      }else if ((*it).GetCurSize() == huge)
                cout << "Your dragon cannot grow any larger" << endl;
	    }
	  }
	}
    }
    
  else
    StartGame();
  }
  StartGame();
}


//StartGame
//starts the game and calls other functions to be used
void Game::StartGame(){
  switch(MainMenu())
    {
    case 1:
      SearchEgg();
    case 2:
      DisplayMyDragons();
      HatchEgg();
    case 3:
      DisplayMyDragons();
    case 4:
      Attack();
    case 5:
      cout << "Thanks for playing Dragon Wars!" << endl;
    }
}
