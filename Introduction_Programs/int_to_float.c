#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i_num;
    float f_num;
    system("cls");
    printf("\nEnter an integer Number : ");
    scanf("%d", &i_num);
    f_num = (float)i_num;
    printf("\nThe floating point variant of %d is = %f", i_num, f_num);
    return 0;
}