#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char article[1000][16];
char noun[1000][16];
char verb[1000][16];
char pre[1000][16];
int narticle;
int nnoun;
int nverb;
int npre;

void main()
{
	printf("So article: ");
	scanf("%d", &narticle);
	for (int i = 0;i < narticle;i++)
	{
		printf("Article %d: ", i);
		fflush(stdin);
		gets(article[i]);
	}
	printf("So noun: ");
	scanf("%d", &nnoun);
	for (int i = 0;i < nnoun;i++)
	{
		printf("Noun %d: ", i);
		fflush(stdin);
		gets(noun[i]);
	}
	printf("So verb: ");
	scanf("%d", &nverb);
	for (int i = 0;i < nverb;i++)
	{
		printf("Verb %d: ", i);
		fflush(stdin);
		gets(verb[i]);
	}
	printf("So preposition: ");
	scanf("%d", &npre);
	for (int i = 0;i < npre;i++)
	{
		printf("Preposition %d: ", i);
		fflush(stdin);
		gets(pre[i]);
	}
	getch();
}