#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

//分析：依旧双指针，但是设置额外flag记录此元素是否重复过

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  b = 0;//b记录正确的新数组索引
        int  pre = 10000;
        int  flag = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != pre) {
                flag = 0;
                pre = nums[i];
                nums[b] = nums[i];
                b++;
            }
            else if (nums[i] == pre && flag == 0) {//两个重复元素
                //此处必须加上else，否则上个if完成对函数的修改之后可能重新进入该语句判别
                flag = 1;
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
    vector<int> nums1 = { 1,1,1,2,2,3 };



    int k = solution.removeDuplicates(nums1);

    // 输出合并后的nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // 输出：1 2 2 3 5 6
    cout << k << endl;
    return 0;
}