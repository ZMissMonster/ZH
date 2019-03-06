#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("**********************\n");
	printf("****    1.Play    ****\n");
	printf("****    0.Exit    ****\n");
	printf("**********************\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~\n");
}


void game()
{
	//1.������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine,ROW, COL);
	DisplayBoard(show, ROW, COL);
	//2.ɨ��
	FindMine(mine,show,ROW,COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("\n");
		printf("��ѡ��---->");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
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