#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给定字符串 s 和 t ，判断 s 是否为 t 的子序列
//字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
//分析：一直在t中走，看能否匹配完s中的每个字符，一个指针指向s，一个指针指向t
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x = 0;
        if (s == "")
            return true;
        for (int i = 0;i < t.size();i++) {
            if (t[i] == s[x])
                x++;
            if (x == s.size())
                return true;
        }
        return false;
    }
};