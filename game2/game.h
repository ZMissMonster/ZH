#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10
//#define MIDDLE_COUNT 10   中等难度
//#define HARD_COUNT 10  高级难度


void InitBoard(char a[ROWS][COLS],int rows, int cols,char set); 
void DisplayBoard(char a[ROWS][COLS], int row, int col);
void SetMine(char a[ROW][COL],int row,int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);







#endif //__GAME_H__