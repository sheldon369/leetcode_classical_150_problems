#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�
//��������������rʱ���������r�У�ÿ������r�����֣�б��r-2������

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        vector<vector<char>> out(numRows, vector<char>(1000));
        int i = 0;
        int c = 0;
        int r = 0;
        int up = 0;//��־��=0���������ɣ�=1����������
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
//�Ľ�������ֻ��Ҫ��֤ÿ�е����˳�򼴿ɣ�����Ҫ�洢����Ŀո����ÿ�����ʹ��push_back���ɣ�ֻ��Ҫ��ע������һ��
string convert(string s, int numRows) {
    string res;
    vector<string> out(numRows);
    int i = 0;
    int c = 0;
    int up = 0;//��־��=0���������ɣ�=1����������
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