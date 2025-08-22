#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

//在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。
//你从其中的一个加油站出发，开始时油箱为空。
//给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1 。
//如果存在解，则输入 保证 它是 唯一 的。

//分析： 初始时油箱为空，至少需要保证 gas[i] >= cost[i]
//假设能从 x到达y，但是到达不了y+1，则从x到y中任一点k出发都不可能到达y+1，因为既然从x能到k，则在k时的汽油余量必然大于等于0，若直接从k出发只可能让汽油减少
//计算difference函数，我们的目标是在difference中找到一串序列，使得它们的前缀和总是大于等于0.
//我们使用逻辑循环队列维护，若从某点出发计算前缀和小于0，则下次从下一位重新计算即可


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;
        int n = gas.size();
        int step = 0;
        vector<int> difference;
        for (int i = 0;i < n;i++) {
            difference.push_back(gas[i] - cost[i]);
        }
        int i = 0;
        while (i < n) {

            while (i < n && difference[i] < 0) i++; // 跳过负起点
            if (i >= n) break;

            int total = 0;  // 前缀和
            int steps = 0;  // 已经走的步数
            int start = i;

            // 模拟环形路径
            while (steps < n) {
                int idx = (start + steps) % n;
                total += difference[idx];
                if (total < 0) {
                    break; // 此路径不成立，从下一位重新找起点
                }
                steps++;
            }

            if (steps == n) {
                return start;
            }
            else {
                i = i + steps + 1;// 跳过尝试失败的所有中间站点
            }
        }

        return -1;
    }
};



int main() {
    Solution sol;
    pair<vector<int>, vector<int>> testCases =
    { {1,2,3,4,5}, {3,4,5,1,2} };  // expected: 3
        
    int result = sol.canCompleteCircuit(testCases.first, testCases.second);
    printf("%d", result);
    return 0;
}