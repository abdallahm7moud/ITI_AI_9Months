#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;
    char op;
    printf("plz enter the operation: ");
    scanf("%c", &op);
    printf("plz enter the first num: ");
    scanf("%d", &n1);
    printf("plz enter the second num: ");
    scanf("%d", &n2);
    switch(op){
        case '+':
            printf("%d + %d = %d",n1,n2,n1+n2);
            break;
        case '-':
            printf("%d - %d = %d",n1,n2,n1-n2);
            break;
        case '*':
            printf("%d * %d = %d",n1,n2,n1*n2);
            break;
        case '/':
            printf("%d / %d = %d",n1,n2,n1/n2);
            break;
        default:
            printf("Invalid operation");
            break;
    }
    return 0;
}
