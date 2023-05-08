#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Car{
    private: 
        string make;
        string model;
        int year;
    public:
        Car (const string &make, const string &model, int year){
            this->make = make;
            this->model = model;
            this->year = year;
        }

        string getMake(){
            return make;
        }

        string getModel(){
            return model;
        }

        int getYear(){
            return year;
        }

        void setMake(const string &carMake){
            make = carMake;
        }

        void setModel(const string &carModel){
            model = carModel;
        }

        void setYear(int carYear){
            year = carYear;
        }
};

int main(){
    Car car1 ("Toyota", "Camry", 2015);
    cout << "Make: " << car1.getMake() << endl;
    cout << "Model: " << car1.getModel() << endl;
    cout << "Year: " << car1.getYear() << endl;

    cout << endl;

    car1.setMake("Honda");
    car1.setModel("Civic");
    car1.setYear(2002);

    cout << "Make: " << car1.getMake() << endl;
    cout << "Model: " << car1.getModel() << endl;
    cout << "Year: " << car1.getYear() << endl;

    return 0;
}