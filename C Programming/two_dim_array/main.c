#include <stdio.h>
#include <stdlib.h>
#define row 3
#define col 4

int main()
{
    int arr[row][col];
    int i, j;

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("plz enter %d row %d col: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\narray is: \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }

    int sum[row]={0};
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
            sum[i] += arr[i][j];
    }

    printf("\nsum is: ");
    for(i=0;i<row;i++){
        printf("%d,", sum[i]);
    }


    return 0;
}
