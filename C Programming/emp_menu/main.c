#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct emp {
    int id;
    char names[30];
    int age;

};

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
    int size;
    int i, n=0, flag=0,index,id;
    char name[30];

    printf("Enter the number of emp: ");
    scanf("%d",&size);

    struct emp* ptr1=(struct emp*)malloc(size*sizeof(struct emp));
    int* ptr2=(int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++){
        ptr2[i]=-1;
    }
    if(ptr1!=NULL && ptr2!=NULL){
        char names[5][20] = {"New", "Display All", "Display by id","Display by names","Exit"};

        do{
            system("cls");
            for (i=0;i<5; i++) {
                    gotoxy(1, 1 + i);
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
                            if(n>4)
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
                        printf("Enter the index you want to store in: ");
                        scanf("%d",&index);
                        system("cls");
                        printf("emp id: ");
                        scanf("%d",&ptr1[index].id);
                        printf("emp name: ");
                        scanf("%s",&ptr1[index].names);
                        printf("emp age: ");
                        scanf("%d",&ptr1[index].age);
                        ptr2[index]=ptr1[index].id;

                        ch=_getch();
                        }
                    else if (n == 1){
                        for(i=0;i<size;i++){
                                if(ptr2[i]!=-1){
                                    printf("\nemp info %d :\n", i+1);
                                    printf("id is %d\nname is %s\nage is %d\n",ptr1[i].id,ptr1[i].names,ptr1[i].age);
                                }
                        }
                        ch=_getch();
                    }
                    else if(n == 2){
                        printf("Enter the employee ID you want to search for: ");
                        scanf("%d",&id);
                        for(i=0;i<size;i++){
                            if(id==ptr1[i].id){
                                printf("id is %d\nname is %s\nage is %d\n",ptr1[i].id,ptr1[i].names,ptr1[i].age);
                        }
                        }
                        ch=_getch();
                    }

                    else if(n == 3){
                        printf("Enter the employee name you want to search for: ");
                        scanf("%s",&name);
                        for(i=0;i<size;i++){
                            if(strcmp(name,ptr1[i].names)==0){
                                printf("id is %d\nname is %s\nage is %d\n",ptr1[i].id,ptr1[i].names,ptr1[i].age);
                                break;
                        }
                            }
                        ch=_getch();
                    }
                    else if (n == 4){
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

        free(ptr1);
        free(ptr2);

    }

    return 0;
}
