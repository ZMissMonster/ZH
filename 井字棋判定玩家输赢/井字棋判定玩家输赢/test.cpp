#define _CRT_SECURE_NO_WARNINGS 1
//https://www.nowcoder.com/practice/e1bb714eb9924188a0d5a6df2216a3d1?tpId=8&&tqId=11055&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//对于一个给定的井字棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
//给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0表示没有棋子，为 - 1代表是对方玩家的棋子。
//测试样例：
//[[1, 0, 1], [1, -1, -1], [1, -1, 0]]
//返回：true
#include <iostream>
#include <vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board) {
		int row = board.size();
		//检查每行是否赢，和为row
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
		//检查每一列是否赢
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
		//检查右对角是否赢
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][i];
		}
		if (sum == row)
		{
			return true;
		}
		//检查左对角线是否赢
		sum = 0;
		for (i = 0; i < row; i++)
		{
			sum += board[i][row - i - 1];
		}
		if (sum == row)
		{
			return true;
		}
		//到这里都没有赢
		return false;
	}
};