#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

//给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//输入：s = "the sky is blue"
//输出："blue is sky the"

//分析:使用双指针法来提取字符
//右指针跳过所有空格，直至找到第一个非空格字符，记为r
//左指针从右指针开始向左扫描，直至找到第一个空格，记为l
//则有效字符串在substr[l+1,r-l]
//令r = l-1，则可循环执行,终止条件为l=0，r<0
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int r = s.size() - 1;
        while (r >= 0) {
            while (r >= 0 && s[r] == ' ') r--;.//r >= 0保证 s[r] 访问不会出错
            if (r < 0) break; //若s[0]仍为空格，则r减为-1
            int l = r;
            while (l >= 0 && s[l] != ' ') l--;
            res = res + s.substr(l + 1, r - l)+ ' ';
            r = l - 1;
        }
        res.pop_back();
        return res;
  
    }
};