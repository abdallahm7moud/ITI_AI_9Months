#include <stdio.h>
#include <stdlib.h>

struct emp{
    int id;
    char names[30];
    int age;

};

int main()
{
    int size,i;
    printf("Enter the number of emp: ");
    scanf("%d",&size);

    struct emp* ptr=(struct emp*)malloc(size*sizeof(struct emp));
    if(ptr!=NULL){
        for(i=0;i<size;i++){
            printf("enter emp id %d: ",i+1);
            scanf("%d",&ptr[i].id);
            printf("enter emp name %d: ",i+1);
            scanf("%s",&ptr[i].names);
            printf("enter emp age %d: ",i+1);
            scanf("%d",&ptr[i].age);
        }
        for(i=0;i<size;i++){
            printf("emp info %d :\n", i+1);
            printf("id is %d\nname is %s\nage is %d\n",ptr[i].id,ptr[i].names,ptr[i].age);

        }

        free(ptr);
    }
    return 0;
}
