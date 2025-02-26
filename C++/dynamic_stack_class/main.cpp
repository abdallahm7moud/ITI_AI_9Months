#include <iostream>

using namespace std;

class Stack {
    int* arr;
    int size;
    int tos;

public:

    Stack(){
        tos=-1;
        size=5;
        arr=new int[size];
    }

    Stack(int _size){
        size=_size;
        tos=-1;
        arr=new int[size];


    }


    void push(int d){
        if(tos< size-1){
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
    // const -> no edit
    Stack(const Stack& s){
        tos=s.tos;
        size =s.size;
        arr= new int[size];
        for(int i=0;i<=tos;i++){
            arr[i]= s.arr[i];
        }

    }




    ~Stack(){
        cout<<"\ndestructor";
        delete[] arr;

    }



};

myfun(Stack s){

    int x;
    s.push(30);
    s.pop(x);
    cout<<endl<<x;

}

int main()
{
    Stack s1, s2(3);

    s2.push(10);
    s2.push(20);
    myfun(s2);
    int x;
    s2.pop(x);
    cout<<endl<<x;
    s2.pop(x);

    return 0;
}
