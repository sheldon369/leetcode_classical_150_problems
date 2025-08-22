#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;


/*����һ���������� nums ��һ������ k ���ж��������Ƿ�������� ��ͬ������ i �� j ������ nums[i] == nums[j] �� abs(i - j) <= k ��������ڣ����� true �����򣬷��� false */

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