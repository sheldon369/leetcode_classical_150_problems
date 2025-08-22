#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//分析：给定行数r时，则输出在r行，每组竖着r个数字，斜着r-2个数字

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        vector<vector<char>> out(numRows, vector<char>(1000));
        int i = 0;
        int c = 0;
        int r = 0;
        int up = 0;//标志，=0则向下生成，=1则向上生成
        while (i < s.size()) {
            out[c][r] = s[i];
            i++;
            if (numRows == 1)
                r++;
            else if (up == 0 && c < numRows) {
                c++;
                if (c == numRows) {
                    c -= 2;
                    r++;
                    up = 1;
                }
            }
            else if (c >= 0 && up == 1) {
                c--;
                r++;
                if (c == -1) {
                    c += 2;
                    r--;
                    up = 0;
                }
            }
        }
        for (int k = 0;k < numRows;k++) {
            for (int j = 0;j < 1000;j++)
            {
                if (out[k][j] != '\0')
                    res = res + out[k][j];
            }
        }
        return res;

    }
};
//改进：我们只需要保证每行的相对顺序即可，不需要存储额外的空格，因此每次添加使用push_back即可，只需要关注插入哪一行
string convert(string s, int numRows) {
    string res;
    vector<string> out(numRows);
    int i = 0;
    int c = 0;
    int up = 0;//标志，=0则向下生成，=1则向上生成
    if (numRows == 1)
        return s;
    while (i < s.size()) {
        out[c].push_back(s[i]);
        i++;
        if (up == 0) {
            c++;
            if (c == numRows) {
                c -= 2;
                up = 1;
            }
        }
        else {
            c--;
            if (c == -1) {
                c += 2;
                up = 0;
            }
            
        }
   
    }
    for (int k = 0;k < numRows;k++) {
        res = res + out[k];
    }
    return res;

}

int main() {
    Solution sol;
    string res = sol.convert("PAYPALISHIRING", 3);
    printf("%s", res.c_str());
    return 0;
}