#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//分析：如果对字母异位词进行排序，则同一类对应唯一的一个键。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        for (auto& p : mp) {//遍历mp
            ans.push_back(p.second);

        }
        return ans;
    }
};
