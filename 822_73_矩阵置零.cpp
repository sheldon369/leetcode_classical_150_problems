#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。
//请使用 原地 算法。

//分析：使用O（m+n）空间，先扫描一次矩阵，记录哪行哪列出现过0

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m[200]{ 0 };
        int n[200]{ 0 };
        int numOfCol{};
        for (int row = 0;row < matrix.size();row++) {
            numOfCol = matrix[row].size();
            for (int col = 0;col < numOfCol;col++) {
                if (matrix[row][col] == 0) {
                    m[row] = 1;
                    n[col] = 1;
                }
            }
        }
        for (int i = 0;i < 200;i++) {
            if (m[i] == 1) {
                for (int col = 0;col < numOfCol;col++)
                    matrix[i][col] = 0;
            }
        }
        for (int i = 0;i < 200;i++) {
            if (n[i] == 1) {
                for (int row = 0;row < matrix.size();row++) 
                    matrix[row][i] = 0;
            }
        }


    }
};