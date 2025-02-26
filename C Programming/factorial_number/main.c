#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, fact=1;
    printf("plz enter the num: ");
    scanf("%d", &num);
    for(i=1;i<=num;i++){
           fact *= i;
    }
    printf("factorial = %d", fact);
    return 0;
}
