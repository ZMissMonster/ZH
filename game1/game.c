#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char a[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			a[i][j] = ' ';
		}
	}
	/*memset(a, ' ', row*col*sizeof(a[0][0]));*/
}


void DisplayBoard(char a[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", a[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j< col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char a[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:\n");
	while (1)
	{
		printf("请输入坐标---> ");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= 3) && (y >= 1 && y <= 3))
		{
			if (a[x - 1][y - 1] == ' ')
			{
				a[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("该坐标已经被占用");
			}
		}
		else
		{
			printf("非法输入\n");
		}
	}
}
void ComputerMove(char a[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走:\n");
	
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (a[x][y] == ' ')
		{
			a[x][y] = '0';
			break;
		}
	}

}

int IsFull(char a[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (a[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char a[ROW][COL], int row, int col)
{
	//横排
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ')
		{
			return a[i][0];
		}
	}
	//竖排
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (a[0][j] == a[1][j] && a[1][j] == a[2][j] && a[0][j] != ' ')
		{
			return a[0][j];
		}
	}
	//斜排
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ')
	{
		return a[0][0];
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] != ' ')
	{
		return a[0][2];
	}
	//平局
	if (IsFull(a,row,col))
	{
		return 'p';
	}
	return 'j';
}