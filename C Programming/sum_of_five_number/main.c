#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum =0;
    int x;
    int i;
    for(i=0;i<5;i++){
        printf("plz enter the 5 number: ");
        scanf("%d", &x);
        sum += x;
    }
    printf("Sum = %d", sum);
    return 0;
}
