#define _CRT_SECURE_NO_WARNINGS 1
//atoi(��ʾ ascii to integer)�ǰ��ַ���ת������������һ������.
//atoi()������ɨ����� nptr�ַ���������ǰ��Ŀհ��ַ�������ո�tab�����ȣ�����ͨ��isspace()��������⣩��ֱ���������ֻ��������Ųſ�ʼ��ת�����������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء���� nptr����ת���� int ���� nptrΪ���ַ�������ô������0
//������ģ��ʵ��atoi����ʱ, Ҫע�����¼���:
//1.�ַ���֮ǰ�Ŀհ�����
//2.������
//3.�ַ���Ϊ��ʱ
//4.��ת�������ֹ��ڴ���������������
//5.����, �޷�ת�������(ȫ����ĸ....֮���)
#include <iostream>
#include <assert.h>
#include <stdlib.h>
using namespace std;

enum
{
	vaild,//��Ч=0
	invaild,//��Ч=1
};
int flag = vaild;//Ĭ����Ч
int my_atoi(const char* ptr)
{
	long long ret = 0;
	int symbol = 1;//���ű�ʾ����
	//����ptr != NULL
	assert(ptr);
	//�жϿ��ַ�
	if (*ptr == '\0')
	{
		flag = invaild;
		return 0;
	}
	//ȥ���ո��Ʊ��
	while(isspace(*ptr))
	{
		ptr++;
	}
	//����λ�ж�
	if (*ptr == '-')
	{
		symbol = -1;
		ptr++;
	}
	else if (*ptr == '+')
	{
		ptr++;
	}
	else if (((*ptr <= '0') && (*ptr >= '9')))//�Ƿ��ַ�
	{
		flag = invaild;
		return 0;
	}
	//�����쳣������ϣ���ʼת��
	while ((*ptr != '\0') && (*ptr >= '0') && (*ptr <= '9'))
	{
		ret = (ret * 10 + *ptr - '0');
		ptr++;
	}
	//���Ϸ���
	ret *= symbol;
	//���������
	//int 0111 1111 1111 1111 1111 1111 1111 1111 �����
	//     7    f    f    f    f    f    f    f
	//    1000 0000 0000 0000 0000 0000 0000 0000 �����
	//      8     0   0   0     0    0    0    0
	if (((ret > 0x7fffffff) && (1 == symbol)) ||
		(ret < (signed int)0x80000000) && (-1 == symbol)){
		flag = invaild;
		return 0;
	}
	//ret�Ϸ�
	flag = vaild;
	cout << ret << endl;
}
//��ӡatoi����״̬
void PrintState(){
	if (flag){
		cout << "�쳣" << endl;
	}
	else{
		cout<< "����" << endl;
	}
}
//���Ժ���
int main()
{
	my_atoi("1234");
	PrintState();
	my_atoi("-1234");
	PrintState();
	my_atoi("!!!");
	PrintState();
	my_atoi("");
	PrintState();
	my_atoi("   1234aaaa");
	PrintState();
	my_atoi("1234aaaa");
	PrintState();

	system("pause");
	return 0;
}