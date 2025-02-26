#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{

    char ch;

    do{
        printf("New\nDispaly\nExit\n");
        _flushall();
        printf("\nplz enter the item: ");
        scanf("%c", &ch);
        system("cls");
        switch(ch){
            case'n':
                printf("U selected the new item");
                break;
            case'd':
                printf("U selected the display item");
                break;
            case'e':
                printf("U selected the exit item");
                break;
            default:
                printf("Invalid item");
                break;
    }
        Sleep(3000);
        system("cls");
    }
    while(ch != 'e');
    return 0;
}
