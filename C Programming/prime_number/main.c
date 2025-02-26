#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, i, j,f;
    printf("plz enter the number: ");
    scanf("%d", &num);

    printf("the prime number : ");
    for(i=num;i>=2;i--){
        f=0;
        for(j=2;j<i;j++){
            if(i%j == 0)
                f=1;
        }
        if(f==0)
            printf("%d,", i);

    }

    return 0;
}
