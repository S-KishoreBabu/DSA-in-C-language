#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i, sum = 0;
    system("cls");
    printf("Enter a starting Number : ");
    scanf("%d", &m);
    printf("Enter the last Number :");
    scanf("%d", &n);
    i = m;
    while (i <= n)
    {
        sum += i;
        i++;
    }
    printf("\n The sum of the numbers from %d to %d = %d", m, n, sum);
    return 0;
}