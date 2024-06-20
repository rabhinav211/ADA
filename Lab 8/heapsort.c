#include <stdio.h>



void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void heapify(int arr[], int N, int i)
{

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])

        largest = left;

    if (right < N && arr[right] > arr[largest])

        largest = right;


    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
    printf("heapify:");
    display(arr,N);
}

void heapSort(int arr[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        printf("heapsort:");
        display(arr,N);
    }
    
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 14,8,3,9,44,32};
    int N = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, N);
    printf("Sorted array is\n");
    printArray(arr, N);
}

