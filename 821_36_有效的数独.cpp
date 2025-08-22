#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
//数字 1 - 9 在每一行只能出现一次。
//数字 1 - 9 在每一列只能出现一次。
//数字 1 - 9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
//只需验证有效性，无需验证可解性

//分析：针对每行，每列，每个九宫格，设计一个长为[10]的bool型数组记录该元素是否出现过(实际用到1-9)
//显然，对于元素board[i][j],它属于row[i],column[j],matrix[i/3*3+j/3]
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10]{ false };
        bool column[9][10]{ false };
        bool matrix[9][10]{ false };
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.')
                    continue;
                int n = board[i][j] - '0';
                if (row[i][n] == true || column[j][n] == true || matrix[i / 3 * 3 + j / 3][n] == true)
                    return false;
                row[i][n] = true;
                column[j][n] = true;
                matrix[i / 3 * 3 + j / 3][n] = true;

            }
        }
        return true;

    }
};