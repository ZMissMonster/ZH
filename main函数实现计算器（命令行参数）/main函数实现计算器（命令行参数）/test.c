#define _CRT_SECURE_NO_WARNINGS 1
//ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ�������� - a��ѡ��ִ�мӷ����� - s��ѡ��ִ�м������� - m��ѡ��ִ�г˷����� - d��ѡ��ִ�г�����������������Ϊ��������
//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Add(x, y)
{
	return x + y;
}

int Sub(x, y)
{
	return x - y;
}

int Mul(x, y)
{
	return x * y;
}
int Div(x, y)
{
	return x / y;
}

int main(int argc, char*argv[], char*envp[])
{
	int ret = 0;
	if (argc != 4)
	{
		printf("������������argc=%d\n", argc);
		return 0;
	}
	switch (*(argv[1] + 1))
	{
	case 'a':
		ret = Add(atoi(argv[2]), atoi(argv[3]));
		break;
	case 's':
		ret = Sub(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'm':
		ret = Mul(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'd':
		ret = Div(atoi(argv[2]), atoi(argv[3]));
		break;
	}
	printf("ret=%d\n", ret);
	system("pause");
	return ret;
}
