#include <iostream>
#include <string>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

int main(){
    PasswordManager passwordSample[3];
    string user, pass;

    // Working as intended
    ifstream fin;
    fin.open("passwords.txt");
    if (!fin){ //Error check
        cout << "ERROR: File failed to open." << endl;
    }
    else{ //Read data from the file
        for (int i = 0; i < 3; i++){
            fin >> user;
            passwordSample[i].setUsername(user);
            fin >> pass;
            passwordSample[i].setEncryptedPassword(pass);
            fin >> ws;

            // Debug/Testing code
            // cout << passwordSample[i].getUsername() << endl;
            // cout << passwordSample[i].getEncryptedPassword() << endl;
        }
    }
}