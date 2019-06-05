#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
//����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0��ʾû�����ӣ�Ϊ - 1�����ǶԷ���ҵ����ӡ�
//����������
//[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//���أ�true
#include <iostream>
#include <vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		//���ÿ���Ƿ�Ӯ����Ϊrow
		int i, j, sum;
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[i][j];
			}
			if (sum == row)
			{
				return true;
			}
		}
		//���ÿһ���Ƿ�Ӯ
		for (i = 0; i < row; i++)
		{
			sum = 0;
			for (j = 0; j < row; j++)
			{
				sum += board[j][i];
			}
			if (sum == row)
			{
				return true;
			}
		}
		//����ҶԽ��Ƿ�Ӯ
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
		{
			return true;
		}
		//�����Խ����Ƿ�Ӯ
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}
		//�����ﶼû��Ӯ
		return false;
	}
};