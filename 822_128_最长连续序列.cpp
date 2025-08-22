#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

//分析：O（n）则不能先对数组进行排序，我们首先使用set排除重复元素，接着我们对每个元素进行后继的查找。
//一个问题是若我们从序列的中间开始查找，必然产生冗余使得复杂度上升至n方，因此我们查找前保证查找元素为首个即可

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        unordered_set<int> set;
        for (int n : nums) {
            set.insert(n);
        }
        for (int n : set) {//对set元素进行遍历
            int currentNum = n;
            int  currentLength = 1;
            if (!set.count(currentNum - 1)) {
                while (set.count(currentNum + 1)) {
                    currentNum++;
                    currentLength++;
                }
            }
            ans = max(ans, currentLength);
        }
        return ans;


    }
};

