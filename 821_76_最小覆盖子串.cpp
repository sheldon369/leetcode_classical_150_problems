#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
//如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

//分析：使用两个指针begin end对s进行检索，无论何时都只有一个指针在动。
//当check失败时，我们移动右指针，直至成功（外层while）
//此时不断移动左指针（内层while），收缩答案，直到破坏了答案的性质，则回归到外层，继续移动右指针
//重复上述过程，直到左右指针均指向结尾


class Solution {
public:
    unordered_map<char, int> mapS;
    unordered_map<char, int> mapT;

    bool check() {
         for (const auto& p : mapT) {
            if (mapS[p.first] < p.second) {//若s中存在某字符c，使得c在s出现的次数小于c在t中出现的次数，则不构成覆盖
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int ansLeft{ -1 };
        int ansRight{ -1 };
        int ansLength{ INT_MAX };//记录成功的结果

        int ptrL{ 0 };
        int ptrR{ 0 };//滑动窗口指针

        for (char c : t) {
            mapT[c]++;
        }

        while (ptrR < s.size()) {
            mapS[s[ptrR]]++;
            
            while (ptrR < s.size() && check()) {//check成功,则右移左指针
                int l = ptrR - ptrL + 1;
                if (l < ansLength) {
                    ansLength = l;
                    ansLeft = ptrL;
                }
                mapS[s[ptrL++]]--;
            }
            ptrR++;
        }
        return ansLength <= s.size() ? s.substr(ansLeft, ansLength) : "";

    
    }
};