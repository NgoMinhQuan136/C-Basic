#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element_type;
typedef struct _QUEUE_ELEMENT
{
	element_type data;
	struct _QUEUE_ELEMENT* link;
}QUEUE_ELEMENT, *PQUEUE_ELEMENT;

typedef struct _QUEUE
{
	PQUEUE_ELEMENT Front;
	PQUEUE_ELEMENT Rear;	
	int size;
}QUEUE, *PQUEUE;


int IsEmpty(PQUEUE pQueue)
{
	if (pQueue->Front == NULL && pQueue->Rear == NULL)
		return 1;
	else
		return 0;
}
void Enqueue(PQUEUE pQueue, element_type data)
{
	PQUEUE_ELEMENT newElement = (PQUEUE_ELEMENT)calloc(1, sizeof(QUEUE_ELEMENT));
	newElement->data = data;
	newElement->link = NULL;
	if (IsEmpty(pQueue))
	{
		pQueue->Front = newElement;
		pQueue->Rear = newElement;
	}else{
		pQueue->Rear->link = newElement;
		pQueue->Rear = newElement;
	}
	pQueue->size += 1;
}
int Dequeue(PQUEUE pQueue, element_type* out)
{
	if (IsEmpty(pQueue))
		return 0; //Khong lay duoc
	else
	{
		*out = pQueue->Front->data;
		PQUEUE_ELEMENT oldElement = pQueue->Front;
		pQueue->Front = pQueue->Front->link;
		free(oldElement);
		oldElement = NULL;
		if (pQueue->Front == NULL)
		{
			pQueue->Rear = NULL;
		}
		pQueue->size -= 1;
		return 1; //Lay thanh cong
	}
}
void Free(PQUEUE pQueue)
{
	element_type d;
	while (Dequeue(pQueue, &d) == 1);
}
void main()
{

	//int h, m, n, count = 0;
    int num[10];
    int m ;
    
	element_type data;
	QUEUE queue1;
	memset(&queue1, 0, sizeof(QUEUE));

    for ( int i = 0; i <4; i++){
        printf("Nhap so:\n");
        scanf("%d", &num[i]);
        fflush(stdin);
    }
    for( int k = 0; k < 4 ; k++){
        Enqueue(&queue1, num[k]);
    }
    printf("Nhap vao gia tri can them:\n");
    scanf("%d", &m);
    

    printf("So bi loai bo la: %d\n", queue1.Front->data);
    int r = Dequeue(&queue1, &data);
    Enqueue(&queue1, m);
    printf(" Gia tri : %d\n", queue1.Rear->data);
	
}
