#include <iostream>
using namespace std;

class Employee {
    int employeeNumber;
    float compensation;

public:
    Employee(int _employeeNumber=0,float _compensation=0 ){
        employeeNumber=_employeeNumber;
        compensation=_compensation;

    }

    void input() {
        cout << "Enter employee number: ";
        cin >> employeeNumber;
        cout << "Enter employee compensation: ";
        cin >> compensation;
    }

    void display(){
        cout << "Employee Number: " << employeeNumber
             << ", Compensation: " << compensation << endl;
    }
};

int main() {
    const int NUM_EMPLOYEES = 3;
    Employee employees[NUM_EMPLOYEES];

    cout << "Enter details for " << NUM_EMPLOYEES << " employees:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "\nEmployee " << (i + 1) << ":\n";
        employees[i].input();
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        cout << "Employee " << (i + 1) << ": ";
        employees[i].display();
    }

    return 0;
}
