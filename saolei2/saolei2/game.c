#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitalBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------------扫雷----------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%2c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------***----------------\n");
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1]
		+ mine[x - 1][y]
		+ mine[x - 1][y + 1]
		+ mine[x][y - 1]
		+ mine[x][y + 1]
		+ mine[x + 1][y - 1]
		+ mine[x + 1][y]
		+ mine[x + 1][y + 1] - 8 * '0';
}
void SetBlank(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y)
{
	int ret = get_mine_count(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1 >= 0 && x - 1 <= ROW && y >= 1 && y <= COL && show[x - 1][y] == '*')
		{
			SetBlank(mine, show, x - 1, y);
		}
		if (x + 1 >= 0 && x + 1 <= ROW && y >= 1 && y <= COL && show[x + 1][y] == '*')
		{
			SetBlank(mine, show, x + 1, y);
		}
		if (x >= 0 && x <= ROW && y+1 >= 1 && y+1 <= COL && show[x][y+1] == '*')
		{
			SetBlank(mine, show, x , y+1);
		}
		if (x >= 0 && x <= ROW && y-1 >= 1 && y-1 <= COL && show[x][y-1] == '*')
		{
			SetBlank(mine, show, x, y-1);
		}
	}
	show[x][y] = ret + '0';
}
int count_mine(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	//int count = row*col-EASY_COUNT;
	while (1)
	{
		printf("请输入扫雷坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，您被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				SetBlank(mine, show, x, y);
				int count = count_mine(show, row, col);
				if (count == EASY_COUNT)
				{				
					DisplayBoard(show, row, col);
					printf("恭喜您，通关！\n");
					DisplayBoard(mine, row, col);
					break;
				}
				DisplayBoard(show, row, col);

			}
		}
		else
		{
			printf("输入坐标越界，请重新输入\n");
		}
	}
}