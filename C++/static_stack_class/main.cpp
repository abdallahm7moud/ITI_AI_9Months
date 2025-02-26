#include <iostream>

using namespace std;

class Stack {
    int arr[5];
    int sizeOfStack;
    int tos;

public:

    Stack(){
        tos=-1;
        sizeOfStack=5;
    }


    void push(int d){
        if(tos< sizeOfStack-1){
            tos++;
            arr[tos]=d;
        }
        else
            cout<<"\n stack is Full";
    }

    int pop(int& d){

        if(tos!=-1){
            d= arr[tos];
            tos--;
            return 1;

            }
        else
        {
            cout<<"\n stack is empty";
            return 0;
        }

    }

    ~Stack(){
        cout<<"destructor";

    }



};

myfun(Stack s){

    int x;
    s.push(30);
    s.pop(x);
    cout<<endl<<x<<endl;

}

int main()
{
    Stack s1;

    s1.push(10);
    s1.push(20);

    myfun(s1);
    int x;
    s1.pop(x);
    cout<<endl<<x<<endl;

    return 0;
}
