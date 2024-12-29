/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-12-29 18:25:25
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-12-29 19:07:36
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode121\LeeCode121.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;  // 如果没有价格，利润为 0

    // 初始化最小价格和最大利润
    int min_price = prices[0];
    int max_profit = 0;

    // 遍历股票价格
    for (int i = 1; i < pricesSize; i++) {
        // 更新最小价格
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        
        // 计算当前卖出所能获得的利润，并更新最大利润
        int profit = prices[i] - min_price;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}

int main() {
    // 示例1
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("最大利润：%d\n", maxProfit(prices1, size1));  // 输出：5

    // 示例2
    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("最大利润：%d\n", maxProfit(prices2, size2));  // 输出：0

    return 0;
}
