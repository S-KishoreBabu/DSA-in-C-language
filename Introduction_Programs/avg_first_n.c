// completed 
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, sum = 0, i = 0;
    float result;
    system("cls");
    printf("Enter the value of n : ");
    scanf("%d", &n);
    do
    {
        sum += i;
        i++;
    } while (i <= n);
    result = (float)sum / n;
    printf("\n The Average of first %d numbers = %.2lf ", n, result);
    return 0;
}