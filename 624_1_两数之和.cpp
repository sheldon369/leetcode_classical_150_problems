#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0;i < nums.size();i++) {
            for (int j = i + 1;j < nums.size();j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
            
           
            
        }
         return res;

    }
};