#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fname[10], lname[10], fullname[20];

    printf("Enter first name: ");
    scanf("%s", fname);
    printf("Enter last name: ");
    scanf("%s", lname);

    strcpy(fullname, fname);
    strcat(fullname, " ");
    strcat(fullname, lname);

    printf("Full name is: %s", fullname);

    return 0;
}
