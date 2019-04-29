#define _CRT_SECURE_NO_WARNINGS 1
//递归：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n = 0;
	printf("请输入要求的第n个菲波那切数列 n = ");
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
//非递归：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
	int n = 0;
	int a = 1;
	int b = 1;
	int c = a;
	printf("请输入要求的第n个菲波那切数列 n = ");
	scanf("%d", &n);
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	printf("%d\n", c);
	system("pause");
	return 0;
}
