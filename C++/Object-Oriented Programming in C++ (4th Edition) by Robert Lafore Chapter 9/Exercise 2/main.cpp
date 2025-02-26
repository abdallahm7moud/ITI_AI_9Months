#include <iostream>
#include <string.h>
using namespace std;

class Employee {
    char name[50];
    int id;

public:
    Employee(){
        id=0;
        strcpy(name, "No name");

    }
    Employee(int _id,char _name[] ){
        id=_id;
        strcpy(name, _name);

    }

    void getdata() {
        cout << "Enter employee name: ";
        cin>>name;
        cout << "Enter employee ID: ";
        cin >> id;
    }

    void putdata(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

class Employee2 : public Employee {
    double compensation;
    enum Period { HOURLY, WEEKLY, MONTHLY } period;

public:
    Employee2(){
        compensation=0;
        period=HOURLY;

    }

    void getdata() {
        Employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;

        char choice;
        cout << "Enter pay period (h for hourly, w for weekly, m for monthly): ";
        cin >> choice;
        switch (choice) {
        case 'h':
        case 'H':
            period = HOURLY;
            break;
        case 'w':
        case 'W':
            period = WEEKLY;
            break;
        case 'm':
        case 'M':
            period = MONTHLY;
            break;
        default:
            cout << "Invalid input. Setting pay period to hourly." << endl;
            period = HOURLY;
        }
    }

    void putdata(){
        Employee::putdata();
        cout << "Compensation: " << compensation << endl;
        cout << "Pay Period: ";
        switch (period) {
        case HOURLY:
            cout << "Hourly";
            break;
        case WEEKLY:
            cout << "Weekly";
            break;
        case MONTHLY:
            cout << "Monthly";
            break;
        }
        cout << endl;
    }
};

class Manager : public Employee2 {};
class Scientist : public Employee2 {};
class Laborer : public Employee2 {};

int main() {
    Manager manager;
    Scientist scientist;
    Laborer laborer;

    cout << "Enter details for manager:\n";
    manager.getdata();
    cout << "\nDetails of manager:\n";
    manager.putdata();

    cout << "\nEnter details for scientist:\n";
    scientist.getdata();
    cout << "\nDetails of scientist:\n";
    scientist.putdata();

    cout << "\nEnter details for laborer:\n";
    laborer.getdata();
    cout << "\nDetails of laborer:\n";
    laborer.putdata();

    return 0;
}
