/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-01-04 01:02:40
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-01-04 01:02:49
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode134\LeeCode134.c
 * @Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalTank = 0;  // 总油量
    int currTank = 0;   // 当前油量
    int startIndex = 0; // 起点加油站的索引

    for (int i = 0; i < gasSize; i++) {
        totalTank += gas[i] - cost[i]; // 计算每个加油站的油量差
        currTank += gas[i] - cost[i];  // 计算当前的油量

        // 如果当前油量不足以继续行驶，尝试从下一个加油站开始
        if (currTank < 0) {
            startIndex = i + 1;    // 下一个加油站作为起点
            currTank = 0;          // 重置当前油量
        }
    }

    // 如果总油量不足以完成一圈，返回 -1
    return totalTank >= 0 ? startIndex : -1;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    int gasSize = sizeof(gas) / sizeof(gas[0]);
    int costSize = sizeof(cost) / sizeof(cost[0]);

    int result = canCompleteCircuit(gas, gasSize, cost, costSize);
    printf("Result: %d\n", result);  // 输出 3

    return 0;
}
