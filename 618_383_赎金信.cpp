#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
//如果可以，返回 true ；否则返回 false 。
//magazine 中的每个字符只能在 ransomNote 中使用一次。

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0;i < magazine.size();i++) {
            map[magazine[i]]++;
        }
        for (int j = 0;j < ransomNote.size();j++) {
            if (map[ransomNote[j]] <= 0)
                return false;
            else
                map[ransomNote[j]]--;
        }
        return true;
    }
};