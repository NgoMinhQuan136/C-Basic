#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* T = NULL;
char* P = NULL;
int n = 0;
int m = 0;
int* L = NULL;
int* F = NULL;

void BruteForceSearch(char* p, char* t)
{
	int found = 0;
	for (int i = 0;i < strlen(t);i++)
	{
		if (p[0] == t[i])
		{
			int j = 0;
			while (j < strlen(p) && i + j < strlen(t))
			{
				if (p[j] != t[i + j])
					break;
				j += 1;
			}
			if (j == strlen(p))
			{
				printf("Tim thay tai vi tri: %d\n", i);
				found = 1;
			}
		}
	}
	if (!found)
	{
		printf("Khong tim thay\n");
	}
}

void PreProcessing(char* t, char* p, int* l)
{
	for (int i = 0;i < 256;i++)
	{
		l[i] = -1;
	}
	for (int i = 0;i < strlen(p);i++)
	{
		l[p[i]] = i;
	}
}

void BMSearch(char* p, char* t)
{
	PreProcessing(t, p, L);
	int m = strlen(p);
	int i = m - 1;
	int j = m - 1 ;
	int found = 0;
	do{
		if (t[i] == p[j])
		{
			if (j == 0)
			{
				printf("Tim thay tai vi tri: %d\n", i);
				found = 1;
			}else
			{
				i -= 1;
				j -= 1;
			}
		}else
		{
			if (j < L[t[i]] + 1)
				i = i + m - j;
			else
				i = i + m - (L[t[i]] + 1);
			j = m - 1;
		}
	}while (i < strlen(t));
	
	if (!found)
	{
		printf("Khong tim thay");
	}
}

void Failure(char* p)
{
	F[0] = 0;		
	int j = 1;
	int L = 0;
	while (j < m)
	{
		if (p[j] == p[L])
		{
			F[j] = L + 1;
			L = L + 1;
			j = j + 1;
		}else
		{
			if (L > 0)
				L = F[L - 1];
			else
			{
				F[j] = 0;
				j = j + 1;
			}
		}
	}
	
	for (int i = 0;i < strlen(p);i++)
	{
		printf("%d\n", F[0]);
	}
}

void main()
{
	printf("Do dai xau du lieu: ");
	scanf("%d",&n);
	T = (char*)calloc(n + 1, sizeof(char));
	P = (char*)calloc(n + 1, sizeof(char));
	L = (int*)calloc(256, sizeof(int));
	F = (int*)calloc(n + 1, sizeof(int));
	
	time_t now = time(NULL);
	srand(now);
	for (int i = 0;i < n;i++)
	{
		int type = rand() % 3;
		if (type == 0)
		{
			T[i] = 'A' + (rand() % ('Z' - 'A' + 1));
		}else if (type == 1)
		{
			T[i] = 'a' + (rand() % ('z' - 'a' + 1));	
		}else
			T[i] = '0' + (rand() % ('9' - '0' + 1));	
	}
	printf("%s\n", T);
	printf("Nhap mau can tim: ");
	fflush(stdin);
	gets(P);
	m = strlen(P);
	P = (char*)realloc(P, m + 1);
	BruteForceSearch(P, T);
	Failure(P);
	free(T); T = NULL;
	free(P); P = NULL;
	free(L); L = NULL;
	free(F); F = NULL;
}