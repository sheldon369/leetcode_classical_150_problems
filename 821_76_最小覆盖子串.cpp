#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ���
//��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��

//������ʹ������ָ��begin end��s���м��������ۺ�ʱ��ֻ��һ��ָ���ڶ���
//��checkʧ��ʱ�������ƶ���ָ�룬ֱ���ɹ������while��
//��ʱ�����ƶ���ָ�루�ڲ�while���������𰸣�ֱ���ƻ��˴𰸵����ʣ���ع鵽��㣬�����ƶ���ָ��
//�ظ��������̣�ֱ������ָ���ָ���β


class Solution {
public:
    unordered_map<char, int> mapS;
    unordered_map<char, int> mapT;

    bool check() {
         for (const auto& p : mapT) {
            if (mapS[p.first] < p.second) {//��s�д���ĳ�ַ�c��ʹ��c��s���ֵĴ���С��c��t�г��ֵĴ������򲻹��ɸ���
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int ansLeft{ -1 };
        int ansRight{ -1 };
        int ansLength{ INT_MAX };//��¼�ɹ��Ľ��

        int ptrL{ 0 };
        int ptrR{ 0 };//��������ָ��

        for (char c : t) {
            mapT[c]++;
        }

        while (ptrR < s.size()) {
            mapS[s[ptrR]]++;
            
            while (ptrR < s.size() && check()) {//check�ɹ�,��������ָ��
                int l = ptrR - ptrL + 1;
                if (l < ansLength) {
                    ansLength = l;
                    ansLeft = ptrL;
                }
                mapS[s[ptrL++]]--;
            }
            ptrR++;
        }
        return ansLength <= s.size() ? s.substr(ansLeft, ansLength) : "";

    
    }
};