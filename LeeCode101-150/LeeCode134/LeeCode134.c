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
    int totalTank = 0;  // ������
    int currTank = 0;   // ��ǰ����
    int startIndex = 0; // ������վ������

    for (int i = 0; i < gasSize; i++) {
        totalTank += gas[i] - cost[i]; // ����ÿ������վ��������
        currTank += gas[i] - cost[i];  // ���㵱ǰ������

        // �����ǰ���������Լ�����ʻ�����Դ���һ������վ��ʼ
        if (currTank < 0) {
            startIndex = i + 1;    // ��һ������վ��Ϊ���
            currTank = 0;          // ���õ�ǰ����
        }
    }

    // ������������������һȦ������ -1
    return totalTank >= 0 ? startIndex : -1;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    int gasSize = sizeof(gas) / sizeof(gas[0]);
    int costSize = sizeof(cost) / sizeof(cost[0]);

    int result = canCompleteCircuit(gas, gasSize, cost, costSize);
    printf("Result: %d\n", result);  // ��� 3

    return 0;
}
