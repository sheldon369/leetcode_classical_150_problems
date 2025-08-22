#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
//同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//I 可以放在 V(5) 和 X(10) 的左边，来表示 4 和 9。
//X 可以放在 L(50) 和 C(100) 的左边，来表示 40 和 90。
//C 可以放在 D(500) 和 M(1000) 的左边，来表示 400 和 900。
//给定一个罗马数字，将其转换成整数。

//分析：
//特殊组合包括：IV,IX,XL,XC,CD,CM,其他只需要把字符串进行拆分，然后映射相加即可。

//标准答案：
//不使用特殊判别分支排除六种情况，而是判定当前字符是否比右边字符更小，若更小则自己取值为负！
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

