#include <iostream>
#include <string>
using namespace std;

class publication {
    char title[50];
    float price;

public:
    virtual void getdata() {
        cout << "Enter title: ";
        cin>>title;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

};

class book : public publication {
    int page_count;

public:
    void getdata(){
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }

    void putdata(){
        publication::putdata();
        cout << "Page count: " << page_count << endl;
    }
};

class tape : public publication {
    float playing_time;

public:
    void getdata(){
        publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playing_time;
    }

    void putdata(){
        publication::putdata();
        cout << "Playing time: " << playing_time << " minutes" << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of publications: ";
    cin >> n;

    publication* pubarr[n];

    for (int i = 0; i < n; ++i) {
        int choice;
        cout << "Enter 1 for Book, 2 for Tape: ";
        cin >> choice;

        if (choice == 1) {
            pubarr[i] = new book;
        } else if (choice == 2) {
            pubarr[i] = new tape;
        } else {
            cout << "Invalid choice, exiting!" << endl;
            return 1;
        }

        pubarr[i]->getdata();
    }

    cout << "\nDisplaying all publications:\n";
    for (int i = 0; i < n; ++i) {
        pubarr[i]->putdata();
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete pubarr[i];
    }

    return 0;
}
