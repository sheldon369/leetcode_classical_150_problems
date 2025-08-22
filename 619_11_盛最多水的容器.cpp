#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。

//分析：本题和接雨水比较像，但并不完全相同，本题简单的多
//选定两条垂线 i,h[i] 以及j,h[j]，则水的数量为 j-i * min{h[i],h[j]}
//最笨的方法，两两匹配，求最大值O(n2)
//优化：从两端开始，每次移动短的一边，则容量存在变大的可能性；反之，如果移动较长的一边，容量只可能变小
//则在此策略下，我们遍历了所有使当前容量变大的情况。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int column = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int h = height[i] > height[j] ? height[j] : height[i];
            int current = (j - i) * h;
            if (current > column)
                column = current;
            if (h == height[i])
                i++;
            else
                j--;

        }
        return column;

    }
};