#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

// ��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

// �������
void PlayerMove(char board[ROW][COL], int row, int col);

// ��������
// ��û����λ���������
void ComputerMove(char board[ROW][COL], int row, int col);

// ���ʤ* ����ʤ# ƽ��Q ����C
char IsWin(char board[ROW][COL], int row, int col);

// ��������0 ���˷���1
int IsFull(char board[ROW][COL], int row, int col);