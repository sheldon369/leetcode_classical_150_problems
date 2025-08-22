#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
//分析：与205同构字符串如出一辙，只不过map中变为了string，这里我们刚好用两个map实现映射

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ptos;
        unordered_map<string,char> stop;
        vector<string> book;
        int i = 0;
        while (i < s.size()) {
            int begin = i;
            while (i < s.size() && s[i] != '\ ') i++;
            book.push_back(s.substr(begin, i - begin));
            i++;
        }
        if (book.size() != pattern.size())
            return false;
        for (int i = 0;i < pattern.size();i++) {
            if (ptos.find(pattern[i]) == ptos.end())
                ptos[pattern[i]] = book[i];
            else
                if (ptos[pattern[i]] != book[i])
                    return false;
            if (stop.find(book[i]) == stop.end())
                stop[book[i]] = pattern[i];
            else
                if (stop[book[i]] != pattern[i])
                    return false;
        }
        return true;


    }
};