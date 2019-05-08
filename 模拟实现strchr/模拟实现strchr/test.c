#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>

char  *my_strchr(const char *arr, char ch)
{
	assert(arr);
	while (*arr != '\0')
	{
		if (*arr == ch)
		{
			return (char*)arr;
		}
		arr++;
	}
	return NULL;
}
int main()
{
	char arr[] = "abccd";
	printf("%s\n", my_strchr(arr, 'c'));
	system("pause");
	return 0;
}
