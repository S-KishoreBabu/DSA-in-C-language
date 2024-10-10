//completed - get array values function and sum of array values function using pointers

#include<stdio.h>

int* getarray(int);
int arraysum();

int main(){
    int n,i;
    int *p;
    printf("Enter the Number of values in array : ");
    scanf("%d",&n);
    p=getarray(n);
    int sum=arraysum(p,n);
    printf("\n Sum of array values : %d",sum);
    return 0;
}

int arraysum(int *x,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*(x+i);
    }
    return sum;
}

int* getarray(int n){
    static int arr[100],i;
    printf("\n\nEnter the values : ");
    for(i=0;i<n;i++){
        printf("\n %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    return arr;
}