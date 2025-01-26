#include <stdio.h>
#include <stdlib.h>
void add(int *, int *, int *);

void add(int *a, int *b, int *tot)
{
    *tot = *a + *b;
}
int main()
{
    int num1, num2, total;
    system("cls");
    printf("Enter value for num1 : ");
    scanf("%d", &num1);
    printf("Enter value for num2 : ");
    scanf("%d", &num2);
    add(&num1, &num2, &total);
    printf("\n sum of %d and %d is %d", num1, num2, total);
    return 0;
}