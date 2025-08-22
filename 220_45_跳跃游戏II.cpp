#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

//分析：在跳跃游戏的基础上，加入了判断到达nums[n - 1]的最小跳跃次数
//直观上感觉需要使用动态规划法，但是仍存在一个贪心的基本事实——使到达最后一个位置的跳跃次数最小，则之前需要维护到达所有位置的最小跳跃次数。

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_step(n);//初始化辅助数组记录到达每个索引的最低步数，长度为n，全部初始化为0
        if (n == 1) {
            return 0;
        }
        else {
            for (int i = 0; i < n;i++) {
                for (int j = i + 1; j <= i + nums[i] && j < n;j++) {
                    int temp = min_step[i] + 1;
                    if (min_step[j] == 0 || min_step[j] > temp) {
                        min_step[j] = temp;
                    }
                }
            }
        }
        return min_step[n - 1];



    }
};

//优化：滑动窗口
//随着step增加，不断更新能到达的区间[left, right]，当区间覆盖了n - 1的时候，得到step为答案。
// 
//以[2, 3, 1, 2, 4, 2, 3]为例，step = 1的时候区间为[1, 2](注意这个区间指的是下标)，遍历之后得到下一步的区间是[2, 4]，但是这里可以把已经计算过的部分去掉以达成O(N)的复杂度，也就是先将left更新为right + 1再更新right