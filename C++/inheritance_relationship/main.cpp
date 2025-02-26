#include <iostream>
#include <string.h>

using namespace std;

class Person{
protected:
    int id;
    char name[20];
    int age;
public:
    Person(int _id=0, char* _name="No Name",int _age=0){
        id=_id;
        strcpy(name,_name);
        age=_age;
        cout<<endl<<"person constructor";
    }

    void setId(int _id){
        id=_id;
    }
    void setName(char _name[]){
        strcpy(name,_name);
    }
    void setAge(int _age){
        age=_age;
    }
    int getId(){
        return id;
    }
    char* getName(){
        return name;
    }
    int getAge(){
        return age;
    }

    void print(){
        cout<<endl<<id<<":"<<name<<":"<<age;
    }

    ~Person(){
        cout<<endl<<"person destructor";
    }
};

class emp: public Person
{
    int salary;

public:
    emp(int _id=0, char* _name="No Name",int _age=0,int _salary=9000): Person(_id, _name, _age)
    {
        salary=_salary;
        cout<<endl<<"emp constructor";
    }

    void setSalary(int _salary){
        salary=_salary;
    }
    int getSalary(){
        return salary;
    }

    void print(){
        Person::print();
        cout<<endl<<"emp salary is : "<<salary;
    }

    ~emp(){
        cout<<endl<<"emp destructor";
    }
};

class student: public Person
{
    float gpa;

public:
    student(int _id=0, char* _name="No Name",int _age=0,float _gpa=2.5):Person(_id, _name, _age)
    {
        gpa=_gpa;
        cout<<endl<<"student constructor";
    }

    void setGPA(int _gpa){
        gpa=_gpa;
    }
    int getGPA(){
        return gpa;
    }

    void print(){
        Person::print();
        cout<<endl<<"student GPA is : "<<gpa;
    }

    ~student(){
        cout<<endl<<"student destructor";
    }
};

void print(Person p){
    p.print();
}

int main()
{
    Person p;
    emp e(1,"Mahmoud",50,15000);
    e.print();
    student s(2,"Abdallah",22,3.5);
    s.print();

    /*
    print(p);
    print(e);
    print(s);
    */

    return 0;
}
