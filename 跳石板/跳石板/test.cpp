#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&amp;&amp;tqId=29852&amp;rp=1&amp;ru
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//���磺
//N = 4��M = 24��
//4->6->8->12->18->24
//����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
//�������� :
//	����Ϊһ�У�����������N��M���Կո������(4 �� N �� 100000) (N �� M �� 100000)
//������� :
//	���С��������Ҫ��Ծ�Ĳ���, ������ܵ������ - 1
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
//��ʯ��

//��Լ��
void getYueshu(int n, vector<int> &yueshu){//�����1�ͱ����Լ��
	for (int i = 2; i <= sqrt(n); ++i){
		if (n%i == 0){
			yueshu.push_back(i);
			if (n / i != i)//��ƽ����ʱ������һ����ҲҪ����
				yueshu.push_back(n / i);
		}
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> steps(M + 1, 0);
	steps[N] = 1;

	for (int i = N; i <= M; ++i){
		if (steps[i] == 0)continue;   //λ���޷��������
		vector<int> yueshu;
		getYueshu(i, yueshu);
		for (int j = 0; j < yueshu.size(); ++j){  //��¼�����N��λ��i����С����
			if (yueshu[j] + i <= M){
				if (steps[yueshu[j] + i] == 0)    //����λ��i����С������1
					steps[yueshu[j] + i] = steps[i] + 1;
				else                         //������Ҳ�ܵ���Ƚϴ�С����¼��С����
					steps[yueshu[j] + i] = (steps[i] + 1) < steps[yueshu[j] + i] ? (steps[i] + 1) : steps[yueshu[j] + i];
			}
		}
	}

	if (steps[M] == 0)
		cout << -1 << endl;
	else
		cout << steps[M] - 1 << endl;
	system("pause");
	return 0;
}
