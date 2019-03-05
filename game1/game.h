#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define ROW 3
#define COL 3


void InitBoard(char a[ROW][COL],int row,int col);
void DisplayBoard(char a[ROW][COL], int row, int col);
void PlayerMove(char a[ROW][COL], int row, int col);
void ComputerMove(char a[ROW][COL], int row, int col);
char IsWin(char a[ROW][COL], int row, int col);

#endif //__GAME_H__