#include <stdio.h>
#include <string.h>

int main()
{
	int count[256];
	char input[1024];
	printf("Nhap vao mot xau ky tu: ");
	fflush(stdin);
	memset(input, 0, sizeof(input));
	gets(input);
	memset(count, 0, sizeof(count));
	for (int i = 0;i < strlen(input);i++)
	{
		count[input[i]] += 1;
	}
	for (int i = 0;i < 256;i++)
	{
		if (count[i] > 0)
		{
			printf("Character '%c': %d\n", i, count[i]);
		}
	}
	getch();
	return 0;
}