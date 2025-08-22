#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。子串需要连续
//分析：不断使用set记录重复字符，一旦出现重复set清零，重新记录

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> tab;
        int i = 0;
        int res = 0;
        while (i < s.size()) {
            int length = 0;
            while (i + length < s.size() && tab.count(s[i+length]) == 0) {
                tab.insert(s[i + length]);
                length++;

            }
            res = max(res, length);
            //i += length;这只能解决出现连续两个同样的字符，假设它们的字符并不连续出现，则出现问题
            i++;
            tab.clear();

        }
        return res;

    }
};

//优化：滑动窗口，结束位置也是递增的，所以当出现重复时，我们总是令起点往后挪一位即可

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> tab;
        int begin = 0;
        int end = 0;
        int res = 0;
        while (end < s.size()) {
            while (end < s.size() && tab[s[end]] == 0) {
                tab[s[end]]++;
                end++;
            }
            res = max(res, end-begin);
            tab[s[begin]]--;
            begin++;
        }
        return res;

    }
};