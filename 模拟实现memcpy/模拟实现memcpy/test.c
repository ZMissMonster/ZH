#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

void* my_memcpy(void *dest, const void *src, size_t sz)
{
	assert(src);
	assert(dest);
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	unsigned int i = 0;
	for (i = 0; i < sz; i++)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
	}
	return dest;
}

int main()
{
	char arr1[10] = { 0 };
	char arr2[] = "abcdef";
	my_memcpy(arr1, arr2, 5 * sizeof(arr2[0]));
	printf("%s\n", arr1);
	system("pause");
	return 0;
}
