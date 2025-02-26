#include <stdio.h>
#include <stdlib.h>
#define size 5
void scan_array(int arr[],int n);
void array_sum(int arr[],int n);
void print_array(int arr[],int n);



int main()
{
    int arr[size];

    scan_array(arr,size);
    array_sum(arr,size);
    print_array(arr,size);

    return 0;
}
void scan_array(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++){
        printf("print %d num: ", i+1);
        scanf("%d", &arr[i]);

    }

}
void array_sum(int arr[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++){
        sum += arr[i];
    }
    printf("\narray sum is= %d", sum);

}
void print_array(int arr[],int n)
{
    int i;
    printf("\narray is: ");
    for(i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
}
