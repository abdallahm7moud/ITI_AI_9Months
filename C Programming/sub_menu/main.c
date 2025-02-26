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
    char sub_new[3][10] = {"file", "edit", "tools"};
    char sub_display[3][10] = {"view", "search", "help"};

    int i, n=0, flag=0, h=0, f=0;

    do{
        f=0;
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
                if (n == 0){
                    do{
                        for (i=0;i<3; i++) {
                        gotoxy(20+(8*i), 10);
                        if (i == h)
                            textattr(0x04);
                        else
                            textattr(0x07);

                        _cprintf("%s", sub_new[i]);
                        }

                        char c = _getch();
                        switch(c){
                            case -32:
                                c =_getch();
                                switch(c){
                                    case 77:
                                        h++;
                                        if(h>2)
                                            h=0;
                                        break;
                                    case 75:
                                        h--;
                                        if(h<0)
                                            h=2;
                                        break;

                                }
                                break;
                            case 8:
                                f=1;
                                break;
                        }
                    }while(f==0);

                }
                else if (n == 1){
                    do{
                        for (i=0;i<3; i++) {
                        gotoxy(20+(8*i), 10);
                        if (i == h)
                            textattr(0x04);
                        else
                            textattr(0x07);

                        _cprintf("%s", sub_display[i]);
                        }

                        char c = _getch();
                        switch(c){
                            case -32:
                                c =_getch();
                                switch(c){
                                    case 77:
                                        h++;
                                        if(h>2)
                                            h=0;
                                        break;
                                    case 75:
                                        h--;
                                        if(h<0)
                                            h=2;
                                        break;

                                }
                                break;
                            case 8:
                                f=1;
                                break;
                        }
                    }while(f==0);

                }
                else if (n == 2){
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
