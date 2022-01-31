#include <stdio.h>
#include <string.h>


void Replace(char* str, char c1, char c2)
{
	for (int i = 0;i < strlen(str);i++)
	{
		if (str[i] == c1)
		{
			str[i] = c2;
		}
	}
}

int main()
{
	char input[1024];
	char c1, c2;
	printf("Nhap vao mot xau ky tu: ");
	fflush(stdin);
	memset(input, 0, sizeof(input));
	gets(input);
	printf("Nhap vao 2 ky tu: ");
	fflush(stdin);
	scanf("%c%c",&c1, &c2);
	Replace(input, c1, c2);
	printf("%s\n", input);
	getch();
	return 0;
}