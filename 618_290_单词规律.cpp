#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//����һ�ֹ��� pattern ��һ���ַ��� s ���ж� s �Ƿ���ѭ��ͬ�Ĺ��ɡ�
//��������205ͬ���ַ������һ�ޣ�ֻ����map�б�Ϊ��string���������Ǹպ�������mapʵ��ӳ��

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