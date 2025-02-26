#include <iostream>

using namespace std;

class Duration{

    int hours;
    int minutes;
    int seconds;

public:

    void setHours(int _hours){
        hours=_hours;

    }
    void setMinutes(int _minutes){
        hours = _minutes / 60;
        minutes = _minutes % 60;
    }
    void setSeconds(int _seconds){
        hours = _seconds / 3600;
        _seconds %= 3600;
        minutes = _seconds / 60;
        seconds = _seconds % 60;
    }
    int getHours(){
        return hours;
    }
    int getMinutes(){
        return minutes;
    }
    int getSeconds(){
        return seconds;
    }


    Duration(){
         hours =0;
         minutes=0;
         seconds=0;

    }
    Duration(int _hours, int _minutes, int _seconds){
         hours =_hours;
         minutes=_minutes;
         seconds=_seconds;

    }
    Duration(int _seconds){
        hours = _seconds / 3600;
        _seconds %= 3600;
        minutes = _seconds / 60;
        seconds = _seconds % 60;

    }

    void print(){
        if (hours > 0) {
            cout << "Hours: " << hours << ", ";
        }
        if (minutes > 0 || hours > 0) {
            cout << "Minutes: " << minutes << ", ";
        }
        cout << "Seconds: " << seconds << endl;
    }

    Duration operator+(const Duration& d){
        int totalSeconds = (hours + d.hours) * 3600 +
                           (minutes + d.minutes) * 60 +
                           (seconds + d.seconds);
        return Duration(totalSeconds);
    }

    Duration operator+(int extraSeconds)  {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + extraSeconds;
        return Duration(totalSeconds);
    }

    int operator>(const Duration& d){
        if (hours != d.hours)
            return hours > d.hours;
        if (minutes != d.minutes)
            return minutes > d.minutes;
        return seconds > d.seconds;
    }

    int operator<=(const Duration& d){
        if (hours != d.hours)
            return hours < d.hours;
        if (minutes != d.minutes)
            return minutes < d.minutes;
        return seconds <= d.seconds;
    }

    //postfix
    Duration operator++(int) {
        Duration temp = *this;
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + 60;
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
        return temp;
    }

    //prefix
    Duration& operator--() {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds - 60;
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
        return *this;
    }

    friend Duration operator+(int extraSeconds, Duration& d);
};

Duration operator+(int extraSeconds, Duration& d){
        int totalSeconds = d.hours * 3600 + d.minutes * 60 + d.seconds + extraSeconds;
        return Duration(totalSeconds);
}


int main()
{
    Duration D(1,10,15);
    D.print();
    Duration D4(3600);
    D4.print ();
    Duration D5(7800);
    D5.print();
    Duration D6(666);
    D6.print();

    Duration D1(2, 30, 45);
    Duration D2(1, 45, 15);
    Duration D3;

    D3 = D1 + D2;
    D3.print();

    D3 = D1 + 7800;
    D3.print();

    D3 = 666 + D3;
    D3.print();

    D3 = D1++;
    D1.print();
    D3.print();

    --D2;
    D2.print();

    if (D1 > D2==1) {
        cout << "D1 is greater than D2" << endl;
    }

    if (D1 <= D2==1) {
        cout << "D1 is less than or equal to D2" << endl;
    }

    return 0;
}
