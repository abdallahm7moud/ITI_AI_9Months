#include <iostream>

using namespace std;

void swap(int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
}

int main()
{
    int a,b;
    cout<<"Enter first num: ";
    cin>>a;
    cout<<"Enter second num: ";
    cin>>b;
    swap(a,b);
    cout<<"num after swap is :"<<endl;
    cout<<"first num : "<<a<<endl<<"second num :"<<b;

    return 0;
}
