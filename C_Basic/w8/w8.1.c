#include <stdio.h>
#include <malloc.h>

typedef struct _NODE
{
	int player1;
	int player2;
	struct _NODE* left;
	struct _NODE* right;
}NODE;

NODE* root = NULL;

void FreeTree(NODE* node)
{
	if (node != NULL)
	{
		int p1 = node->player1;
		int p2 = node->player2;
		NODE* left = node->left;
		NODE* right = node->right;
		free(node);
		node = NULL;
		
		FreeTree(left);
		//printf("%d-%d\n", p1, p2);
		FreeTree(right);
	}
}

int CountRight(NODE* node)
{
	if (node == NULL)
		return 0;
	else{
		if (node->right == NULL)
			return CountRight(node->left);
		else
			return 1 + CountRight(node->left) + CountRight(node->right);
	}
}

int CountLeaf(NODE* node)
{
	if (node == NULL)
		return 0;
	else{
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
		{
			return CountLeaf(node->left) + CountLeaf(node->right);
		}
	}	
}

int Height(NODE* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int leftHeigth = Height(node->left);
		int rightHeight = Height(node->right);
		return 1 + (leftHeigth < rightHeight ? rightHeight : leftHeigth);
	}
}

int CountNode(NODE* node)
{
	if (node == NULL)
		return 0;
	else{
		return 1 + CountNode(node->left) + CountNode(node->right);
	}
}

NODE* CreateNode(int p1, int p2)
{
	NODE* node = (NODE*)calloc(1, sizeof(NODE));
	node->player1 = p1;
	node->player2 = p2;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void main()
{	
	int a12, a34, a56, a78, a910, a1112, a1314, a1516;
	int a1234, a5678, a9101112, a13141516;
	int a1_8, a9_16;
	int a1_16;
	printf("1-2: ");
	scanf("%d", &a12);
	NODE* n12 = CreateNode(1, 2);
	printf("3-4: ");
	scanf("%d", &a34);
	NODE* n34 = CreateNode(3, 4);
	printf("5-6: ");
	scanf("%d", &a56);
	NODE* n56 = CreateNode(5, 6);
	printf("7-8: ");
	scanf("%d", &a78);
	NODE* n78 = CreateNode(7, 8);
	printf("9-10: ");
	scanf("%d", &a910);
	NODE* n910 = CreateNode(9, 10);
	printf("11-12: ");
	scanf("%d", &a1112);
	NODE* n1112 = CreateNode(11, 12);
	printf("13-14: ");
	scanf("%d", &a1314);
	NODE* n1314 = CreateNode(13, 14);
	printf("15-16: ");
	scanf("%d", &a1516);
	NODE* n1516 = CreateNode(15, 16);
	////////////////////////////////
	printf("%d-%d: ", a12, a34);
	scanf("%d", &a1234);
	NODE* n1234 = CreateNode(a12, a34);
	n1234->left = n12;
	n1234->right = n34;
	printf("%d-%d: ", a56, a78);
	scanf("%d", &a5678);
	NODE* n5678 = CreateNode(a56, a78);
	n5678->left = n56;
	n5678->right = n78;
	printf("%d-%d: ", a910, a1112);
	scanf("%d", &a9101112);
	NODE* n9101112 = CreateNode(a910, a1112);
	n9101112->left = n910;
	n9101112->right = n1112;
	printf("%d-%d: ", a1314, a1516);
	scanf("%d", &a13141516);
	NODE* n13141516 = CreateNode(a1314, a1516);
	n13141516->left = n1314;
	n13141516->right = n1516;
	//////////////////////////////////////////////
	printf("%d-%d: ", a1234, a5678);
	scanf("%d", &a1_8);
	NODE* n1_8 = CreateNode(a1234, a5678);
	n1_8->left = n1234;
	n1_8->right = n5678;
	printf("%d-%d: ", a9101112, a13141516);
	scanf("%d", &a9_16);
	NODE* n9_16 = CreateNode(a9101112, a13141516);
	n9_16->left = n9101112;
	n9_16->right = n13141516;
	////////////////////////////////////////////////
	printf("%d-%d: ", a1_8, a9_16);
	scanf("%d", &a1_16);
	NODE* n1_16 = CreateNode(a1_8, a9_16);
	n1_16->left = n1_8;
	n1_16->right = n9_16;
	
	root = n1_16;
	printf("Leaf: %d\n", CountLeaf(root));
	printf("Height: %d\n", Height(root));
	printf("Right Node: %d\n", CountRight(root));
	
	FreeTree(root);
}