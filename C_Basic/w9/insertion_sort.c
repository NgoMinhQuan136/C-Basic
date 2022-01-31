#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

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
{
	time_t now = time(NULL);
	int* a = NULL;
	int n;
	int temp;
	clock_t start, end ;

	printf("Nhap so luong: ");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	srand(now);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000;
	}
	//for (int i = 0; i < n; i++)
	//{
		//printf("%d\n", a[i]);
	//}
	printf("***\n");
	start = clock();
	insertionSort(a,n);
	end = clock();
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d\n", a[i]);
	//}
	double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time : %2.4fs\n", elapsed);
	free(a);
	a = NULL;
}