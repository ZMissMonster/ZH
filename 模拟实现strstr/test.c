#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strstr(const char *str, char *substr)
{
	assert(str);
	const char *s1 = str;
	const char *s2 = substr;
	const char *cur = str;
	while (*cur)
	{
		s1 = cur;
		s2 = substr;
		while (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return cur;
		if (*s1 == '\0')
			return NULL;
		cur++;
	}
	return NULL;
}

int main()
{
	char *p = "abcdefg";
	char *q = "bcd";
	char *ret = my_strstr(p, q);
	printf("%s\n", ret);
	system("pause");
	return 0;
}
