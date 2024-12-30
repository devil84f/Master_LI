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

    // ����������ֱ��ʾһ�ν��׺����ν��׵��������
    int dp1_buy = -prices[0];  // ��1�ν��׵�����״̬����ʼ��Ϊ���ĵ�1��ɼ�
    int dp1_sell = 0;          // ��1�ν��׵�����״̬����ʼ��Ϊ0
    int dp2_buy = -prices[0];  // ��2�ν��׵�����״̬����ʼ��Ϊ���ĵ�1��ɼ�
    int dp2_sell = 0;          // ��2�ν��׵�����״̬����ʼ��Ϊ0

    // �������еĹɼ�
    for (int i = 1; i < pricesSize; i++) {
        // ���µ�1�ν��׵����������״̬
        dp1_buy = (dp1_buy > -prices[i]) ? dp1_buy : -prices[i];  // ����ʱ����
        dp1_sell = (dp1_sell > dp1_buy + prices[i]) ? dp1_sell : dp1_buy + prices[i];  // ����ʱ����

        // ���µ�2�ν��׵����������״̬
        dp2_buy = (dp2_buy > dp1_sell - prices[i]) ? dp2_buy : dp1_sell - prices[i];  // �ڶ�������ʱ����
        dp2_sell = (dp2_sell > dp2_buy + prices[i]) ? dp2_sell : dp2_buy + prices[i];  // �ڶ�������ʱ����
    }

    return dp2_sell;  // ����������󣬼�������ν��׺������
}

int main() {
    // ʾ��1
    int prices1[] = {3, 2, 6, 5, 0, 3};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("�������%d\n", maxProfit(prices1, size1));  // �����6

    // ʾ��2
    int prices2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("�������%d\n", maxProfit(prices2, size2));  // �����4

    // ʾ��3
    int prices3[] = {7, 6, 4, 3, 1};
    int size3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("�������%d\n", maxProfit(prices3, size3));  // �����0

    return 0;
}
