#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int money = 0;
	printf("请输入money=");
	scanf("%d", &money);
	int total = money;
	int empty = money;
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("你可以喝 %d 瓶饮料\n", total);
	system("pause");
	return 0;
}
