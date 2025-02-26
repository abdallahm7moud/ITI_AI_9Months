#include <stdio.h>
#include <stdlib.h>
struct emp{
    int id;
    char name[30];
    int age;

};

int main()
{
    struct emp e1;
    struct emp *ptr=&e1;
    printf("enter emp id: ");
    scanf("%d", &(ptr->id));
    printf("enter emp name: ");
    scanf("%s", ptr->name);
    printf("enter emp age: ");
    scanf("%d", &(ptr->age));

    printf("emp info is: \nid : %d\nname is %s\nage is %d",ptr->id,ptr->name,ptr->age);
    return 0;
}
