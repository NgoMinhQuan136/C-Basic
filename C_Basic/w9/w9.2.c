#include <stdlib.h>
#include <math.h> 
#include <stdio.h> 
#include <time.h>
  
void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void main() 
{   time_t now = time(NULL);
    clock_t start, end ;
    	int* arr = NULL;
    double time_use ;
    int n;
    //int arr[] = { 12, 11, 13, 5, 6 ,3 ,4, 10, 17, 18, 10, 100, 123, 134, 136, 136,16, 1999, 139, 947, 376, 263, 3892, 4947}; 
	printf("Nhap so luong: ");
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	srand(now);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}
    start = clock();
    int na = sizeof(arr) / sizeof(arr[0]); 
  
    insertionSort(arr, na); 
    end = clock();
    time_use = (double)(end - start)/CLOCKS_PER_SEC;
    printArray(arr, na); 
    printf("Thoi gian chay : %2.5f", time_use);
   // return 0; 
} 