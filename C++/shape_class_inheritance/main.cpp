#include <iostream>

using namespace std;

class Shape{
protected:
    int dim1;
    int dim2;
public:
    Shape(){
        dim1=dim2=1;
    }
    Shape(int _dim1){
        dim1=_dim1;
        dim2=_dim1;
    }
    Shape(int _dim1,int _dim2){
        dim1=_dim1;
        dim2=_dim2;
    }

     virtual void setDim1(int _dim1){
        dim1=_dim1;
    }
    virtual void setDim2(int _dim2){
        dim2=_dim2;
    }
    int getDim1(){
        return dim1;
    }
    int getDim2(){
        return dim2;
    }

    virtual float calcArea()=0;

};

class rectangle: public Shape{
public:
    rectangle(int _dim1=1, int _dim2=1): Shape(_dim1,_dim2){}

    float calcArea(){
        return dim1*dim2;
    }


};

class triangle: public Shape{
public:
    triangle(int _dim1=1, int _dim2=1): Shape(_dim1,_dim2){}

    float calcArea(){
        return 0.5*dim1*dim2;
    }


};

class circle: public Shape{
public:
    circle(int _dim1=1): Shape(_dim1){}

    void setDim1(int _dim1){
        dim1=dim2=_dim1;
    }

    void setDim2(int _dim2){
        dim2=dim1=_dim2;
    }

    float calcArea(){
        return 3.14*dim1*dim2;
    }


};

class square: public rectangle{
public:
     square(int _dim1 = 1): rectangle(_dim1, _dim1) {}

    void setDim1(int _dim1){
        dim1=dim2=_dim1;
    }

    void setDim2(int _dim2){
        dim2=dim1=_dim2;
    }
};

float SumOfAreas(Shape* s[]){
    float sum=0;
    for(int i=0;i<sizeof(*s);i++){
        sum += s[i]->calcArea();
    }

    return sum;
}

float CalculateArea(Shape* s){
    float area= s->calcArea();
    return area;
}



int main()
{

    rectangle r(10,20);
    triangle t(10,20);
    circle c(7);
    square q(5);

    Shape* s[4]={&r, &t, &c};
    s[3]=&q;
    cout<<"Shape Area: "<<CalculateArea(&q);
    cout<<endl;
    cout<<"Sum Of Areas: "<<SumOfAreas(s);

    return 0;
}
