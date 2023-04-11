// File Name: PasswordDriver.cpp
//
// Author: Alyana Imperial
// Date: 04/10/2023
// Assignment Number: 2
// CS 2308.258 Spring 2023
//
// driver or main file that compiles or mimics a change
// password program.
#include <iostream>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

int main() {

  PasswordManager pw[4];
  string filename;
  bool match; 
  
  cout << "Please enter the name of the input file: " << endl;
  cin >> filename;

  ifstream inputFile(filename);
  if (!inputFile){
    cout << "Error opening file." << endl;
    exit(0);
  }

  string user, password;

  for (int i = 0; i < 4; i++){
    inputFile >> user >> password;
    pw[i].setUsername(user);
    pw[i].setEncryptedPassword(password);
  }

  string userInput;
  cout << "Please enter your netID: ";
  cin >> userInput;

  string oldPW;
  cout << "Please enter your old password: ";
  cin >> oldPW;

  string newPW;
  cout << "Please enter your new password: ";
  cin >> newPW;

  int index; 
  for (int i = 0; i < 4; i++){
    if (userInput == pw[i].getUsername()){
      match = true;
     index = i;
    }
  }
  if (match == false){
    cout << "NetID is invalid, password not changed." << endl;
    exit(0);
  }
  if (!pw[index].authenticate(oldPW)){
    cout << "Old password is incorrect." << endl;
    exit(0);
  }
  if (!pw[index].setNewPassword(newPW)){
    cout << "New Password does not meet criteria." << endl;
  exit(0);
  }
    for (int i = 0; i < 4; i++){
      cout << pw[i].getUsername() << pw[i].getEncryptedPassword() << endl;
    }

  cout << "Password has been changed for netID: " << userInput << endl;
    return 0;
 
  
}