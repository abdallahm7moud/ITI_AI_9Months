#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("Plz enter num1 : \n ");
    scanf("%d", &num1);
    printf("Plz enter num2 : \n ");
    scanf("%d", &num2);
    printf("%d + %d = %d\n",num1, num2, num1+num2);
    printf("%d - %d = %d\n",num1, num2, num1-num2);
    printf("%d * %d = %d\n",num1, num2, num1*num2);
    return 0;
}
