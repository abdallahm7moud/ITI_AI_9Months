#include <stdio.h>
#include <stdlib.h>
#define size 2
struct emp{
    int id;
    char names[30];
    int age;


};
int main()
{
    struct emp arr[size];
    int i;
    for(i=0;i<size;i++){
        printf("emp %d enter id: ",i+1);
        scanf("%d", &arr[i].id);
        printf("emp %d enter name: ", i+1);
        scanf("%s", arr[i].names);
        printf("emp %d enter age: ", i+1);
        scanf("%d", &arr[i].age);

    }

    for(i=0;i<size;i++){
        printf("emp %d:\nid is %d name is %s  age is %d\n",i+1,arr[i].id,arr[i].names,arr[i].age);
    }
    return 0;
}
