#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, f=0;
    printf("plz enter the number: ");
    scanf("%d", &num);
    if(num < 2){
        f = 1;
    }
    for(i=2;i<num;i++){
        if(num%i == 0){
            f=1;
            break;
        }
    }
    if(f)
        printf("the number is not prime");
    else
        printf("the number is prime");
    return 0;
}
