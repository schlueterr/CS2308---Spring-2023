#include <iostream>
#include <string>

using namespace std;

class BankAccount{
    private:
        string accountNumber;
        string accountHolderName;
        double balance;
    public:
        BankAccount(const string &accountNumber, const string &accountHolderName, double balance){
            this->accountNumber = accountNumber;
            this->accountHolderName = accountHolderName;
            this->balance = balance;
        } 
        void deposit(double amount){
            balance += amount;
        }

        void withdraw(double amount){
            if (amount > balance){
                cout << "Insufficient funds" << endl;
            }
            else{
                balance -= amount;
            }
        }

        void display(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder Name: " << accountHolderName << endl;
            cout << "Balance: " << balance << endl;
        }
};

int main(){
    BankAccount account1 ("12334582", "John Doe", 1000.0);
    account1.display();
    account1.deposit(500.0);
    account1.display();
    account1.withdraw(2000.0);
    account1.display();
    account1.withdraw(100.0);
    account1.display();

    return 0;
}