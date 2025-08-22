#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//strs[i] 如果非空，则仅由小写英文字母组成

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int res = 0;
        int flag = 0;
        for (int i = 0;i < strs[0].size();i++) {
            for (int j = 1;j < strs.size();j++) {
                if (strs[j][i] != strs[0][i] || strs[j][i] == '\0') {
                    flag = 1;
                }
            }
            if (flag == 0) {
                res++;
            }
            else {
                break;
            }
        }
        return strs[0].substr(0,res);

    }
};