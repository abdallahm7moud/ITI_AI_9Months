#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no_of_month;
    printf("plz enter the number of month: ");
    scanf("%d", &no_of_month);
    switch(no_of_month){
        case 1:
            printf("number of days is 31");
            break;
        case 2:
             printf("number of days is 29");
             break;
        case 3:
            printf("number of days is 31");
            break;
        case 4:
            printf("number of days is 30");
            break;
        case 5:
            printf("number of days is 31");
            break;
        case 6:
            printf("number of days is 30");
            break;
        case 7:
            printf("number of days is 31");
            break;
        case 8:
            printf("number of days is 31");
            break;
        case 9:
            printf("number of days is 30");
            break;
        case 10:
            printf("number of days is 31");
            break;
        case 11:
            printf("number of days is 30");
            break;
        case 12:
             printf("number of days is 31");
             break;
        default:
             printf("Invalid month");
             break;
    }
    return 0;
}
