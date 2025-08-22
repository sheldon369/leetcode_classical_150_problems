#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

//分析：从后往前，直到找到空格
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;
        int flag = 0;
        for (int i = n - 1;i>=0;i--) {
            if (s[i] == '\ ' && flag == 1)
                break;
            else if (s[i] == '\ ')
                continue;
            flag = 1;
            length++;

        }
        return length;

    }
};