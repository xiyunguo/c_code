#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitalBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//打印一行内容
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//打印空格内容空格
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				//打印|
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			//打印一行分割
			for (j = 0; j < col; j++)
			{
				//打印---
				printf("---");
				if (j < col - 1)
				{
					//打印|
					printf("|");
				}
			}
		}
		printf("\n");
		

	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	while (1)
	{
		printf("请输入要走的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//如果占用，警告重新输入
			if ( board[x-1][y-1] != ' ')
			{
				printf("该位已被占用，请重新输入\n");
			}
			else
			{
				//如果为空，则赋值
				board[x - 1][y - 1] = '*';
				break;
			}			
		}
		else
		{
			printf("输入的坐标越界，请重新输入\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//1-满了
//0-未满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//玩家赢*
//电脑赢#
//平局Q
//继续C
char IsWin(char board[ROW][COL], int row, int col)
{
	//三行
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//三列
	 for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	 if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	 {
		 return board[1][1];
	 }
	 if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	 {
		 return board[1][1];
	 }
	 //判断是否为空
	 if (IsFull(board, ROW, COL) == 1)
	 {
		 return 'Q';
	 }
	 return 'C';
}