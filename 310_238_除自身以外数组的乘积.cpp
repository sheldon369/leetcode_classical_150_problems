#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

//请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

//分析：结果可以存储在int类型中，且不允许使用除法，因此我们不可以算出所有元素的乘积再除以某元素自身的值(本质：如果出现元素0，则该方法失效！)
//我们考虑用前缀和 以及 后缀和分别存储 i之前以及之后的元素的和，空间复杂度 O（2n）

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> pre(n);
        vector<int> suc(n);
        int product = 1;
        pre[0] = 1;
        suc[n-1] = 1;
        for (int i = 1;i < n;i++) {
            product *= nums[i - 1];
            pre[i] = product;
        }
        product = 1;
        for (int i = n-2;i >= 0 ;i--) {
            product *= nums[i + 1];
            suc[i] = product;
        }
        for (int i = 0;i < n;i++) {
            answer[i] = pre[i] * suc[i];
        }
        return answer;
    }
};

//解2：优化空间复杂度为0（1）
//显然我们必须使用answer来存储最终的答案，而answer仅在最后一步才被使用
//故我们可以采用anwser存储原解中的pre数组，随后从右往左，product实际记录了累积的suc，直接更新answer[i] = product * answer[i]即可，则该法没有借用额外的空间