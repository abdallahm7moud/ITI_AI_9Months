#include <iostream>

using namespace std;

class SerialNumberedObject {
    static int objectCount;
    int serialNumber;
public:
    SerialNumberedObject() {
        objectCount++;
        serialNumber = objectCount;
    }

    void printSerialNumber(){
        cout << "I am object number " << serialNumber <<endl;
    }
};

int SerialNumberedObject::objectCount = 0;

int main() {
    SerialNumberedObject obj1;
    SerialNumberedObject obj2;
    SerialNumberedObject obj3;

    obj1.printSerialNumber();
    obj2.printSerialNumber();
    obj3.printSerialNumber();

    return 0;
}
