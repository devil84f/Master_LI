/*
 * @Author: devil84f 1204259355@qq.com
 * @Date: 2024-12-01 21:09:10
 * @LastEditors: devil84f 1204259355@qq.com
 * @LastEditTime: 2024-12-01 21:19:05
 * @FilePath: \Master_LI\LeeCode51-100\LeeCode79\LeeCode79.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check(char** board, int boardSize, int boardColSize, int** visited, int i, int j, char* s, int sSize, int k) {
    if (board[i][j] != s[k]) {
        return false;
    } else if (k == sSize - 1) {
        return true;
    }
    visited[i][j] = true;
    bool result = false;
    for (int sel = 0; sel < 4; sel++) {
        int newi = i + directions[sel][0], newj = j + directions[sel][1];
        if (newi >= 0 && newi < boardSize && newj >= 0 && newj < boardColSize) {
            if (!visited[newi][newj]) {
                bool flag = check(board, boardSize, boardColSize, visited, newi, newj, s, sSize, k + 1);
                if (flag) {
                    result = true;
                    break;
                }
            }
        }
    }
    visited[i][j] = false;
    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int** visited = malloc(sizeof(int*) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        visited[i] = malloc(sizeof(int) * boardColSize[0]);
        memset(visited[i], 0, sizeof(int) * boardColSize[0]);
    }
    int wordSize = strlen(word);
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            bool flag = check(board, boardSize, boardColSize[0], visited, i, j, word, wordSize, 0);
            if (flag) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char* board[] = {
        "ABCE",
        "SFCS",
        "ADEE"
    };
    int boardColSize[] = {4, 4, 4};
    char word[] = "ABCCED";

    if (exist(board, 3, boardColSize, word)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
