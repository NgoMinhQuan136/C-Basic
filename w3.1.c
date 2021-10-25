#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _PhoneBook
{
	char name[32];
	char phone[16];
	struct _PhoneBook* next;
}PhoneBook;

PhoneBook* root = NULL;
PhoneBook* cur = NULL;

void Sort()
{
	PhoneBook* tmp = root;
	PhoneBook* prev = NULL;
	while (tmp != NULL)
	{
		PhoneBook* next = tmp->next;
		while (next != NULL)
		{
			if (strcmp(tmp->name, next->name) > 0)
			{
				if (root == tmp)
				{
					root = next;
				}
				
				tmp->next = next->next;
				next->next = tmp;
				if (prev != NULL)
				{
					prev->next = next;
				}
				tmp = next;
			}
			next = next->next;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void Free()
{
	if (root != NULL)
	{
		PhoneBook* tmp = root;
		while (tmp != NULL)
		{
			root = tmp->next;
			free(tmp);
			tmp = root;
		}
	}
}
void Remove(char* name, char* phone)
{
	if (root != NULL)
	{
		PhoneBook* tmp = root;
		PhoneBook* prev = NULL;
		while (tmp != NULL)
		{
			if (strcmp(tmp->name, name) == 0 &&
				strcmp(tmp->phone, phone) == 0)
			{
				if (prev != NULL)
				{
					prev->next = tmp->next; //Xoa nut o giua
				}else
				{
					root = tmp->next; //Xoa nut goc
				}
				free(tmp);
				break;
			}else
			{
				prev = tmp;
				tmp = tmp->next;
			}
		}
	}
}

void Travers()
{
	if (root != NULL)
	{
		PhoneBook* tmp = root;
		while (tmp != NULL)
		{
			printf("%s: %s\n", tmp->name, tmp->phone);
			tmp = tmp->next;
		}
	}
}

void Insert(char* name, char* phone)
{
	if (cur != NULL)
	{
		PhoneBook* newItem = 
		(PhoneBook*)calloc(1, sizeof(PhoneBook));
		strcpy(newItem->name, name);
		strcpy(newItem->phone, phone);
		newItem->next = NULL;
		cur->next = newItem;
		cur = newItem;
	}else{
		PhoneBook* newItem = 
		(PhoneBook*)calloc(1, sizeof(PhoneBook));
		strcpy(newItem->name, name);
		strcpy(newItem->phone, phone);
		newItem->next = NULL;
		root = newItem;
		cur = newItem;
	}
}


void Reverse()
{
	PhoneBook* tmp = root;
	PhoneBook* next = tmp->next;
	while (next != NULL)
	{
		if (tmp == root)
		{
			tmp->next = NULL;
		}
		PhoneBook* tmp1 = next->next;
		next->next = tmp;
		tmp = next;
		next = tmp1;
	}
	root = tmp;
}

void main()
{
	char name[32];
	char phone[16];
	
	while (0==0)
	{
		printf("Name: ");
		fflush(stdin);
		gets(name);
		if (strlen(name) > 0)
		{
			printf("Phone: ");
			fflush(stdin);
			gets(phone);
			Insert(name, phone);
		}else
			break;
	}	
	Reverse();
	Travers(); //Kiem tra du lieu da nhap
	
	printf("Name to remove: ");
	fflush(stdin);
	gets(name);
	printf("Phone to remove: ");
	fflush(stdin);
	gets(phone);
	Remove(name, phone); //Xoa
	Travers(); //Kiem tra du lieu sau khi xoa
	
	Free(); //Giai phong toan bo va thoat
}
