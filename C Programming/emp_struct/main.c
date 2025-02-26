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
    printf("enter emp id: ");
    scanf("%d", &(e1.id));
    printf("enter emp name: ");
    scanf("%s", e1.name);
    printf("enter emp age: ");
    scanf("%d", &(e1.age));

    printf("emp info is: \nid : %d\nname is %s\nage is %d",e1.id,e1.name,e1.age);
    return 0;
}
