// * Implementation of Max Heap

#include<stdio.h>
#include<stdlib.h>


#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val){
    size++;
    int index = size;
    heap[index] = val;

    // Corrected heapify up
    while(index > 1 && heap[index / 2] < heap[index]){
        swap(&heap[index / 2], &heap[index]);
        index = index / 2;
    }
}

int deleteMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int max = heap[1];
    heap[1] = heap[size];
    size--;

    // Heapify down
    int i = 1;
    while (i <= size) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else {
            break;
        }
    }

    return max;
}

void display() {  
    printf("Heap: ");
    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}


int main() {
    insert(50);
    insert(30);
    insert(20);
    insert(15);
    insert(10);
    insert(8);
    insert(16);
    display();

    deleteMax();
    display();
    return 0;
}