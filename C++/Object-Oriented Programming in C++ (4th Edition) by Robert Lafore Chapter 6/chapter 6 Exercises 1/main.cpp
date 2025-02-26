#include <iostream>

using namespace std;

class Number{

    int num1;
    int num2;

public:

    Number(int _num1=0,int _num2=0){
        num1=_num1;
        num2=_num2;

    }

    void set_num1(int _num1){
        num1=_num1;

    }
    void set_num2(int _num2){
        num2=_num2;

    }
    int get_num1(){
        return num1;

    }
    int get_num2(){
        return num2;

    }


    void Display(){
        cout<<"Number1: "<<num1<<endl;
        cout<<"Number2: "<<num2<<endl;

    }

    int add_num(){
        int res;
        res=num1+num2;
        return res;

    }


};

int main()
{
    Number n1, n2(5), n3(4,5);
    n1.Display();
    n2.Display();
    n3.Display();

    cout<<n1.add_num();
    cout<<n2.add_num();
    cout<<n3.add_num();

    return 0;
}
