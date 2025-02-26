#include <iostream>
using namespace std;

class TollBooth {
    unsigned int totalCars;
    double totalCash;

public:

    TollBooth(unsigned int _totalCars=0, double _totalCash=0){
        totalCars=_totalCars;
        totalCash=_totalCash;
    }

    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }

    void nopayCar() {
        totalCars++;
    }

    void display(){
        cout << "Total cars: " << totalCars << endl;
        cout << "Total cash collected: " << totalCash << endl;
    }
};

int main() {
    TollBooth booth;
    char ch;

    cout << "Press 'p' for a paying car, 'n' for a nonpaying car, or 'Esc' to quit.\n";

    while (true) {
        cin>>ch;
        if (ch == 'e' || ch == 'E') {
            cout << "\nExiting program...\n";
            booth.display();
            break;
        } else if (ch == 'p' || ch == 'P') {
            booth.payingCar();
            cout << "Paying car counted.\n";
        } else if (ch == 'n' || ch == 'N') {
            booth.nopayCar();
            cout << "Nonpaying car counted.\n";
        } else {
            cout << "Invalid input. Press 'p', 'n', or 'Esc'.\n";
        }
    }

    return 0;
}

