#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，
//请你从数组中找出满足相加之和等于目标数 target 的两个数。
//仅存在一个有效答案，只使用常量级的额外空间

//分析：两个指针，ab，b搜索至首位超过target的元素，搜索失败，则a向右移动一位，b搜索范围减小一位

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int begin = 0;
        int end = 1;
        while (end < numbers.size()-1 && numbers[0] + numbers[end] < target) end++;//end指向的位置有两数之和 大于等于target 或者指向数组末尾
        while (begin < end) {
            int i = end;
            while (i > begin) {
                if (numbers[begin] + numbers[i] == target) {
                    res.push_back(begin + 1);
                    res.push_back(i + 1);
                    return res;
                }
                else if (numbers[begin] + numbers[i] < target) {//最大的b加上begin都小，则减小b无意义
                    begin++;
                    continue;
                }
                i--;
            }
            begin++;
         
        }
        return res;
    
        

    }
};