#include <iostream>
#include <string.h>

using namespace std;

class Publication {
    char title[50];
    float price;
public:

    Publication(){
        strcpy(title, "No Title");
        price=0;
    }

    Publication(char _title[],float _price){
        strcpy(title, _title);
        price=_price;
    }

    void getdata() {
        cout << "Enter title: ";
        cin>>title;
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata(){
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
    int pageCount;

public:
    Book(int _pageCount=0){
        pageCount=_pageCount;

    }

    void getdata() {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putdata(){
        Publication::putdata();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
    float playingTime;

public:
    Tape(float _playingTime=0){
        playingTime=_playingTime;
    }

    void getdata() {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void putdata(){
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for the book:\n";
    book.getdata();
    cout << "\nDetails of the book:\n";
    book.putdata();

    cout << "\nEnter details for the tape:\n";
    tape.getdata();
    cout << "\nDetails of the tape:\n";
    tape.putdata();

    return 0;
}
