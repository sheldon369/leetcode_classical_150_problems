#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

//����һ���ַ��� s �������ҳ����в������ظ��ַ��� � �Ӵ� �ĳ��ȡ��Ӵ���Ҫ����
//����������ʹ��set��¼�ظ��ַ���һ�������ظ�set���㣬���¼�¼

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
            //i += length;��ֻ�ܽ��������������ͬ�����ַ����������ǵ��ַ������������֣����������
            i++;
            tab.clear();

        }
        return res;

    }
};

//�Ż����������ڣ�����λ��Ҳ�ǵ����ģ����Ե������ظ�ʱ�������������������Ųһλ����

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