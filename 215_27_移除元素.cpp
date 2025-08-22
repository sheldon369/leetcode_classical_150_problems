#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

//假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
//（1）更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
//（2）返回 k

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //分析：双指针法，指针i正常遍历（快指针），b记录非val的值的数量，重写nums[b]上的每个值
        int  b = 0;
        for (int i = 0;i < nums.size() ;i++) {
            if ( nums[i] != val ) {
                nums[b] = nums[i];
                b++;
            }
        }
        return b;

    }
};


//法二，双指针优化：
//注意到法一中对重复元素进行了重复赋值，比方说1，2，3删除2，我们对1进行了重复赋值，且保留了除去val的值在原数组中的位置，这点是完全不必要的。
//我们可以从左右两边共同遍历数组，左指针找到等于val的那个值，右指针被动每次移动一次，左指针赋值右指针的值。若复制过来的值依然等于val，则重复改操作，直至双指针相遇
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[--right];
            }
            else {
                left++;
            }
        }
        return left;
    }
};
