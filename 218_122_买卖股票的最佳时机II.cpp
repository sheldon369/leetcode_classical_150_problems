#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ���������� prices ������ prices[i] ��ʾĳ֧��Ʊ�� i ��ļ۸�
//��ÿһ�죬����Ծ����Ƿ���� / ����۹�Ʊ�������κ�ʱ�� ��� ֻ�ܳ��� һ�� ��Ʊ����Ҳ�����ȹ���Ȼ���� ͬһ�� ���ۡ�
//���� ���ܻ�õ� ��� ���� ��

//�������ο�121��ֻ�������� difference < 0ʱѡ�����������ٵ��ӵ� profit �ϡ��൱��ÿ�춼����һ������,����ֻ�������������Ĳ���
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1;i < prices.size();i++) {
            int difference = prices[i] - prices[i - 1];
            if (difference > 0) {
                profit += difference;
            }
           
        }
        return profit;
    }
};