#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, arr[20], small, pos;
    system("cls");
    printf("\nEnter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\nEnter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i == 0)
        {
            small = arr[0];
        }
        if (small > arr[i])
        {
            small = arr[i];
            pos = i;
        }
    }
    printf("\n The smallest element is : %d", small);
    printf("\n The position of the smallest element in the array is : %d", pos);
    return 0;
}