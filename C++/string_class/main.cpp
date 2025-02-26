#include <iostream>
#include <cstring>

using namespace std;

class String {
    int size;
    char* arr;

public:
    String() {
        size = 10;
        arr = new char[size];
        arr[0] = '\0';
    }

    String(int _size) {
        size = _size;
        arr = new char[size];
        arr[0] = '\0';
    }

    String(const char _arr[]) {
        size = strlen(_arr) + 10;
        arr = new char[size];
        strcpy(arr, _arr);
    }

    int getSize() const {
        return size;
    }

    const char* getarr() const {
        return arr;
    }

    void setSize(int _size) {
        size = _size;
    }

    void setarr(const char _arr[]) {
        int newLength = strlen(_arr);
        if (newLength >= size) {
            delete[] arr;
            size = newLength + 1;
            arr = new char[size];
        }
        strcpy(arr, _arr);
    }

    // Copy constructor
    String(const String& s) {
        size = s.size;
        arr = new char[size];
        strcpy(arr, s.arr);
    }

    // = operator overloading
    String& operator=(const String& s) {
        if (this == &s)
            return *this;

        delete[] arr;
        size = s.size;
        arr = new char[size];
        strcpy(arr, s.arr);

        return *this;
    }

    // + operator overloading
    String operator+(const String& s) const {
        String newString(strlen(arr) + strlen(s.arr) + 1);
        strcpy(newString.arr, arr);
        strcat(newString.arr," ");
        strcat(newString.arr, s.arr);
        return newString;
    }

    // Destructor
    ~String() {
        cout << "\ndestructor";
        delete[] arr;
    }

    friend void ViewContent(const String& s);
};

void ViewContent(const String& s) {
    cout <<endl<< "String is: " << s.arr << endl;
}

int main() {
    String s1, s2(10), s3("Abdallah");

    s1 = s3;
    ViewContent(s1);

    s2 = s1 + s3;
    ViewContent(s2);

    return 0;
}
