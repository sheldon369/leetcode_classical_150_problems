#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

//ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��
//ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������
//I ���Է��� V(5) �� X(10) ����ߣ�����ʾ 4 �� 9��
//X ���Է��� L(50) �� C(100) ����ߣ�����ʾ 40 �� 90��
//C ���Է��� D(500) �� M(1000) ����ߣ�����ʾ 400 �� 900��
//����һ���������֣�����ת����������

//������
//������ϰ�����IV,IX,XL,XC,CD,CM,����ֻ��Ҫ���ַ������в�֣�Ȼ��ӳ����Ӽ��ɡ�

//��׼�𰸣�
//��ʹ�������б��֧�ų���������������ж���ǰ�ַ��Ƿ���ұ��ַ���С������С���Լ�ȡֵΪ����
//for (int i = 0; i < n; ++i) {
//    int value = symbolValues[s[i]];
//    if (i < n - 1 && value < symbolValues[s[i + 1]]) {
//        ans -= value;
//    }
//    else {
//        ans += value;
//    }
//}

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> tab = { {'I',1},{'V',5} ,{'X',10} ,{'L',50} ,{'C',100} ,{'D',500},{'M',1000} };
        int sum = 0;
        for (int i = 0;i < s.size();i++) {
            if (s.substr(i,2) == "IV") {
                sum += 4;
                i++;
                
            }
            else if (s.substr(i, 2) == "IX") {
                sum += 9;
                i++;
               
            }
            else if (s.substr(i, 2) == "XL") {
                sum += 40;
                i++;
               
            }
            else if (s.substr(i, 2) == "XC") {
                sum += 90;
                i++;
              
            }
            else if (s.substr(i, 2) == "CD") {
                sum += 400;
                i++;
              
            }
            else if (s.substr(i, 2) == "CM") {
                sum += 900;
                i++;
              
            }
            else {
                sum += tab[s[i]];
              
            }
        }
        return sum;
    }
};

//test
int main() {
    Solution solution;
    string str;
    char arr[100];
    while (scanf("%s",arr) != EOF) {
        str = arr;
       int n = solution.romanToInt(str);
       printf("%d\n", n);
    }

}

