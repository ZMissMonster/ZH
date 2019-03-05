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
		printf("��ϲ��ȡ��ʤ����\n");
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
		printf("����Ӯ���ٽ�����~\n");
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
		printf("ƽ��\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");

	}
}
//x-���Ӯ
//0-����Ӯ
//p-ƽ��
//j-����

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��-->");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 2:
				printf("�˳���Ϸ");
				break;
			default:
				printf("��������������ѡ��!!");
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