/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-12-29 18:25:25
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-12-29 19:29:21
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode122\LeeCode122.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;  // 如果没有价格，最大利润为 0

    int max_profit = 0;

    // 遍历价格数组，找出所有的买入卖出机会
    for (int i = 1; i < pricesSize; i++) {
        // 如果今天的价格比昨天的价格高，就进行交易（卖出）
        if (prices[i] > prices[i - 1]) {
            max_profit += prices[i] - prices[i - 1];
        }
    }

    return max_profit;
}

int main() {
    // 示例1
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("最大利润：%d\n", maxProfit(prices1, size1));  // 输出：7

    // 示例2
    int prices2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("最大利润：%d\n", maxProfit(prices2, size2));  // 输出：4

    // 示例3
    int prices3[] = {7, 6, 4, 3, 1};
    int size3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("最大利润：%d\n", maxProfit(prices3, size3));  // 输出：0

    return 0;
}
