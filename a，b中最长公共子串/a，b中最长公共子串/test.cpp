#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//��Ŀ����
//���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
//�������� :
//���������ַ���
//������� :
//�����ظ����ֵ��ַ�
//ʾ��1
//����
//����
//abcdefghijklmnop
//abcsafjklmnopqrstuvw
//���
//����
//jklmnop
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string ls, ss;
	while (cin >> ls>> ss)
	{
		//����̵��ַ�����Ϊs1
		if (ls.size() > ss.size())
			swap(ls, ss);
		int len1 = ls.size(), len2 =ss.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (ls[i - 1] == ss[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//����и����Ĺ����Ӵ������³���
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
				start = i - max;
			}
		}
		cout <<ls.substr(start, max) << endl;
	} 
	return 0;
}