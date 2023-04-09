#include "PasswordManager.h"
#include <iostream>
#include <string>
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

using namespace std;

string PasswordManager::encrypt(string pass){
    const int SHIFT = 37;         // amount to shift/cycle the ascii value
    string encryptedStr;          // encrypted version of string

    for (int i=0; i < pass.length(); i++) {
        char x = ((encryptedStr[i]-33) + SHIFT) % 94 + 33;
        pass.push_back(x);
    }
    return encryptedStr;
}

bool PasswordManager::meetsCriteria(string pass){
    bool upper_count = 0, lower_count = 0, digit_count = 0, special_count = 0;
    if (pass.length() < 15){
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
            else if (ispunct(pass[i])){
                special_count = 1;
            }
        }
        if (upper_count && lower_count && digit_count && special_count){
            return true;
        }
        else{
            return false;
        }
    }

}

void PasswordManager::setUsername(string user){
    userName = user;
}

string PasswordManager::getUsername() const{
    return userName;
}

void PasswordManager::setEncryptedPassword(string pass){
    encryptedPassword = pass;
}

string PasswordManager::getEncryptedPassword() const{
    return encryptedPassword;
}

bool PasswordManager::setNewPassword(string pass){
    if (meetsCriteria(pass)){
        encryptedPassword = encrypt(pass);
        return true;
    }
    else{
        return false;
    }
}

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