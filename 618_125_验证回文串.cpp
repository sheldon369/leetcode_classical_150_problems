#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��
//��ĸ�����ֶ�������ĸ�����ַ���
//����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��

class Solution {
public:
    bool isPalindrome(string s) {
        //�����ַ�����ɾ������ĸ�����ַ���������дת��ΪСд
        string str;
        for (int i = 0;i < s.size();i++) {
            if ('0' <= s[i] && '9' >= s[i] || 'a' <= s[i] && 'z' >= s[i])
                str += s[i];
            else if ('A' <= s[i] && 'Z' >= s[i])
                str += s[i] + 32;
        }
        int i = 0;
        int j = str.size() - 1;
        while (i <= j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;


    }
};