//my_memcpy¡¢my_strstr¡¢my_strcmp¡¢my_strcpy
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

int main()
{

	system("pause");
	return 0;
}


//void* my_memcpy(void *dest,const void *src,size_t sz)
//{
//	assert(src);
//	assert(dest);
//	char* pdest = (char*)dest;
//	char* psrc = (char*)src;
//	unsigned int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		*pdest = *psrc;
//		pdest++;
//		psrc++;
//	}
//	return dest;
//}
//
//int main()
//{
//	char arr1[10] = { 0 };
//	char arr2[] = "abcdef";
//	my_memcpy(arr1, arr2, 5* sizeof(arr2[0]));
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}

//char* my_strstr(const char *str, char *substr)
//{
//	assert(str);
//	const char *s1 = str;
//	const char *s2 = substr;
//	const char *cur = str;
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = substr;
//		while (*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return cur;
//		if (*s1 == '\0')
//			return NULL;
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char *p = "abcdefg";
//	char *q = "bcd";
//	char *ret = my_strstr(p,q);
//	printf("%s\n", ret);
//	system("pause");
//	return 0;
//}
//
////int my_strcmp(const char* str1, const char *str2)
////{
////	assert(str1);
////	assert(str2);
////	while (*str1 == *str2)
////	{
////		if (*str1 == '\0')
////			return 0;
////		str1++;
////		str2++;
////	}
////	if (*str1 > *str2)
////		return 1;
////	else
////		return -1;//return *str1-*str2;
////
////}
//
//int main()
//{
//	char *p1 = "abcd";
//	char *p2 = "aaaa";
//	int ret =my_strcmp(p1, p2);
//	printf("%d\n\n",ret);
//	system("pause");
//	return 0;
//}



//
//void my_strcpy(char*dest, const char*src)
//{
//	char ret = dest;
//	assert(dest);
//	assert(src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char a[] = "abc";
//	char b[] = "bcd";
//	my_strcpy(b, a);
//	printf("%s\n", b);
//	system("pause");
//	return 0;
//}


//void my_strcpy(char*dest, const char*src)
//{
//	char ret = dest;
//	assert(dest);
//	assert(src);
//	while ((*dest++ = *src++))
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char a[] = "abc";
//	char b[] = "bcd";
//	my_strcpy(b,a);
//	printf("%s\n", b);
//	system("pause");
//	return 0;
//}