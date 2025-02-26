#include <stdio.h>
#include <stdlib.h>

struct complexNum{
    int real;
    int complex;

};

int main()
{
    struct complexNum comp1;
    printf("enter the real value: ");
    scanf("%d",&(comp1.real));
    printf("enter the complex value: ");
    scanf("%d",&(comp1.complex));

    printf("complex number is:%d + %di",comp1.real,comp1.complex);

    return 0;
}
