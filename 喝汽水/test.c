#define _CRT_SECURE_NO_WARNINGS 1
//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ��
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int money = 0;
	printf("������money=");
	scanf("%d", &money);
	int total = money;
	int empty = money;
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("����Ժ� %d ƿ����\n", total);
	system("pause");
	return 0;
}
