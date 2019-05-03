#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

void my_strcat(char*dest, const char*src)
{
	assert(dest);
	assert(src);
	char *ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[] = "abc";
	char arr2[] = "def";
	printf("arr1=%s arr2=%s\n", arr1, arr2);
	my_strcat(arr1, arr2);
	printf("arr1=%s \n", arr1);
	system("pause");
	return 0;
}
