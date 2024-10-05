/*
Array Implementation and operations 

 1) Display the array values
 2) Insert value at end 
 3) insert value at specific postion
 4) Insert value at 0th index
 5) Delete the last index value
 6) Delete a specific value
 7) delete a specific index
 8) delete a value of 0th index
 9) Search a specific value in array
 
*/


#include<stdio.h>
#define MAXSIZE 50
int arr[MAXSIZE];
int size=0;

void display(){
    printf("[ ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf(" ] ");
}

int getvalue(){
    int val;
    printf(" Enter value : ");
    scanf("%d",&val);
    return val;
}

int getpos(){
    int val;
    printf(" Enter position : ");
    scanf("%d",&val);
    return val;
}

void insert(int pos,int val){
    if(pos==size){
        arr[size++]=val;
    }
    else{
        for(int i=size-1;i>=pos;i--){
            arr[i+1]=arr[i];
        }
        arr[pos]=val;
        size++;
    }
}

void deletebypos(int pos){
    if(pos==size-1){
        size--;
    }
    else{
        for(int i=pos;i<size;i++){
            arr[i]=arr[i+1];   
        }
        size--;
    }
}

int search(int val){
    for(int i=0;i<size;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main(){
    int option=0;
    
    printf("\n choose the option to perform operation on array :- ");
    printf("\n 1) Display \n 2) Insert value at end \n 3) insert value at specific postion \n 4) Insert value at 0th index \n 5) Delete the last index value \n 6) Delete a specific value \n 7) delete a specific index \n 8) delete a value of 0th index \n 9) Search a specific value in array \n 10) Exit ");
    while(option!=10){
        printf("\n Enter option : ");
        scanf("%d",&option);
        switch(option){
            case 1: 
                if(size!=0){
                    display();
                }else{
                    printf(" array is Empty");
                }
                break;
            case 2: 
                // printf("\n SZ = %d,MSZ = %d",size,MAXSIZE);
                if(size!=MAXSIZE){
                    int val = getvalue();
                    insert(size,val);
                }
                else{
                    printf(" array is full");
                }
                break;
            case 3: 
                if(size!=MAXSIZE){
                    int val = getvalue();
                    int pos = getpos();
                    insert(pos,val);
                }
                else{
                    printf(" array is full");
                }
                break; 
            case 4: 
                if(size!=MAXSIZE){
                    int val = getvalue();
                    insert(0,val);
                }
                else{
                    printf(" array is full");
                }
                break;  
            case 5:
                if(size!=0){
                    deletebypos(size-1);
                }else{
                    printf(" Array is empty");
                } 
                break;
            case 6:
                if(size!=0){
                    int val=getvalue();
                    int pos=search(val);
                    if(pos!=-1){
                        deletebypos(pos);
                    }
                    else{
                        printf("val is not exist");
                    }                            
                }else{
                    printf(" Array is empty");
                }             
                break;
            case 7:
                if(size!=0){
                    int pos=getpos();
                    deletebypos(pos);
                }else{
                    printf(" Array is empty");
                }                 
                break;
            case 8:
                if(size!=0){
                    deletebypos(0);
                }else{
                    printf(" Array is empty");
                } 
                break; 
            case 9:
                if(size!=0){
                    int value=getvalue();
                    int pos=search(value);
                    if(pos!=-1){
                        printf("index = %d",pos);
                    }
                    else{
                        printf("val is not exist");
                    }                
                }else{
                    printf(" Array is empty");
                }
                break;               

        }
    }
    return 0;
}
