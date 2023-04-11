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

    PasswordManager user1;
    int size = 4;
    int index = -1; // index of perticular member function in class

    for(int i=0; i<size; i++){
        if(passwordSample[i].getUsername() == user_netID){
            index=i;
            // Debug/Testing code
            // cout << "username is equal to user_netID " << passwordSample[i].getUsername() << endl;
            break;
        }
    }

    if(index == -1){ // if index is not found after loop
        cout<< "\nNetID is invalid, password not changed."<< endl;
    }


    for (int i = 0; i < size; i++){
        index = i;
        
        /* if (passwordSample[index].setNewPassword(user_oldPass)){
            cout << "\nNew password does not meet criteria." << endl;
            break;
        }
    */
        if(passwordSample[i].getUsername() == user_netID){ // This is working as intended
            // If old password is correct, change password
        if(user_oldPass == passwordSample[index].getEncryptedPassword()){
                passwordSample[i].setEncryptedPassword(user_newPass);
                cout << "\nPassword has been changed for netID: " << passwordSample[i].getUsername() << endl;
            }
        else{
                cout << "\nOld password is incorrect." << endl;
            }
       }
    }

   cout << endl;
   for (int i = 0; i < 4; i++){
        cout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }
   
    ofstream fout;
    fout.open("passwords.txt");
    for (int i = 0; i < 4; i++){
        fout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }
    fout.close();

    return 0;
}
