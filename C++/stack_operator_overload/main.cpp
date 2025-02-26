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
    Stack(const Stack& s){   //copy constructor
        tos=s.tos;
        size =s.size;
        arr= new int[size];
        for(int i=0;i<=tos;i++)
            arr[i]= s.arr[i];


    }

    Stack operator=(const Stack& s){  //operator overloading

        tos=s.tos;
        size=s.size;
        delete[] arr;
        arr=new int[size];
        for(int i=0; i<=tos;i++)
            arr[i]=s.arr[i];

        return *this;
    }


    Stack operator+(const Stack& s) {     //operator overloading
        int newSize = size + s.size;
        int* newArr = new int[newSize];

        for (int i = 0; i <= tos; i++) {
            newArr[i] = arr[i];
        }

        for (int i = 0; i <= s.tos; i++) {
            newArr[tos + 1 + i] = s.arr[i];
        }

        delete[] arr;
        arr = newArr;
        size = newSize;
        tos += s.tos + 1;

        return *this;
}



    ~Stack(){
        cout<<"\ndestructor";
        delete[] arr;

    }

    friend void ViewContent(Stack s);

};

void ViewContent(Stack s){

    for(int i=0;i<=s.tos;i++)
        cout<<s.arr[i]<<",";
}


int main()
{
    Stack s1, s2(3), s3, s4;

    s2.push(10);
    s2.push(20);
    s2.push(30);
    s1.push(1);
    s1.push(2);
    s1.push(3);

    s3=s1+s2;

    s4=s3;

    cout<<endl;
    ViewContent(s3);
    cout<<endl;
    ViewContent(s4);

    return 0;
}
