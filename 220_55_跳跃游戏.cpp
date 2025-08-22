#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


//给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

//分析：一个基本事实——我们所能达到的位置必然是连续的，因此我们只需要维护我们所能访问的最大下标，判定它是否大于等于n-1即可

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        int i = 0; // i为当前访问位置
        while (i <= max_index) {
            int temp = i + nums[i];
            if (temp >= max_index) {
                max_index = temp;
                if (max_index >= nums.size() - 1) { //程序仅仅在此判定返回true,故我们需要保证尽可能多的更新max_index，故上面的判定标准为temp >= max_index
                    //假设判定标准为 temp > max_index，则判定nums = [0]时发生错判，显然这个数组能抵达末尾，但我们判定为false
                    return true;
                }
            }
            i++;
        }

   
        return false;

    }
};