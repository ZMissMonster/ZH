#define _CRT_SECURE_NO_WARNINGS 1
#include "CommentConvert.h"

void test()
{
	FILE*pfRead = fopen("input.c","r"); 
	if (pfRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	FILE*pfWrite = fopen("input.c", "w");
	if (pfWrite == NULL)
	{
		perror("open file for write");
		fclose(pfRead);
		exit(EXIT_FAILURE);
	}
	//ע��ת��
	CommentConvert(pfRead,pfWrite);
	printf("ת�����\n");
	fclose(pfRead);
	fclose(pfWrite);
	pfRead = NULL;
	pfWrite = NULL;


}

int main()
{
	test();
	system("pause");
	return 0;
}