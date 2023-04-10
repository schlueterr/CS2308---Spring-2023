#include <iostream>
#include <string>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

int main(){
    PasswordManager passwordSample[3];
    string user, pass;
    string fileName;

    // Working as intended
    ifstream fin;
    // cout << "Please enter the name of the input file: " << endl;
    // cin >> fileName;
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
            //  cout << passwordSample[i].getEncryptedPassword() << endl;
        }
    }
    fin.close();

    cout << "A valid password must meet the following criteria:" << endl;
    cout << "1. Must be at least 8 characters long" << endl;
    cout << "2. Must contain at least one uppercase letter" << endl;
    cout << "3. Must contain at least one lowercase letter" << endl;
    cout << "4. Must contain at least one digit" << endl;

    PasswordManager user1;
    string user_netID, user_newPass, user_oldPass;
    
    // Ask user for netID, new & old password
    cout << "Please enter your netID: " << endl;
        cin >> user_netID;
    cout << "Please enter your old password: " << endl;
        cin >> user_oldPass;
    cout << "Please enter your new password: " << endl;
        cin >> user_newPass;

    // Debug/Testing code
    // cout << "Your netID is: " << user_netID << " Your old password is: "
       //  << user_oldPass << " Your new password is: " << user_newPass << endl;


    // Debug/Testing code 
/*
    cout << user_netID << "is the netID" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Testing to see if getUserName works: " << passwordSample[i].getUsername() << endl;
    }
*/
  
    for (int i = 0; i < 3; i++){
        if (user_netID == passwordSample[i].getUsername()){
            cout << "Your netID is valid." << endl;
            if (user_oldPass == passwordSample[i].getEncryptedPassword()){
                cout << "Your old password is valid." << endl;
                if (user1.setNewPassword(user_newPass)){
                    cout << "Your new password is valid." << endl;
                    passwordSample[i].setEncryptedPassword(user_newPass);
                    cout << "Your password has been changed." << endl;
                }
                else{
                    cout << "Your new password is invalid." << endl;
                }
            }
            else{
                cout << "Your old password is invalid." << endl;
            }
        }
        else{
            cout << "Your netID is invalid." << endl;
        }
    }

    ofstream fout;
    fout.open("passwords.txt");
    for (int i = 0; i < 3; i++){
        fout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }
    fout.close();

    return 0;
    
}