#include <stdio.h>
#include <stdlib.h>
int factorial(int x);

int main()
{
    int f,fact;
    printf("enter the number: ");
    scanf("%d",&f);
    fact=factorial(f);
    printf("factorial %d= %d",f,fact);

    return 0;
}
int factorial(int x)
{
    int i,f=1;
    for(i=1;i<=x;i++){
        f *= i;
    }
    return f;

}
