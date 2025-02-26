#include <iostream>

using namespace std;

class complexNum{

    int real;
    int img;

public:
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



};

void printcomplex(complexNum comp1){
    if(comp1.getImg() > 0)
        cout<<"the complex num is: "<<comp1.getReal()<<"+"<<comp1.getImg()<<"i";
    else if(comp1.getImg() == 0)
        cout<<"the complex num is: "<<comp1.getReal();
    else if(comp1.getImg() < 0)
        cout<<"the complex num is: "<<comp1.getReal()<<comp1.getImg()<<"i";

}

int main()
{
    int real,img;
    complexNum comp1;
    cout<<"Enter real: ";
    cin>>real;
    comp1.setReal(real);
    cout << "Enter img:";
    cin>>img;
    comp1.setImg(img);

    printcomplex(comp1);

    return 0;
}
