#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
//���������bit��
int main()
{
	int n;
	while (cin >> n)
	{
		int maxsum = 0;
		int count = 0;
		while (n)
		{
			if (n & 1)
			{
				count++;
				maxsum = max(count, maxsum);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << maxsum << endl;
	}
	system("pause");
	return 0;
}



//�����������
//class LCA {
//public:
//	int getLCA(int a, int b) {
//		while (a != b)
//		{
//			if (a>b)
//				a = a / 2;
//			else
//				b = b / 2;
//		}
//		return b;
//	}
//};
//
