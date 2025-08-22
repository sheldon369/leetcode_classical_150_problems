#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;


//给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其总和大于等于 target 的长度最小的 子数组[numsl, numsl + 1, ..., numsr - 1, numsr] ，
//并返回其长度。如果不存在符合条件的子数组，返回 0 。

//分析：由于全是正数，只要和没超过target就可以加，超过了就从下一个数重新开始,我们可以维持滑动窗口，避免过多的冗余
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;//start被动更新，标记sum计算的起始位置
        int end = 0;//end主动更新
        int sum = 0;//滑动窗口的总值
        int res = n + 1;//全局最优解
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {//当超额后删除的为前缀，故可能删除多个
                res = min(end - start + 1, res);
                sum -= nums[start];
                start++;
            }
            end++;
         }
        res = res > n ? 0 : res;
        return res;

    }
};

