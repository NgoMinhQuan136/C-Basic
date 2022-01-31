#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

void QuickSort(int a[], int left, int right)
{
	int pivot, i, j, p;
	if (left < right)
	{
		i = left;
		j = right + 1;
		p = left + rand() % (right - left + 1);
		int temp = a[left];
		a[left] = a[p];
		a[p] = temp;
		//printf("[%d,%d,%d]\n", left, p, right);
		pivot = a[left];
		do {
			do {
				i = i + 1;
			} while (i <= right && a[i] < pivot);

			do {
				j = j - 1;
			} while (a[j] > pivot);
			
			if (i < j)
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);

		temp = a[left];
		a[left] = a[j];
		a[j] = temp;

		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
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
	QuickSort(a, 0, n - 1);
	end = clock();
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d\n", a[i]);
	//}
	double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Time : %f\n", elapsed);
	free(a);
	a = NULL;
}