#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/
//��ʵ�����½ӿ�
//public   static   int  findNumberOf1(int num)
//{
//	/*  ��ʵ��  */
//	return  0;
//
//} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
//
//�������� :
//����һ������
//������� :
//����������������1�ĸ���
#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n > 0)
		{
			if (n & 1)
			{
				++count;
			}
			n = n >> 1;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}