// Completed

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    system("cls");
    printf("\nEnter any Integer number : ");
    scanf("%d", &n);
    if ((n % 2) == 0)
    {
        printf(" %d is Even ", n);
    }
    else
    {
        printf(" %d is Odd ", n);
    }
    return 0;
}