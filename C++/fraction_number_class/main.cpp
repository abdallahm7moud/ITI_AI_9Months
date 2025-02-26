#include <iostream>

using namespace std;

class fraction_number{
    int num;
    int den;

public:

    fraction_number(){
        num=0;
        den=1;

    }

    fraction_number(int _num){
        num=_num;
        den=1;

    }
    fraction_number(int _num, int _den){
        num=_num;
        den=_den;

    }

    void SetNum(int _num){

        num=_num;
    }

    void SetDen(int _den){

        den=_den;
    }

    int getNum(){
        return num;
    }

    int getNDen(){
        return den;
    }

    void print(){
        if(den==1)
            cout<<num;
        else if(den==0)
            cout<<"erorr";
        else
            cout<<num<<"/"<<den;
    }
    void simplify() {
        int a=num,b=den;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        num /= a;
        den /= a;
        if(den==1)
            cout<<num;
        else if(den==0)
            cout<<"erorr";
        else
            cout<<num<<"/"<<den;
    }

     // Overloaded operators
     fraction_number operator+(fraction_number& f){
        fraction_number res;
        res.num = num * f.den + f.num * den;
        res.den = den * f.den;

        return res;

    }

    fraction_number operator-(const fraction_number &f){
        return fraction_number(num * f.den - f.num * den, den * f.den);
    }

    fraction_number operator*(const fraction_number &f){
        return fraction_number(num * f.num, den * f.den);
    }

    fraction_number operator/(const fraction_number &f){
        return fraction_number(num * f.den, den * f.num);
    }

    fraction_number operator++() { // Prefix increment
        num += den;
        return *this;
    }

    fraction_number operator++(int) { // Postfix increment
        fraction_number temp= *this;
        num += den;
        return temp;
    }

    fraction_number operator--() { // Prefix decrement
        num -= den;
        return *this;
    }

    fraction_number operator--(int) { // Postfix decrement
        fraction_number temp=*this;
        num -= den;
        return temp;
    }

    // Cast to float
    explicit operator float(){
        return (float)(num) / den;
    }

};

int main()
{
     fraction_number f1(2, 3), f2(3, 4), f3, f4(2,4);

    cout << "simplify: ";
    f4.simplify();
    cout<<endl;

    f3 = f1 + f2;
    cout << "Sum: ";
    f3.print();
    cout << endl;

    f3 = f1 - f2;
    cout << "Difference: ";
    f3.print();
    cout << endl;

    f3 = f1 * f2;
    cout << "Product: ";
    f3.print();
    cout << endl;

    f3 = f1 / f2;
    cout << "Quotient: ";
    f3.print();
    cout << endl;

    ++f1;
    cout << "After prefix increment f1: ";
    f1.print();
    cout << endl;

    f1++;
    cout << "After postfix increment f1: ";
    f1.print();
    cout << endl;

    --f1;
    cout << "After prefix decrement f1: ";
    f1.print();
    cout << endl;

    f1--;
    cout << "After postfix decrement f1: ";
    f1.print();
    cout << endl;

    float floatValue = (float)f4;
    cout << "f1 as float: " << floatValue << endl;

    return 0;
}
