#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5]={0};
    int *ptr=arr;
    int i;
    for(i=0;i<5;i++){
        printf("enter %d num : ", i+1);
        scanf("%d", ptr+i);
    }
    printf("numbers is: ");
    for(i=0;i<5;i++){
        printf("%d,", *(ptr+i));
    }

    return 0;
}
