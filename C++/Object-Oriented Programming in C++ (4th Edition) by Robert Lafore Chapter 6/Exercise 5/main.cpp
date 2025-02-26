#include <iostream>
using namespace std;

class Date {
    int month;
    int day;
    int year;

public:
    Date(int _day=1,int _month=1,int _year=2000){
        day=_day;
        month=_month;
        year=_year;
    }

    void getdate() {
        char separator;
        cout << "Enter date (MM/DD/YY): ";
        cin >> month >> separator >> day >> separator >> year;
    }

    void showdate(){
        cout <<month << "/"<< day << "/"<<year << endl;
    }
};

int main() {
    Date today;


    today.getdate();
    cout << "The date you entered is: ";
    today.showdate();

    return 0;
}
