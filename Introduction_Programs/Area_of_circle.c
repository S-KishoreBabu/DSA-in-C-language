// Completed 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float r = 7;
    double area;
    system("cls");
    printf("\n Enter Radius : ");
    scanf("%f", &r);
    area = (r * r) * 3.14;
    printf("\n Area = %.2lf", area);
    return 0;
}