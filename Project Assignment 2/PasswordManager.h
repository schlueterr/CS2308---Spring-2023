#include <iostream>
using namespace std;

class PasswordManager {
    private: 
        string userName;
        string encryptedPassword;
        string encrypt(string pass);
        bool meetsCriteria(string pass);
    public:
        void setUsername(string user);
        string getUsername() const;
        void setEncryptedPassword(string pass);
        string getEncryptedPassword() const;
        bool setNewPassword(string pass);
        bool authenticate(string pass);
};