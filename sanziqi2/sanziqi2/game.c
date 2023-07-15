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
		//��ӡһ������
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//��ӡ�ո����ݿո�
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				//��ӡ|
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			//��ӡһ�зָ�
			for (j = 0; j < col; j++)
			{
				//��ӡ---
				printf("---");
				if (j < col - 1)
				{
					//��ӡ|
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
	printf("����ߣ�\n");
	while (1)
	{
		printf("������Ҫ�ߵ����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//���ռ�ã�������������
			if ( board[x-1][y-1] != ' ')
			{
				printf("��λ�ѱ�ռ�ã�����������\n");
			}
			else
			{
				//���Ϊ�գ���ֵ
				board[x - 1][y - 1] = '*';
				break;
			}			
		}
		else
		{
			printf("���������Խ�磬����������\n");
		}
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");
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
//1-����
//0-δ��
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
//���Ӯ*
//����Ӯ#
//ƽ��Q
//����C
char IsWin(char board[ROW][COL], int row, int col)
{
	//����
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//����
	 for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�����Խ���
	 if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	 {
		 return board[1][1];
	 }
	 if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	 {
		 return board[1][1];
	 }
	 //�ж��Ƿ�Ϊ��
	 if (IsFull(board, ROW, COL) == 1)
	 {
		 return 'Q';
	 }
	 return 'C';
}