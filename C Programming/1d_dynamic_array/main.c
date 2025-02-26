#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,i;
    printf("Enter the size of array: ");
    scanf("%d",&size);

    int* ptr=(int*)malloc(size*sizeof(int));
    if(ptr!=NULL){
        for(i=0;i<size;i++){
            printf("enter %d num: ",i+1);
            scanf("%d", &ptr[i]);
        }
        printf("array numbers is: [");
        for(i=0;i<size;i++){
            printf("%d,", ptr[i]);

        }
        printf("]");

        free(ptr);

    }

    return 0;
}
