#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//��дһ���㷨���ж�һ���� n �ǲ��ǿ�������
//���������� ����Ϊ��
//����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
//Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
//���������� ���Ϊ 1����ô��������ǿ�������
//��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��

//������ά��һ��map��¼���ֹ����ݱ��������ظ���˵��ѭ������Ȼ���ǲ���֪���᲻�ᶼѭ��(�ᣬ�����㶨��)

class Solution {
public:
    bool isHappy(int n) {
        map<int, int>  map;//map��¼����������ϣ�����ظ������Ϊset ���� set.count();
        int k = n;
        while (k != 1) {
            int m = 0;
            string s = to_string(k);
            for (int i = 0;i < s.size();i++) {
               m += pow(s[i] - '0', 2);
            }
            k = m;
            map[k]++;
            if (map[k] > 1)
                return  false;
        }
        return true;
        



    }
};