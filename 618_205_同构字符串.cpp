#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给定两个字符串 s 和 t ，判断它们是否是同构的。
//如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0;i < s.size();i++) {
            if (map.find(s[i]) == map.end())
                //没找到该元素
                map[s[i]] = t[i];
            else 
                if (map[s[i]] != t[i] )
                    return false;
     
        }
        //单独判断是否存在多个值指向同一个值,如b->b,d->b
        unordered_map<char, int> map2;
        for (auto& pair : map) {
            map2[pair.second]++;
            if (map2[pair.second] > 1) {
                return false;
            }

        }

        return true;

    }
};

//标答：维护两张哈希表，分别记录s to t, t to s（更优）