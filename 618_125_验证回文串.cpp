#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//字母和数字都属于字母数字字符。
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

class Solution {
public:
    bool isPalindrome(string s) {
        //处理字符串，删除非字母数字字符，并将大写转换为小写
        string str;
        for (int i = 0;i < s.size();i++) {
            if ('0' <= s[i] && '9' >= s[i] || 'a' <= s[i] && 'z' >= s[i])
                str += s[i];
            else if ('A' <= s[i] && 'Z' >= s[i])
                str += s[i] + 32;
        }
        int i = 0;
        int j = str.size() - 1;
        while (i <= j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;


    }
};