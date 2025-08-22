#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm> //max
using namespace std;

//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

//分析：对于每个下标，分别找到左边最高的柱子lmax和右边最高的柱子rmax，则该列能接雨水 min{lmax,rmax} - 自身高度

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n);
        vector<int> rmax(n);
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] > max) {
                max = height[i];
            }
            lmax[i] = max;
        }
        max = 0;
        for (int i = n-1; i >= 0; i--) {
            if (height[i] > max) {
                max = height[i];
            }
            rmax[i] = max;
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(lmax[i], rmax[i]) - height[i];
        }
        return result;

    }
};