#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t ��������
//�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ�����
//������һֱ��t���ߣ����ܷ�ƥ����s�е�ÿ���ַ���һ��ָ��ָ��s��һ��ָ��ָ��t
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x = 0;
        if (s == "")
            return true;
        for (int i = 0;i < t.size();i++) {
            if (t[i] == s[x])
                x++;
            if (x == s.size())
                return true;
        }
        return false;
    }
};