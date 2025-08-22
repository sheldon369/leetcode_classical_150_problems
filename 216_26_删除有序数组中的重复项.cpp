#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
//
//考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
//（1）更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
//（2）返回 k 。

//分析：实现思路参考215_27移除特定元素的解法一，将特定元素变为重复元素

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  b = 0;
        int  flag = 10000;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != flag) {
                flag = nums[i];
                nums[b] = nums[i];
                b++;
            }
        }
        return b;

    }
};

int main() {
    Solution solution;

    // 测试用例1
    vector<int> nums1 = { 0,0,1,1,1,2,2,3,3,4 };
 


    int k = solution.removeDuplicates(nums1);

    // 输出合并后的nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // 输出：1 2 2 3 5 6
    cout << k << endl;
    return 0;
}