#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

// 打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

// 玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

// 电脑下棋
// 找没下棋位置随机下棋
void ComputerMove(char board[ROW][COL], int row, int col);

// 玩家胜* 电脑胜# 平局Q 继续C
char IsWin(char board[ROW][COL], int row, int col);

// 不满返回0 满了返回1
int IsFull(char board[ROW][COL], int row, int col);