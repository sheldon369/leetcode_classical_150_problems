#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s �� ��ĸ��λ�ʡ�
//������ֻ��Ҫ��ÿ���ַ��ĳ���Ƶ���Ͻ��п�������

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        for (int i = 0;i < t.size();i++) {
            if (map.find(t[i]) == map.end() || map[t[i]] == 0)
                return false;
            map[t[i]]--;
        }
        return true;

    }
};