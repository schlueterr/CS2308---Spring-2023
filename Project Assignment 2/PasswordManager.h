// File Name: PasswordManager.h
//
// Author: Braden Schlueter plr61
// Date: 04/10/2023
// Assignment Number: 2
// CS 2308.258 Spring 2023
//
// A class definition for a PasswordManager class.

#include <iostream>
using namespace std;

class PasswordManager {
    private: 
        string userName;
        string encryptedPassword;
        string encrypt(string);
        bool meetsCriteria(string);
    public:
        PasswordManager();
        void setUsername(string);
        string getUsername();
        void setEncryptedPassword(string);
        string getEncryptedPassword();
        bool setNewPassword(string);
        bool authenticate(string);
};