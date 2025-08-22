#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回 - 1 。
class Solution {
public:
    int strStr(string haystack, string needle) {
		int pos = haystack.find(needle, 0);//find("待找元素",寻找的起始位置),返回值为第一个匹配串的第一个字符的下标
		if (pos == string::npos) {//没找到，string::npos=-1
			return -1;
		}
		return pos;
    }
};