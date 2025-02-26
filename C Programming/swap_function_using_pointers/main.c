#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("enter x num: ");
    scanf("%d", &x);
    printf("enter y num: ");
    scanf("%d", &y);
    swap(&x, &y);
    printf("x = %d  y = %d ",x,y);

    return 0;
}
void swap(int* x,int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y =temp;

}
