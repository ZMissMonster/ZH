#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�

//�ݹ����
//a. ���n����mΪ1����ֻ��һ�л���һ�У������Ͻ��ߵ����½ǵ�·����Ϊn + m
//		���磺 1 * 1���ӣ������������ߣ��������ߣ��������½ǣ������������ߣ��������ߣ��������½ǣ����������� 1 + 1 = 2��
//b.���n, m������1����ô�ߵ�[n][m]���ӵ����½�ֻ������·����
//		<1>: ��[n - 1][m]���ӵ����½������ߣ�����
//		<2> : ��[n][m - 1]���ӵ����½������ߣ�����
//		�����ߵ�[n][m]���ӵ����½ǵ�����Ϊ[n - 1][m] + [n][m - 1], ����ͨ���ݹ�ʵ�֣����aΪ�ݹ����ֹ����

#include <iostream>
using namespace std;

int Num(int x, int y)
{
	if (x > 1 && y > 1)
	{
		return Num(x, y - 1) + Num(x - 1, y);
	}
	else if ((x >= 1) && (y == 1) || (x == 1) && (y >= 1))
		return x + y;
	else
		return 0;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << Num(a, b) << endl;
	}
	system("pause");
	return 0;
}