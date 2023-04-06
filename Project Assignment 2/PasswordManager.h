#include <iostream>
using namespace std;

class PasswordManager {
    private: 
        string password;
        string encryptedPassword;
        string ecrypt(string pass);
        bool meetsCriteria(string pass);
    public:
        void setUsername(string user);
        string getUsername();
        void setEncryptedPassword(string pass);
        string getEncryptedPassword();
        void setNewPassword(string pass);
        bool authenticate(string pass);
};