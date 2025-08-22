#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

//分析：对于每组 i 和 j（其中 j > i）我们需要找出 max(prices[j]−prices[i])。
//解1：
//记录之前遍历的所有元素的历史最低点，并考虑在当天卖出所能获取的利润，维护最大利润


//解2：
//维护一个最大利润profit。每当遍历一个新元素，计算该元素与上个元素的差值，加入profit，一旦profit < 0，则说明之前记录的买卖方式亏损，不如从当天开始买，将 profit 重置为0

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int max = 0;
        for (int i = 1;i < prices.size();i++) {
            int difference = prices[i] - prices[i - 1];
            profit += difference;
            if (profit < 0) {
                profit = 0;
            }
            else {
                if (profit > max) {
                    max = profit;
                }
            }
        }
        return max;
    }
};