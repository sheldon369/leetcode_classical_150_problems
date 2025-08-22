#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
//在每一天，你可以决定是否购买和 / 或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//返回 你能获得的 最大 利润 。

//分析：参考121，只是我们在 difference < 0时选择卖出，不再叠加到 profit 上。相当于每天都结算一次利润,利润只计算曲线上升的部分
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