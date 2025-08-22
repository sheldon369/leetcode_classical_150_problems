#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include<string>
using namespace std;

//����������ͨ����Ӵ���ߵ���͵�С��λֵ��ת�����γɵġ���С��λֵת��Ϊ�������������¹���
//�����ֵ������ 4 �� 9 ��ͷ����ѡ����Դ������м�ȥ�����ֵ�ķ��ţ����÷��Ÿ��ӵ��������ȥ��ֵ��Ȼ�����ಿ��ת��Ϊ�������֡�
//�����ֵ�� 4 �� 9 ��ͷ��ʹ�� ������ʽ����ʾ�����·����м�ȥһ�����ţ����� 4 �� 5 (V)�� 1 (I) : IV ��9 �� 10 (X)�� 1 (I)��IX����ʹ�����¼�����ʽ��4(IV)��9(IX)��40(XL)��90(XC)��400(CD) �� 900 (CM)��
//ֻ�� 10 �Ĵη���I, X, C, M���������������� 3 ���Դ��� 10 �ı������㲻�ܶ�θ��� 5 (V)��50(L) �� 500 (D)�������Ҫ�����Ÿ���4�Σ���ʹ�� ������ʽ��
//����һ������������ת��Ϊ�������֡�   1 <= num <= 3999

//��������ȡ��������λ�ϵ����֣�ǧλ��M��ɣ���λ��CDM��ɣ�ʮλ��XLC��ɣ���λ��IVX���

//�����������ȷ���������ֵĹ����ǣ������������ִ����ҵ�ÿһλ��ѡ�񾡿��ܴ�ķ���ֵ
//�����������ֵ�Ψһ��ʾ����Ϊ�˱�ʾһ������������ num������Ѱ�Ҳ����� num ��������ֵ���� num ��ȥ�÷���ֵ��Ȼ�����Ѱ�Ҳ����� num ��������ֵ�����÷���ƴ������һ���ҵ��ķ���֮��ѭ��ֱ�� num Ϊ 0�����õ����ַ�����Ϊ num ���������ֱ�ʾ��
//for (const auto& [value, symbol] : valueSymbols) { //�ṹ���󶨱��� valueSymbols(һ��pair����)��const��֤���޸ĶԵ�Ԫ�أ�pair��һ��Ԫ�ش浽value�У��ڶ���Ԫ�ش浽symbol��
//    while (num >= value) {
//        num -= value;
//        roman += symbol;
//    }

class Solution {
public:
    string intToRoman(int num) {
        unordered_map<char, int> tab = { {'I',1},{'V',5} ,{'X',10} ,{'L',50} ,{'C',100} ,{'D',500},{'M',1000} };
        int qian = num / 1000;
        int bai = (num - 1000 * qian) / 100;
        int shi = (num - 1000 * qian -100 * bai)/ 10;
        int ge = num - 1000 * qian - 100 * bai - 10 * shi;
        string  roman;
        for (int i = 0;i < qian;i++) {
            roman = roman + "M";
        }
        if (bai == 4)
            roman = roman + "CD";
        else if (bai == 9)
            roman = roman + "CM";
        else {
            if (bai >= 5) {
                roman = roman + "D";
                bai -= 5;
            }
            for (int i = 0;i < bai;i++) {
                roman = roman + "C";
            }
        }
        if (shi == 4)
            roman = roman + "XL";
        else if (shi == 9)
            roman = roman + "XC";
        else {
            if (shi >= 5) {
                roman = roman + "L";
                shi -= 5;
            }
            for (int i = 0;i < shi;i++) {
                roman = roman + "X";
            }
        }
        if (ge == 4)
            roman = roman + "IV";
        else if (ge == 9)
            roman = roman + "IX";
        else {
            if (ge >= 5) {
                roman = roman + "V";
                ge -= 5;
            }
            for (int i = 0;i < ge;i++) {
                roman = roman + "I";
            }
        }
        return roman;
    }
   
};

//test
int main() {
    Solution solution;
    int n;
    while (scanf("%d",&n) != EOF) {
      
        string str = solution.intToRoman(n);
        printf("%s\n", str.c_str());
    }

}