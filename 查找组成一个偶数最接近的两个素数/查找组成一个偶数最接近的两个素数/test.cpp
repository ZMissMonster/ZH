//�������һ��ż����ӽ�����������
//���ӣ�https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283 & rp = 1 & ru = / activity / oj&qru = / ta / huawei / question - ranking
#include <iostream>
using namespace std;

size_t IsPrnumber(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int half;
		int i;
		half = n / 2;//�м��������ҵĻ���ֵ��С
		for (i = half; i > 0; --i)
		{
			if (IsPrnumber(i) && IsPrnumber(n - i))
				break;
		}
		cout << i << endl;
		cout << n - i << endl;
	}
	system("pause");
	return 0;
}

