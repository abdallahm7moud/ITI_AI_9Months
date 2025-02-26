#include <stdio.h>
#include <stdlib.h>
#define size 5

int main()
{
    int arr[size];
    int i;

    for(i=0;i<size;i++){
    printf("plz enter %d num: ", i+1);
    scanf("%d", &arr[i]);
    }

    printf("\narray is: ");
    for(i=0;i<size;i++){
        printf("%d,", arr[i]);
    }

    int sum=0,max=arr[0], min=arr[0];
    for(i=0;i<size;i++){
        sum += arr[i];
    }
    printf("\nsum is: %d\n", sum);

    for(i=0;i<size;i++){
        if(max < arr[i])
            max = arr[i];
    }
    printf("max is: %d\n", max);

    for(i=0;i<size;i++){
        if(min > arr[i])
            min = arr[i];
    }
    printf("min is: %d\n", min);


    return 0;
}
