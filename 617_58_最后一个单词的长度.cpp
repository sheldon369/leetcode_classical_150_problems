#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

//����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ����� ���һ�� ���ʵĳ��ȡ�
//���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����

//�������Ӻ���ǰ��ֱ���ҵ��ո�
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;
        int flag = 0;
        for (int i = n - 1;i>=0;i--) {
            if (s[i] == '\ ' && flag == 1)
                break;
            else if (s[i] == '\ ')
                continue;
            flag = 1;
            length++;

        }
        return length;

    }
};