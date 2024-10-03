#include<stdio.h>
// sum of array values 
int main(){
    int n,i;
    int *ar;
    ar=getarray();
    printf("1 : %d",*ar);
    // int sum=arraysum(a);
    // printf("sum of array values : %d",sum);
    return 0;
}

int arraysum(int x[]){
    int sm=0;
    for(int i=0;i<5;i++){
        sm=sm+x[i];
    }
    return sm;

}

int* getarray(){
    static int b[5],i;
    printf("Enter the values : ");
    for(i=0;i<5;i++){
        scanf("%d",&b[i]);
    }
    return b;
}