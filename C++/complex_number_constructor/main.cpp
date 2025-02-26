#include <iostream>

using namespace std;

class complexNum{

    int real;
    int img;

public:
    complexNum(){
        real=img=0;
    }
    complexNum(int _real){
        real=_real;
        img=0;
    }
    complexNum(int _real, int _img){
        real=_real;
        img=_img;
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
    else if(img == 0)
        cout<<"complex num is: "<<real<<endl;
    else if(img < 0)
        cout<<"complex num is: "<<real<<img<<"i"<<endl;

    }
     //member function
    complexNum AddComplex(complexNum c){

    complexNum res;
    res.real=real+c.real;
    res.img=img+c.img;
    return res;

    }

};
 //stand alone function
complexNum AddComplex(complexNum c1, complexNum c2){

    complexNum res;
    res.setReal(c1.getReal()+c2.getReal());
    res.setImg(c1.getImg()+c2.getImg());
    return res;
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
    c1.printcomplex();
    c2.printcomplex();
    c3.printcomplex();

    complexNum z = c1.AddComplex(c3);
    cout<<endl<<"Sum of ";
    z.printcomplex();

    return 0;
}
