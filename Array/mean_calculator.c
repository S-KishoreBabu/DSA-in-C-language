#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20], i, n, sum = 0;
    float mean;
    system("cls");
    printf("Enter the Number of elements in the array : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }
    mean = (float)sum / n;
    printf("\n The mean of the array elements = %.2lf", mean);

    return 0;
}