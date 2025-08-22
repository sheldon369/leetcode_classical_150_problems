#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//���������ַ��� s �� t ���ж������Ƿ���ͬ���ġ�
//��� s �е��ַ����԰�ĳ��ӳ���ϵ�滻�õ� t ����ô�������ַ�����ͬ���ġ�

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0;i < s.size();i++) {
            if (map.find(s[i]) == map.end())
                //û�ҵ���Ԫ��
                map[s[i]] = t[i];
            else 
                if (map[s[i]] != t[i] )
                    return false;
     
        }
        //�����ж��Ƿ���ڶ��ֵָ��ͬһ��ֵ,��b->b,d->b
        unordered_map<char, int> map2;
        for (auto& pair : map) {
            map2[pair.second]++;
            if (map2[pair.second] > 1) {
                return false;
            }

        }

        return true;

    }
};

//���ά�����Ź�ϣ���ֱ��¼s to t, t to s�����ţ�