#include <iostream>
#include <string>
#include <fstream>
#include "PasswordManager.h"
using namespace std;

int main(){
    PasswordManager passwordSample[4];
    string user, pass;
    string fileName;
    bool flag;

    // Working as intended
    ifstream fin;
    cout << "Please enter the name of the input file: " << endl;
    cin >> fileName;
    fin.open(fileName);
    if (!fin){ //Error check
        cout << "ERROR: File failed to open." << endl;
        exit(0);
    }
    else{ //Read data from the file
        for (int i = 0; i < 4; i++){
            fin >> user;
            passwordSample[i].setUsername(user);
            fin >> pass;
            passwordSample[i].setEncryptedPassword(pass);
            fin >> ws;

            // Debug/Testing code
            //cout << passwordSample[i].getUsername() << endl;
            // cout << passwordSample[i].getEncryptedPassword() << endl;
        }
    }
    fin.close();

    cout << "A valid password must meet the following criteria:" << endl;
    cout << "1. Must be at least 8 characters long" << endl;
    cout << "2. Must contain at least one uppercase letter" << endl;
    cout << "3. Must contain at least one lowercase letter" << endl;
    cout << "4. Must contain at least one digit" << endl;

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
    int index; // index of perticular member function in class
    int size = 4;
    for (int i = 0; i < size; i++){
        if (user_netID == passwordSample[i].getUsername()){
            index = i;
            flag = true;
        }
    }
    if (flag == false){
        cout << "NetID is invalid, password not changed." << endl;
        exit(0);
    }
    if (!passwordSample[index].authenticate(user_oldPass)){
        cout << "Old password is incorrect." << endl;
        exit(0);
    }
    if (!passwordSample[index].setNewPassword(user_newPass)){
        cout << "New Password does not meet criteria." << endl;
        exit(0);
    }
    for (int i = 0; i < 4; i++){
        cout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }

    cout << "Password has been changed for netID: " << passwordSample[index].getUsername() << endl;

    return 0;
}
/*
    int size = 3;
    int index = -1; // index of perticular member function in class

    for(int i=0; i<size; i++){
        if(passwordSample[i].getUsername() == user_netID){
            index=i;
            // Debug/Testing code
            // cout << "username is equal to user_netID " << passwordSample[i].getUsername() << endl;
            break;
        }
    }
  //  cout << "password sample index 0: " << passwordSample[0].getUsername() << endl;
  //  cout << "password sample index 1: " << passwordSample[1].getUsername() << endl;
  //  cout << "password sample index 2: " << passwordSample[2].getUsername() << endl;

    if(index == -1){ // if index is not found after loop
        cout<< "\nNetID is invalid, password not changed."<< endl;
    }

    for (int i = 0; i < 3; i++){
        index = i;
        if(passwordSample[i].getUsername() == user_netID){ // This is working as intended
            cout << "\n" << passwordSample[i].getEncryptedPassword() << endl;
            cout << user_oldPass << endl;
            // cout << "Testing to see where this is going wrong" << endl;
            // passwordSample[i].setEncryptedPassword(user_oldPass);
            // cout << passwordSample[i].getEncryptedPassword() << endl;
            if(user1.setNewPassword(user_newPass) == false){
                cout << "\nNew password does not meet criteria." << endl;
            }
            if (user_oldPass == passwordSample[index].getEncryptedPassword()){
                passwordSample[i].setEncryptedPassword(user_newPass);
                passwordSample[i].setEncryptedPassword(user_oldPass);
                cout << "\nPassword has been changed for netID: " << passwordSample[i].getUsername() << endl;
            }
            else{
                cout << "\nOld password is incorrect." << endl;
            }
       }
    }
// Old password is incorrect
// Password has been changed for netId: user_netID
// New password does not meet criteria

   for (int i = 0; i < 3; i++){
        cout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }
   
    ofstream fout;
    fout.open("passwords.txt");
    for (int i = 0; i < 3; i++){
        fout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }
    fout.close();

    return 0;
   */ 
