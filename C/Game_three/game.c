 #include "game.h"

 void InitBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
 }

//  void DisplayBoard(char board[ROW][COL], int row, int col) {
//     for (int i = 0; i < row; i++) {
//         // 打印数据
//         printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//         // 打印分割信息
//         if (i < row - 1) printf("---|---|---\n");
//     }
//  }
 
 void DisplayBoard(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        // 打印数据
        for (int j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);
            if (j < col - 1) printf("|");
        }
        printf("\n");

        // 打印分割信息

        if (i < row - 1) {
            for (int j = 0; j < col; j++) {
            printf("---");
            if (j < col - 1) printf("|");
            }
        }
        printf("\n");
    }
 }

 void PlayerMove(char board[ROW][COL], int row, int col) {
    int x = 0, y = 0;

    printf("玩家下棋:>\n");
    while (1) {
        printf("请输入坐标:>");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (board[x-1][y -1] == ' ') {
                board[x-1][y -1] = '*';
                break;
            }
            else printf("坐标被占用请选择其他坐标");
        }
        else printf("坐标非法，请重新输入\n");
    }
 }

void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("电脑下棋:>\n");
    int x = 0, y = 0;

    while(1) {
        x = rand() % row;
        y = rand() % col;
        if (board[x][y] == ' ') {
            board[x][y] = '#';
            break;
        }
    }
}

int IsFull(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (board[i][0] == ' ') return 0;
        }
    }
    return 1;
}

char IsWin(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
            return board[i][1];
        }
    }

    for (int i = 0; i < col; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
            return board[1][i];
        }
    }

    if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ') {
        return board[1][1];
    }

    if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ') {
        return board[1][1];
    }

    if (IsFull(board, row, col)) return 'Q';

    return 'C';
}
