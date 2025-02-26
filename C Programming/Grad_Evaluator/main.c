#include <stdio.h>
#include <stdlib.h>

int main()
{
    int degree;
    printf("plz enter your degree: ");
    scanf("%d", &degree);
    if(degree >= 85)
        printf("Excellent grade");
    else if(degree >= 75)
        printf("V.Good grade");
    else if(degree >= 65)
        printf("Good grade");
    else if(degree >= 60)
        printf("acceptable grade");
    else
        printf("Fail");
    return 0;
}
