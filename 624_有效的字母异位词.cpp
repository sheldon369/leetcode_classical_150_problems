#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
//分析：只需要从每个字符的出现频度上进行考量即可

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        for (int i = 0;i < t.size();i++) {
            if (map.find(t[i]) == map.end() || map[t[i]] == 0)
                return false;
            map[t[i]]--;
        }
        return true;

    }
};