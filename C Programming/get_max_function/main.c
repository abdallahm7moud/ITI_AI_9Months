#include <stdio.h>
#include <stdlib.h>
int get_max(int x,int y);

int main()
{
    int x,y,z;
    printf("enter first num: ");
    scanf("%d",&x);
    printf("enter second num: ");
    scanf("%d",&y);
    z=get_max(x,y);
    printf("max number is: %d", z);
    return 0;
}
int get_max(int x,int y)
{

    return x>y?x:y;

}
