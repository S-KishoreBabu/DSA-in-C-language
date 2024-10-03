#include<stdio.h>
// sum of array values 
int* getarray();
int main(){
    int n,i;
    int *p;
    p=getarray();
    // printf("1 : %d",*p);
    int sum=arraysum(p);
    printf("sum of array values : %d",sum);
    return 0;
}

int arraysum(int *x){
    int sm=0;
    for(int i=0;i<5;i++){
        sm=sm+*x+i;
    }
    return sm;

}

int* getarray(){
    static int b[5],i;
    printf("Enter the values : ");
    for(i=0;i<5;i++){
        printf("\n %d : ",i+1);
        scanf("%d",&b[i]);
    }
    return b;
}