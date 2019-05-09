#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strcmp(const char* str1, const char *str2)
{
	assert(str1);
	assert(str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;//return *str1-*str2;

}

int main()
{
	char *p1 = "abcd";
	char *p2 = "aaaa";
	int ret = my_strcmp(p1, p2);
	printf("%d\n\n", ret);
	system("pause");
	return 0;
}
