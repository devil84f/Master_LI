/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-02 09:32:16
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-02 09:38:40
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode130\LeeCode130.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

// �������������DFS������
void dfs(char** board, int i, int j, int rows, int cols) {
    // �߽���
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') {
        return;
    }
    
    // ��ǵ�ǰ�ڵ�
    board[i][j] = '#';  // ��ʱ��ǣ���ʾ��'O'�����޸�
    
    // �ݹ�����ĸ�����
    dfs(board, i+1, j, rows, cols);  // ����
    dfs(board, i-1, j, rows, cols);  // ����
    dfs(board, i, j+1, rows, cols);  // ����
    dfs(board, i, j-1, rows, cols);  // ����
}

// ���������޸ľ����е�'O'Ϊ'X'
void solve(char** board, int boardSize, int* boardColSize) {
    if (board == NULL || boardSize == 0 || *boardColSize == 0) {
        return;
    }
    
    int rows = boardSize;
    int cols = *boardColSize;
    
    // �ӱ߽���������������߽�������'O'Ϊ'#'
    for (int i = 0; i < rows; i++) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0, rows, cols);  // ��һ��
        }
        if (board[i][cols - 1] == 'O') {
            dfs(board, i, cols - 1, rows, cols);  // ���һ��
        }
    }
    for (int j = 0; j < cols; j++) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j, rows, cols);  // ��һ��
        }
        if (board[rows - 1][j] == 'O') {
            dfs(board, rows - 1, j, rows, cols);  // ���һ��
        }
    }

    // �����������󣬽��������޸�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';  // ��Χ�Ƶ�'O'��Ϊ'X'
            } else if (board[i][j] == '#') {
                board[i][j] = 'O';  // ��߽�������'O'�ָ�
            }
        }
    }
}

int main() {
    // ʾ��1��������ά����
    char* board1[ROWS] = {
        (char[]){'X', 'X', 'X', 'X'},
        (char[]){'X', 'O', 'O', 'X'},
        (char[]){'X', 'X', 'O', 'X'},
        (char[]){'X', 'O', 'X', 'X'}
    };
    int colSize1 = COLS;

    solve(board1, ROWS, &colSize1);
    
    // ����޸ĺ�ľ���
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board1[i][j]);
        }
        printf("\n");
    }

    // ʾ��2��������ά����
    char* board2[ROWS] = {
        (char[]){'O', 'O', 'O', 'O'},
        (char[]){'O', 'X', 'O', 'X'},
        (char[]){'O', 'X', 'O', 'X'},
        (char[]){'O', 'O', 'O', 'O'}
    };
    int colSize2 = COLS;

    solve(board2, ROWS, &colSize2);
    
    // ����޸ĺ�ľ���
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
