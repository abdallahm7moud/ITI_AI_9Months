#include <iostream>

using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;

public:
    Time(int _hours=0, int _minutes=0, int _seconds=0){
        hours=_hours;
        minutes=_minutes;
        seconds=_seconds;

    }

    void display() const {
        cout << hours << ":"<< minutes << ":"<<seconds << endl;
    }

    void add(const Time& t1, const Time& t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + seconds / 60;
        hours = t1.hours + t2.hours + minutes / 60;

        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
};

int main() {
    const Time time1(5, 45, 30);
    const Time time2(3, 20, 40);

    Time result;

    result.add(time1, time2);

    cout << "Time 1: ";
    time1.display();
    cout << "Time 2: ";
    time2.display();
    cout << "Result of addition: ";
    result.display();

    return 0;
}
