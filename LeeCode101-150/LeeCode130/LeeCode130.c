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

// 深度优先搜索（DFS）函数
void dfs(char** board, int i, int j, int rows, int cols) {
    // 边界检查
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') {
        return;
    }
    
    // 标记当前节点
    board[i][j] = '#';  // 临时标记，表示此'O'不被修改
    
    // 递归遍历四个方向
    dfs(board, i+1, j, rows, cols);  // 向下
    dfs(board, i-1, j, rows, cols);  // 向上
    dfs(board, i, j+1, rows, cols);  // 向右
    dfs(board, i, j-1, rows, cols);  // 向左
}

// 主函数：修改矩阵中的'O'为'X'
void solve(char** board, int boardSize, int* boardColSize) {
    if (board == NULL || boardSize == 0 || *boardColSize == 0) {
        return;
    }
    
    int rows = boardSize;
    int cols = *boardColSize;
    
    // 从边界出发，标记所有与边界相连的'O'为'#'
    for (int i = 0; i < rows; i++) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0, rows, cols);  // 第一列
        }
        if (board[i][cols - 1] == 'O') {
            dfs(board, i, cols - 1, rows, cols);  // 最后一列
        }
    }
    for (int j = 0; j < cols; j++) {
        if (board[0][j] == 'O') {
            dfs(board, 0, j, rows, cols);  // 第一行
        }
        if (board[rows - 1][j] == 'O') {
            dfs(board, rows - 1, j, rows, cols);  // 最后一行
        }
    }

    // 遍历整个矩阵，进行最后的修改
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';  // 被围绕的'O'改为'X'
            } else if (board[i][j] == '#') {
                board[i][j] = 'O';  // 与边界相连的'O'恢复
            }
        }
    }
}

int main() {
    // 示例1：创建二维矩阵
    char* board1[ROWS] = {
        (char[]){'X', 'X', 'X', 'X'},
        (char[]){'X', 'O', 'O', 'X'},
        (char[]){'X', 'X', 'O', 'X'},
        (char[]){'X', 'O', 'X', 'X'}
    };
    int colSize1 = COLS;

    solve(board1, ROWS, &colSize1);
    
    // 输出修改后的矩阵
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board1[i][j]);
        }
        printf("\n");
    }

    // 示例2：创建二维矩阵
    char* board2[ROWS] = {
        (char[]){'O', 'O', 'O', 'O'},
        (char[]){'O', 'X', 'O', 'X'},
        (char[]){'O', 'X', 'O', 'X'},
        (char[]){'O', 'O', 'O', 'O'}
    };
    int colSize2 = COLS;

    solve(board2, ROWS, &colSize2);
    
    // 输出修改后的矩阵
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
