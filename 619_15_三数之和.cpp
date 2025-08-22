#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

//给你一个整数数组 nums ，判断是否存在三元组[nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
//同时还满足 nums[i] + nums[j] + nums[k] == 0 。
//请你返回所有和为 0 且不重复的三元组。输出的顺序和三元组的顺序并不重要。

//分析：一旦确定某个数，剩下的问题是找到两数之和为一个特定的数，可以使用hash表查阅

//为了避免重复，我们将数组排序,第一个指针从负数检索到0，第一个数只允许是负数，第二个数允许从自己到 +的自己，第三个数补全
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        map<int, int> tab;
        for (int n : nums) {
            tab[n]++;
        }
        map<int, int>::iterator it;
        vector<int> vec;
        for (it = tab.begin();it != tab.end();it++) {
            vec.push_back(it->first);
        }
        int n = vec.size();
        for (int i = 0;  i < n &&vec[i] <= 0;i++) {
            /*if (tab[vec[i]] > 1) {
                if (tab.find(-2 * vec[i]) != tab.end()) {
                    vector<int> temp;
                    temp.push_back(vec[i]);
                    temp.push_back(vec[i]);
                    temp.push_back(-2 * vec[i]);
                    res.push_back(temp);   
                } 
            } */
            tab[vec[i]]--;
            for (int j = i; j < n && vec[j] <= -vec[i] ;j++) {
                if (tab[vec[j]] == 0)//应对 j = i 时，只有一个vec[i];
                    continue;
                tab[vec[j]]--;
                int remainer = - vec[i] - vec[j];
                if (tab.find(remainer) != tab.end()) {
                    if (tab[remainer] > 0 && remainer >= vec[j]) {
                        vector<int> temp;
                        temp.push_back(vec[i]);
                        temp.push_back(vec[j]);
                        temp.push_back(remainer);
                        res.push_back(temp);
                    }  
                }
                tab[vec[j]]++;
            } 
            tab[vec[i]]++;
        }
       /* if (tab[0] >= 3) {
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            res.push_back(temp);
        }*/
        return res;
       

    }
};
//「不重复」的本质是什么？我们保持三重循环的大框架不变，只需要保证：
//第二重循环枚举到的元素不小于当前第一重循环枚举到的元素；
//第三重循环枚举到的元素不小于当前第二重循环枚举到的元素。











// 打印三元组结果
void printResults(const vector<vector<int>>& res) {
    for (const auto& triplet : res) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0},
        {-2, 0, 1, 1, 2},
        {},
        {0, 1, 1},
        {-2, -1, -1, 0, 1, 2}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ":" << endl;
        vector<vector<int>> result = sol.threeSum(testCases[i]);
        printResults(result);
        cout << "--------" << endl;
    }

    return 0;
}