#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
/*�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
��û�н���������һ�룬����0*/��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		//����һ���������֮���Ȼ�����м�
		int middle = gifts[n / 2];
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			//ͳ�������м�����ĸ���
			if (gifts[i] == middle)
			{
				count++;
			}
		} 
		// �����������һ�룬����ڳ���һ�����
		if (count > n / 2)
			return middle;
		else
			return 0;
	}
};