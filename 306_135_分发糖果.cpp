#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。你需要按照以下要求，给这些孩子分发糖果：
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

//例 :5 7 8 3 4 2 1
//分析：将问题分解为左规则和右规则
//左规则：从左往右分配，设相邻元素为a ,b ，如果rate(b) > rate(a),则 num[b] = num[a] + 1 ,否则 num[b] = 1
//通过左规则构造，我们保证有从左往右所有升序二元组构成了最低分配，而降序二元组需要从右往左，进行二次判定
//右规则：从右往左分配，设相邻元素为a ,b ，如果rate(a) > rate(b),则 temp = num[a] + 1 ,num[b] = max{num[b],temp}

//核心：我们分析整体分配的柱状图，必然构成波浪形柱状图，如例子的分配结果为
//1231211 ->  1231321,任何一个非1的数 a 必然存在一段紧挨着 a-1，而我们的设计保证了每一个非1的数都将从一端的a-1 构造而来



class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int result = 0;
        vector<int> assign(n);
        assign[0] = 1;
        for (int i = 1;i < n;i++) {
            if (ratings[i] > ratings[i - 1]) {
                assign[i] = assign[i - 1] + 1;
            }
            else {
                assign[i] = 1;
            }
        }
        for (int i = n - 2;i >= 0;i--) {
            if (ratings[i] > ratings[i + 1]) {
                int temp = assign[i + 1] + 1;
                if (assign[i] < temp) {
                    assign[i] = temp;
                }
            }
        }
        for (int nums : assign) {
            result += nums;
        }
        return result;

    }
};