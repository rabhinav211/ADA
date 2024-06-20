#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low; 
    int j = high+1;
    do{
        do{
            i++;
        }while(arr[i] <  pivot && i<high);
        do{
            j--;
        }while(arr[j] >  pivot && j>low);
        swap(&arr[i], &arr[j]);
    }while(i<j);
    swap(&arr[i], &arr[j]);
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void main() {
    clock_t start, end;
    int n;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand()%100;
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("\nTime taken: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}
