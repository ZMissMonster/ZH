#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
void menu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	printf("***********************\n");
	printf("*****   1.Play   ******\n");
	printf("*****   0.Exit   ******\n");
	printf("***********************\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");

}


void game()
{
	char board[ROW][COL] = {0};
	char ret = 0;
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		PlayerMove(board,ROW,COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	DisplayBoard(board, ROW, COL);
	if (ret == 'x')
	{
		printf("恭喜你取得胜利！\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	}
	else if(ret == '0')
	{
		printf("电脑赢！再接再厉~\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	}
	else if (ret == 'p')
	{
		printf("平局\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");

	}
}
//x-玩家赢
//0-电脑赢
//p-平局
//j-继续

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择-->");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 2:
				printf("退出游戏");
				break;
			default:
				printf("输入有误，请重新选择!!");
				break;
		}
	} while (input);
	
}

int main()
{
	test();
	system("pause");
	return 0;
}