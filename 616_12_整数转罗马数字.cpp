#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include<string>
using namespace std;

//罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：
//如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
//如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V)减 1 (I) : IV ，9 是 10 (X)减 1 (I)：IX。仅使用以下减法形式：4(IV)，9(IX)，40(XL)，90(XC)，400(CD) 和 900 (CM)。
//只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50(L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
//给定一个整数，将其转换为罗马数字。   1 <= num <= 3999

//分析：获取该数各个位上的数字，千位用M组成，百位用CDM组成，十位用XLC组成，个位用IVX组成

//标答：我们用来确定罗马数字的规则是：对于罗马数字从左到右的每一位，选择尽可能大的符号值
//根据罗马数字的唯一表示法，为了表示一个给定的整数 num，我们寻找不超过 num 的最大符号值，将 num 减去该符号值，然后继续寻找不超过 num 的最大符号值，将该符号拼接在上一个找到的符号之后，循环直至 num 为 0。最后得到的字符串即为 num 的罗马数字表示。
//for (const auto& [value, symbol] : valueSymbols) { //结构化绑定遍历 valueSymbols(一个pair集合)，const保证不修改对的元素，pair第一个元素存到value中，第二个元素存到symbol中
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