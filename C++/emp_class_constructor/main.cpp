#include <iostream>
#include <string.h>

using namespace std;

class emp{
    int id;
    char name[50];
    int age;
public:
    int getId(){
        return id;

    }
    void setId(int _id){
        id=_id;
    }
    char* getName(){
        return name;

    }
    void setName(char* _name){
        strcpy(name, _name);
    }
    int getAge(){
        return age;

    }
    void setAge(int _age){
        age=_age;
    }
    void printEmp(){
        cout <<endl<<"id is :"<<id<< endl<<"name is: "<<name<<endl<<"age is: "<< age<<endl;

    }
    emp(){
        id=0;
        strcpy(name,"No Name");
        age=30;
    }
     emp(int _id){
        id=_id;
        strcpy(name,"No Name");
        age=30;
    }
    emp(int _id, char _name[]){
        id=_id;
        strcpy(name, _name);
        age=30;
    }
    emp(int _id, char _name[], int _age){
        id=_id;
        strcpy(name,_name);
        age=_age;
    }
    ~emp(){
        cout<<endl<<"Destructor: Object Deleted";
    }

};


int main()
{
    int age,id;
    char name[50];
    emp e1, e2(4),e3(6,"Abdallah"),e4(8,"Mahmoud",35);
    cout<<"Enter id:";
    cin>>id;
    e1.setId(id);
    cout<<"Enter name:";
    cin>>name;
    e1.setName(name);
    cout<<"Enter age:";
    cin>>age;
    e1.setAge(age);

    e1.printEmp();
    e2.printEmp();
    e3.printEmp();
    e4.printEmp();



    return 0;
}
