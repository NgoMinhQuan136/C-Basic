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

void MergeSort(int a[], int n)
{
	int m = n / 2;
	if (n > 1)
	{
		int* left = (int*)calloc(m, sizeof(int));
		int* right = (int*)calloc(n - m, sizeof(int));
		memcpy(left, a, m * sizeof(int));
		memcpy(right, a + m, (n - m) * sizeof(int));
		MergeSort(left, m);
		MergeSort(right, n - m);
		int i = 0, j = 0, k = 0;
		while (k < n)
		{
			if (i >= m)
				a[k] = right[j++];
			else if (j >= n - m)
				a[k] = left[i++];
			else if (left[i] < right[j])
				a[k] = left[i++];
			else
				a[k] = right[j++];
			k = k + 1;
		}
		free(left);
		left = NULL;
		free(right);
		right = NULL;
	}
}

void main()
{
	time_t now = time(NULL);
	int* a = NULL;
	int n;
	int temp;

	printf("Nhap so luong: ");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	srand(now);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	printf("***\n");
	QuickSort(a, 0, n - 1);
	//MergeSort(a, n);
	/*for (int i = 0;i < n - 1;i++)
	{
		int k = i + 1;
		int min = a[k];
		for (int j = i + 1;j < n;j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				k = j;
			}
		}
		if (a[i] > min)
		{
			int tmp = a[i];
			a[i] = a[k];
			a[k] = tmp;
		}
	}*/

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}

	free(a);
	a = NULL;
}