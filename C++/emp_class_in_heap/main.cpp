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

};

int main()
{
    int age,id;
    char name[50];
    emp* ptr = new emp;
    cout<<"Enter id:";
    cin>>id;
    ptr->setId(id);
    cout<<"Enter name:";
    cin>>name;
    ptr->setName(name);
    cout<<"Enter age:";
    cin>>age;
    ptr->setAge(age);
    cout << "id is :"<<ptr->getId()<< endl<<"name is: "<<ptr->getName()<<endl<<"age is: "<< ptr->getAge();
    return 0;
}
