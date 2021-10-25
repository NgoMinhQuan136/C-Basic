#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct _STACK_ITEM
{
	int d;
	struct _STACK_ITEM* link;
}STACK_ITEM;

STACK_ITEM* pOp1 = NULL;
STACK_ITEM* pOp2 = NULL;
STACK_ITEM* pSum = NULL;

int isEmpty(STACK_ITEM* pStack)
{
	return pStack == NULL ? 1 : 0;
}
int isFull(STACK_ITEM* pStack)
{
	return 0;
}
STACK_ITEM* Push(STACK_ITEM* pStack, int value)
{
	STACK_ITEM* newItem = (STACK_ITEM*)calloc(1, sizeof(STACK_ITEM));
	newItem->d = value;
	newItem->link = pStack;
	return newItem;
}

STACK_ITEM* Pop(STACK_ITEM** ppStack)
{
	STACK_ITEM* pStack = *ppStack;
	
	if (isEmpty(pStack))
		return NULL;
	else
	{
		STACK_ITEM* oldTop = pStack;
		STACK_ITEM* popItem = (STACK_ITEM*)calloc(1, sizeof(STACK_ITEM));
		popItem->d = oldTop->d;
		*ppStack = pStack->link;
		free(oldTop);
		return popItem;
	}
}
void Initialize(STACK_ITEM* pStack)
{
	while (pStack != NULL)
	{
		STACK_ITEM* next = pStack->link;
		free(pStack);
		pStack = next;
	}
	pStack = NULL;
}

void MakeStack(char* op, STACK_ITEM** pStack)
{
	for (int i = 0;i < strlen(op);i++)
	{
		*pStack = Push(*pStack, op[i] - 48);
	}
}

void main()
{
	char op1[8192];
	char op2[8192];
	char op3[8192];
	
	Initialize(pOp1);
	Initialize(pOp2);
	Initialize(pSum);
	printf("Nhap so hang thu nhat: ");
	fflush(stdin);
	scanf("%s", op1);
	MakeStack(op1, &pOp1);
	
	printf("Nhap so hang thu hai: ");
	fflush(stdin);
	scanf("%s", op2);
	MakeStack(op2, &pOp2);
	
	int c = 0;
	int d = 0;
	while (!isEmpty(pOp1) || !isEmpty(pOp2))
	{
		STACK_ITEM* item1 = Pop(&pOp1);
		STACK_ITEM* item2 = Pop(&pOp2);
		
		if (item1 == NULL)
			d = item2->d + c;
		else if (item2 == NULL)
			d = item1->d + c;
		else
			d = item1->d + item2->d + c;
		c = d / 10;
		d = d % 10;
		pSum = Push(pSum, d);
		free(item1);
		free(item2);
	}
	if (c > 0)
	{
		pSum = Push(pSum, c);
	}
	while (!isEmpty(pSum))
	{
		STACK_ITEM* item = Pop(&pSum);
		printf("%d", item->d);
		free(item);
	}
	
	getch();
}