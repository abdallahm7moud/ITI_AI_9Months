#include <stdio.h>
#include <stdlib.h>

struct point{
    int x;
    int y;

};

int main()
{
    struct point p1;
    printf("enter the x: ");
    scanf("%d",&(p1.x));
    printf("enter the y: ");
    scanf("%d",&(p1.y));

    printf("point is:(%d,%d)",p1.x,p1.y);

    return 0;
}
