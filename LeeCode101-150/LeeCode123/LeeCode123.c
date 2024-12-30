/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-12-29 18:25:25
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-12-30 09:51:10
 * @FilePath: \Master_LI\LeeCode101-150\LeeCode123\LeeCode123.c
 * @Description: 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    // 定义变量，分别表示一次交易和两次交易的最大利润
    int dp1_buy = -prices[0];  // 第1次交易的买入状态，初始化为负的第1天股价
    int dp1_sell = 0;          // 第1次交易的卖出状态，初始化为0
    int dp2_buy = -prices[0];  // 第2次交易的买入状态，初始化为负的第1天股价
    int dp2_sell = 0;          // 第2次交易的卖出状态，初始化为0

    // 遍历所有的股价
    for (int i = 1; i < pricesSize; i++) {
        // 更新第1次交易的买入和卖出状态
        dp1_buy = (dp1_buy > -prices[i]) ? dp1_buy : -prices[i];  // 买入时利润
        dp1_sell = (dp1_sell > dp1_buy + prices[i]) ? dp1_sell : dp1_buy + prices[i];  // 卖出时利润

        // 更新第2次交易的买入和卖出状态
        dp2_buy = (dp2_buy > dp1_sell - prices[i]) ? dp2_buy : dp1_sell - prices[i];  // 第二次买入时利润
        dp2_sell = (dp2_sell > dp2_buy + prices[i]) ? dp2_sell : dp2_buy + prices[i];  // 第二次卖出时利润
    }

    return dp2_sell;  // 返回最大利润，即完成两次交易后的利润
}

int main() {
    // 示例1
    int prices1[] = {3, 2, 6, 5, 0, 3};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("最大利润：%d\n", maxProfit(prices1, size1));  // 输出：6

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
