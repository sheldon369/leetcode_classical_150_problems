#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

//����һ���ַ��� s �����㷴ת�ַ����� ���� ��˳��
//���룺s = "the sky is blue"
//�����"blue is sky the"

//����:ʹ��˫ָ�뷨����ȡ�ַ�
//��ָ���������пո�ֱ���ҵ���һ���ǿո��ַ�����Ϊr
//��ָ�����ָ�뿪ʼ����ɨ�裬ֱ���ҵ���һ���ո񣬼�Ϊl
//����Ч�ַ�����substr[l+1,r-l]
//��r = l-1�����ѭ��ִ��,��ֹ����Ϊl=0��r<0
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int r = s.size() - 1;
        while (r >= 0) {
            while (r >= 0 && s[r] == ' ') r--;.//r >= 0��֤ s[r] ���ʲ������
            if (r < 0) break; //��s[0]��Ϊ�ո���r��Ϊ-1
            int l = r;
            while (l >= 0 && s[l] != ' ') l--;
            res = res + s.substr(l + 1, r - l)+ ' ';
            r = l - 1;
        }
        res.pop_back();
        return res;
  
    }
};