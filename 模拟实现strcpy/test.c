#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

void my_strcpy(char*dest, const char*src)
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "abcdef=";
	char arr2[] = { 0 };
	printf("arr1=%s arr2=%s\n", arr1, arr2);
	my_strcpy(arr2, arr1);
	printf("arr1=%s arr2=%s\n", arr1, arr2);
	system("pause");
	return 0;
}
