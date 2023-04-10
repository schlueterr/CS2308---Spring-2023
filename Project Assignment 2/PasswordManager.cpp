// File Name: PasswordManager.cpp
//
// Author: Braden Schlueter plr61
// Date: 04/10/2023
// Assignment Number: 2
// CS 2308.258 Spring 2023
//
// A class source file for the PasswordManager class that includes the member functions.

#include "PasswordManager.h"
#include <iostream>
#include <string>
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

using namespace std;

//***********************************************************
// PasswordManager: default constructor for the PasswordManager class, initializes the userName and encryptedPassword variables.
//
//***********************************************************
PasswordManager::PasswordManager(){
    userName = "";
    encryptedPassword = "";
}

//***********************************************************
// encrypt: takes a password and encrypts it given the algorithm.
//
// pass: the password to be encrypted
//
// returns: the encrypted password (string)
//***********************************************************
string PasswordManager::encrypt(string pass){
    const int SHIFT = 37;         // amount to shift/cycle the ascii value
    string encryptedStr;          // encrypted version of string

    for (int i=0; i < pass.length(); i++) {
        char x = ((encryptedStr[i]-33) + SHIFT) % 94 + 33;
        pass.push_back(x);
    }
    return encryptedStr;
}

//***********************************************************
// meetsCriteria: checks if a password meets the criteria for a valid password.
//
// pass: the input password to be checked
//
// returns: a boolean value (true if password meets criteria, false if not)
//***********************************************************
bool PasswordManager::meetsCriteria(string pass){
    bool upper_count = 0, lower_count = 0, digit_count = 0;
    if (pass.length() < 8){
        return false;
    }
    else{
        for (int i = 0; i < pass.length(); i++){
            if (isupper(pass[i])){
                upper_count = 1;
            }
            else if (islower(pass[i])){
                lower_count = 1;
            }
            else if (isdigit(pass[i])){
                digit_count = 1;
            }
        }
        if (upper_count && lower_count && digit_count){
            return true;
        }
        else{
            return false;
        }
    }

}

//***********************************************************
// setUsername: sets the username to the userName variable.
//
// user: the username to be set to the userName variable
//***********************************************************
void PasswordManager::setUsername(string user){
    userName = user;
}

//***********************************************************
// getUsername: returns the username.
//
// returns: the username (string)
//***********************************************************
string PasswordManager::getUsername() const{
    return userName;
}

//***********************************************************
// setEncryptedPassword: sets the encrypted password to the encryptedPassword variable.
//
// pass: the password to be set to the encryptedPassword variable
//***********************************************************
void PasswordManager::setEncryptedPassword(string pass){
    encryptedPassword = pass;
}

//***********************************************************
// getEncryptedPassword: returns the encrypted password.
//
// returns: the encrypted password (string)
//***********************************************************
string PasswordManager::getEncryptedPassword() const{
    return encryptedPassword;
}

//***********************************************************
// setNewPassword: sets a new password if it meets the criteria.
//
// pass: the input password to be checked and set if it meets the criteria
// returns: a boolean value (true if password meets criteria, false if not)
//***********************************************************
bool PasswordManager::setNewPassword(string pass){
    if (meetsCriteria(pass)){
        encryptedPassword = encrypt(pass);
        return true;
    }
    else{
        return false;
    }
}

//***********************************************************
// authenticate: authenticates a input password against the encrypted password.
//
// pass: the input password to be checked against the encrypted password
// returns: a boolean value (true if password matches, false if not)
//***********************************************************
bool PasswordManager::authenticate(string pass){
    string tempPass = encrypt(pass);
    if (tempPass == encryptedPassword){
        return true;
    }
    else{
        return false;
    }
}

#endif