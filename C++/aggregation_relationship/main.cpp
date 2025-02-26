#include <iostream>

using namespace std;

class Point{

    int x;
    int y;

public:

    Point(){
        x=y=0;
        cout<<"\nPoint CTOR";
    }
    Point(int _x){

        x=y=_x;
        cout<<"\nPoint CTOR";
    }
    Point(int _x, int _y){
        x=_x;
        y=_y;
        cout<<"\nPoint CTOR";
    }

    void setX(int _x){
        x=_x;
    }
    void setY(int _y){
        y=_y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }

    void print(){
        cout<<"\n("<<x<<","<<y<<")";

    }

    ~Point(){
    cout<<"\npoint destructor";

    }



};

class Rect{

    Point* UL;
    Point* LR;

public:
    Rect(){

        cout<<"\nRect CTOR";
    }
    //Rect(int* x1, int* y1, int* x2, int* y2):UL(x1,y2),LR(x2,y2){}
    Rect(Point* _UL, Point* _LR) : UL(_UL), LR(_LR)
    {
        cout<<"\nRect CTOR";

    }

    Point* getUL(){
        return UL;
    }
    Point* getLR(){
        return LR;
    }

    void setUL(Point* _ul){
        UL=_ul;

    }
    void setUL(int x, int y){

        UL->setX(x);
        UL->setY(y);
    }
    void setLR(Point* _lr){
        LR=_lr;

    }
    void setLR(int x, int y){

        LR->setX(x);
        LR->setY(y);
    }

    void print(){

        UL->print();
        LR->print();
    }

    ~Rect(){
        cout<<"\nRect destructor";
    }

};

class Circle{

    int radius;
    Point* center;

public:
    Circle(){

        cout<<"\nCircle CTOR";
    }
    /*
    Circle(int _radius,int* x, int* y):center(x,y)
    {
        radius=_radius;
    }
    */

    Circle(int _radius, Point* _center):center(_center)
    {
        radius=_radius;
        cout<<"\nCircle CTOR";

    }


    int getRadius(){
        return radius;
    }
    Point* getcenter(){
        return center;
    }

    void setRadius(int _radius){
        radius=_radius;

    }
    void setCenter(int x, int y){

        center->setX(x);
        center->setY(y);
    }
    void setCenter(Point* _center){
        center=_center;

    }

    void print(){

        cout<<"\nRadius is: "<<radius;
        center->print();
    }

    ~Circle(){
        cout<<"\nCircle destructor";
    }

};

int main()
{
    //Rect r(&1,&2,&3,&4);
    //Circle c(10,&20,&30);

    Point ul(1, 2);
    Point lr(3, 4);
    Point center(20, 30);

    Rect r(&ul, &lr);
    Circle c(10, &center);


    r.print();
    c.print();


    return 0;
}
