#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

//���������ַ��� haystack �� needle �������� haystack �ַ������ҳ� needle �ַ����ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ������� needle ���� haystack ��һ���֣��򷵻� - 1 ��
class Solution {
public:
    int strStr(string haystack, string needle) {
		int pos = haystack.find(needle, 0);//find("����Ԫ��",Ѱ�ҵ���ʼλ��),����ֵΪ��һ��ƥ�䴮�ĵ�һ���ַ����±�
		if (pos == string::npos) {//û�ҵ���string::npos=-1
			return -1;
		}
		return pos;
    }
};