#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;

//给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
//你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
//要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
//文本的最后一行应为左对齐，且单词之间不插入额外的空格。

//分析：首先需要确定一行中有多少个单词，假设有x个，则加上x-1个空格应小于等于maxWidth
//除最后一行外，如果要均匀分配空格，则需要用剩余空间除以空格数，并把余数都从左边的空格加起
//最后一行额外处理

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> length;
        vector<string> res;
        for (string s : words) {
            length.push_back(s.size());
        }
        int i = 0;
        while (i < words.size()) {
            int sum = -1;//额外处理计算第一个数之前的空位
            int begin = i;
            string temp = "";
            while (i < words.size()) {
                sum = sum + 1 + length[i];
                if (sum > maxWidth)
                    break;
                i++;
            }//i总是指向下一行的首位
            //if (i < words.size()) {//此时i指向刚好超出长度两位，因此我们回退一位
            //    i--;
            //}
            if (i == words.size() ||i - begin ==1) {//则串已经遍历到结尾,最后一行
                for (int k = begin; k < i; k++) {
                    temp += words[k];
                    if (k != i - 1) temp += " ";
                }
                temp += string(maxWidth - temp.size(), ' ');
                res.push_back(temp);
                continue;
            }
           
          
            int end = i;
            int total_length = 0;
            for (int j = begin;j < end;j++) {
                total_length += length[j];
            }
            //if (end - begin == 1) {//特别处理这行只能容纳一个字符
            //    res.push_back(words[begin]);
            //    continue;
            //}
            int product = (maxWidth - total_length)/(end - begin - 1);//这一行可能end - begin -1 =0
            int remainder = (maxWidth - total_length) - product * (end - begin - 1);
            
            int repeat = 1;
            for (int j = begin;j < end;j++) {
                temp = temp + words[j];
                for (int m = 0;m < product;m++)
                    temp = temp + " ";
                if (repeat <= remainder) {
                    temp = temp + " ";
                    repeat++;
                }
          
            }
            temp = temp.substr(0, maxWidth);
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
    int maxWidth = 16;

    vector<string> result = sol.fullJustify(words, maxWidth);

    cout << "Justified Text:\n";
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}