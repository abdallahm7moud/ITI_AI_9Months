#include <iostream>

using namespace std;

class complexNum{

    int real;
    int img;
    static int counter;

public:
    static int getCounter(){
        return counter;
    }

    complexNum(){
        real=img=0;
        counter++;
    }
    complexNum(int _real){
        real=_real;
        img=0;
        counter++;
    }
    complexNum(int _real, int _img){
        real=_real;
        img=_img;
        counter++;

    }

    int getReal(){
        return real;

    }
    void setReal(int _real){
        real=_real;

    }
    int getImg(){
        return img;

    }
    void setImg(int _img){
        img=_img;

    }
    void printcomplex(){
    if(img > 0)
        cout<<"complex num is: "<<real<<"+"<<img<<"i"<<endl;
    else if(img < 0)
        cout<<"complex num is: "<<real<<img<<"i"<<endl;
    else
        cout<<"complex num is: "<<real<<endl;

    }
     //member function
    complexNum AddComplex(complexNum &c){

    complexNum res;
    res.real=real+c.real;
    res.img=img+c.img;
    return res;

    }

    complexNum operator+(complexNum &c){
        complexNum res(real+c.real,img+c.img);
        //res.real=real+c.real;
        //res.img=img+c.img;

        return res;
    }

    complexNum operator+(int x){
        complexNum res(real+x,img);

        return res;
    }


    int operator== (complexNum &c){

        return real==c.real && img == c.img;
    }


    int operator!= (complexNum &c){

        return !(*this==c);
    }


    explicit operator int(){

        return real;

    }

    complexNum operator++(){  //prefix

        real=real+1;
        return *this;
    }

    complexNum operator++(int){ //postfix

        complexNum temp= *this;
        real=real+1;
        return temp;
    }


    ~complexNum(){
        counter--;
        cout<<"\ndestructor";

    }

    friend complexNum operator+(int x, complexNum c);
    friend ostream& operator<<(ostream& out, complexNum& c);
};

int complexNum::counter=0;

 //stand alone function
 /*
complexNum AddComplex(complexNum c1, complexNum c2){

    complexNum res;
    res.setReal(c1.getReal()+c2.getReal());
    res.setImg(c1.getImg()+c2.getImg());
    return res;
}

complexNum operator+(int x, complexNum c){
    complexNum res(c.real+x,c.img);
    return res;
    }
*/

ostream& operator<<(ostream& out, complexNum& c){
    if(c.img > 0)
        out<<c.real<<"+"<<c.img<<"i"<<endl;
    else if(c.img < 0)
        out<<c.real<<c.img<<"i"<<endl;
    else
        out<<c.real<<endl;

    return out;
    }


int main()
{
    int real,img;
    complexNum c1, c2(5), c3(6,7);
    cout<<"Enter comp1 real: ";
    cin>>real;
    c1.setReal(real);
    cout << "Enter comp1 img:";
    cin>>img;
    c1.setImg(img);

    cout<<endl;
    //c1.printcomplex();
    //c2.printcomplex();
    //c3.printcomplex();

    cout<<c1;
    cout<<c2;
    cout<<c3;

/*
    cout<<endl<<"number of object: "<<complexNum::getCounter();
    complexNum s= c1+4, s1 = c1+c3;
    //complexNum s2= 4+c1;

    int x = (int)c3;
    cout<<endl<<"cast : "<<x<<endl;
    cout<<endl<<"Sum of "<<endl;
    s.printcomplex();
    s1.printcomplex();
    //s2.printcomplex();

    cout<<endl<<"number of object: "<<complexNum::getCounter();
*/
    return 0;
}
