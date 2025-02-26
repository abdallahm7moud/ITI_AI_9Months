#include <iostream>
#include <string.h>

using namespace std;

struct emp{
private:
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
    emp e1;
    cout<<"Enter id:";
    cin>>id;
    e1.setId(id);
    cout<<"Enter name:";
    cin>>name;
    e1.setName(name);
    cout<<"Enter age:";
    cin>>age;
    e1.setAge(age);
    cout << "id is :"<<e1.getId()<< endl<<"name is: "<<e1.getName()<<endl<<"age is: "<< e1.getAge();
    return 0;
}
