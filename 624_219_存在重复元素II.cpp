#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;


/*给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        for (int i = 0;i < nums.size();i++) {
            m[nums[i]].push_back(i);
        }
        for (int i = 0;i < nums.size();i++) {
           
                for (int n : m[nums[i]]) {
                    if (n != i && abs(n - i) <= k)
                        return true;
                }
            

        }
        return false;



    }
};