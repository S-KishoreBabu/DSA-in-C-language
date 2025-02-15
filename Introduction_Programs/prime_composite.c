// Completed

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag = 0, i, num;
    system("cls");
    printf("\nEnter an number : ");
    scanf("%d", &num);
    for (i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("\n %d is composite Number", num);
    }
    else
    {
        printf("\n %d is Prime Number", num);
    }
    return 0;
}