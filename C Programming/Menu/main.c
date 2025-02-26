#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }


void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}


int main()
{
    char names[3][10] = {"new", "display", "exit"};
    int i, n=0, flag=0;

    do{
        system("cls");
        for (i=0;i<3; i++) {
                gotoxy(10, 10 + i);
                if (i == n)
                    textattr(0x04);
                else
                    textattr(0x07);

                _cprintf("%s", names[i]);
            }


        char ch = _getch();
        switch(ch){
            case -32:
                ch = _getch();
                switch(ch){
                    case 80:
                        n++;
                        if(n>2)
                            n=0;
                        break;
                    case 72:
                        n--;
                        if(n<0)
                            n=2;
                        break;
                }
                break;
            case 13:
                system("cls");
                if (n == 0){
                    printf("new selected\n");
                    ch=_getch();
                    }
                else if (n == 1){
                    printf("display selected\n");
                    ch=_getch();
                    }
                else if (n == 2){
                    printf("exit selected\n");
                    //ch=_getch();
                    flag=1;
                    }
                break;
            case 27:
                flag=1;
                break;

            }

    }while(flag==0);

    return 0;
}
