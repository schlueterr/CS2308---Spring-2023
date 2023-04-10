#include <iostream>
using namespace std;

class PasswordManager {
    private: 
        string userName;
        string encryptedPassword;
        string encrypt(string);
        bool meetsCriteria(string);
    public:
        void setUsername(string);
        string getUsername() const;
        void setEncryptedPassword(string);
        string getEncryptedPassword() const;
        bool setNewPassword(string);
        bool authenticate(string);
};