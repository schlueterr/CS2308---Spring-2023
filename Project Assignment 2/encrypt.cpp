#include<iostream>
#include<string>

using namespace std;

//***********************************************************
// encrypt: accepts a string to be encrypted.
//   It adds 45 to each character in the string and if it goes
//   past 126, wraps back around starting at 33
// str: the string to be encrypted
// returns the new string, with all the characters encrypted
//***********************************************************

string encrypt (string str) {
    const int SHIFT = 37;         // amount to shift/cycle the ascii value
    string encryptedStr;          // encrypted version of string

    for (int i=0; i < str.length(); i++) {
        char x = ((str[i]-33) + SHIFT) % 94 + 33;
        encryptedStr.push_back(x);
    }
    return encryptedStr;
}

int main() {
    string unen_pd = "abcdABCD1234!@#$";
    cout << "Unencrypted password is " << unen_pd << endl;
    cout << "Encrypted password is " << encrypt(unen_pd); 
}