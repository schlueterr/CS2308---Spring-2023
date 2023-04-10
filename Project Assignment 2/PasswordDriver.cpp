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

    cout << user_netID << "is the netID" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Testing to see if getUserName works: " << passwordSample[i].getUsername() << endl;
    }


// This one works sorta
 /* 
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
*/

int size = 3;
int index = -1; // index of perticular member function in class

for(int i=0; i<size; i++){
    cout << "Testing" << endl;
    cout << passwordSample[0].getUsername() << endl;
    cout << passwordSample[1].getUsername() << endl;
    cout << passwordSample[2].getUsername() << endl;
    cout << user_netID << endl;
    if(passwordSample[i].getUsername() == user_netID){
        index=i;
        break;
    }
}
cout << "password sample index 0: " << passwordSample[0].getUsername() << endl;
cout << "password sample index 1: " << passwordSample[1].getUsername() << endl;
cout << "password sample index 2: " << passwordSample[2].getUsername() << endl;

if(index == -1)
    cout<< "NetID is invalid, password not changed."<< endl;

// authenticating if old password is correct
//else if(!passwordSample[index].authenticate(user_oldPass))
//    cout<< "Old password is incorrect."<< endl;

// checking if new password meets criteria and changing password if true
else if(user1.setNewPassword(user_newPass)== true)
{
    cout << "Password has been changed for netID: ";
    cout << passwordSample[index].getUsername()<< endl;
}
else
    cout << "New Password does not meet criteria.";

   
   
    ofstream fout;
    fout.open("passwords.txt");
    for (int i = 0; i < 3; i++){
        fout << passwordSample[i].getUsername() << " " << passwordSample[i].getEncryptedPassword() << endl;
    }
    fout.close();

    return 0;
    
}