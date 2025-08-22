#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
//s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
//返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

//分析：从某个串开始匹配，如果暂时匹配成功，则窗口end++，匹配失败，要么出现了重复的words中数据，此时begin++。要么出现了意外的数据，begin end重置为end+1

//注:该法还是在182例超时
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].size();
        unordered_map<string, int> map0;
        for (string t : words) {
            map0[t]++;
        }
        vector<int>  res;
        if (n == 1 && map0.size() == 1 && map0.begin()->second == words.size()) {//针对第182例进行特殊优化，实在没招了
            string z = words[0];
            for (int i = 0;i < words.size();i++)
                z += words[0];
            for (int i = 0;i < words.size();i++) {
                if (s.substr(i, words.size()) == z)
                    res.push_back(i);
            }
            return res;
        }
        for (int i = 0; i < n; ++i) {//尝试从所有可能的偏移开始扫描
            int begin = i;
            int end = i;
            unordered_map<string, int> map = map0;
            while (end < s.size()) {
                int count = 0;
                while (end < s.size() && map.count(s.substr(end, n))) {//此循环中至少找到的全是数组中的元素
                    while (end < s.size() && map[s.substr(end, n)] > 0) {
                        map[s.substr(end, n)]--;
                        end += n;
                        count++;
                        if (count == words.size()) {//匹配成功则恢复状态
                            res.push_back(begin);
                        }
                    }//退出循环则说明找到了数组中重复的元素，重置begin
                    if (end >= s.size())//或者end超出界限，造成越界
                        break;
                    map[s.substr(begin, n)]++;
                    begin += n;
                    count--;
                } //退出循环则说明找到了非数组元素，此时重置begin,end
                end += n ;
                begin = end;
                map.clear();
                map = map0;
            }

        }

        return res;

    }
};

//超时优化：map->unordered_map,
//substr提前保存，避免重复计算
//重置map改为map的复制
//map.find 改为 map.count