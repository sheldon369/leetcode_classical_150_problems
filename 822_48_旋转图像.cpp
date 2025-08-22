#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。


//分析：
//解1：使用辅助数组，第i行变为第n-i-1列，则matrix[row][col]新位置为matrix[col][n-row-1],
//该法的缺陷是占据了额外的矩阵空间

//解2：先水平翻折(matrix[row][col]与matrix[n-row-1][col]交换），再沿对角线翻折（matrix[row][col]与matrix[col][row]交换）
//该法不占据额外存储空间

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size() ;
        for (int row = 0;row < n / 2;row++) { //行翻转
            for (int col = 0;col < n;col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[n - row - 1][col];
                matrix[n - row - 1][col] = temp;
            }
        }
        for (int row = 0;row < n - 1 ;row++) { //主对角线翻转
            for (int col = row + 1;col < n ;col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

    }
};