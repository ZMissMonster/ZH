#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/1183548cd48446b38da501e58d5944eb?tpId=85&&tqId=29840&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������
//��������:
//ÿ������������񳤿�W, H���ÿո�ָ�.(1 �� W��H �� 1000)
//������� :
//���һ�������Էŵĵ�����

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
	{
		e.resize(h, 1);
	}
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// ��ǲ��ܷŵ����λ��
				if ((i + 2) < w)
					a[i + 2][j] = 0;
				if ((j + 2) < h)
					a[i][j + 2] = 0;
			}
		}
	} 
	cout << res;
	return 0;
}