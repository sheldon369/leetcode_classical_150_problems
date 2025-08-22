#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
//分析：首先列数递增，直至达到最右，此时行数递增，直至达到最下，然后左减，上减，涉及到两种翻转。
//每次翻转的标志是碰到数组的边界或者访问到过去访问过的元素

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int num = m * n;
        vector<int> res;
        bool visited[10][10]{ false };

        int i = 0;
        int j = 0;
        int count = 0;
        int state = 0;//右，下，左，上
        while (count < num) {
            if (state == 0) {
                while ( j < n && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    count++;
                    j++;
                }
                j--;
                i++;
            }
            else if (state == 1) {
                while (i < m && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    count++;
                    i++;
                }
                i--;
                j--;
            }
            else if (state == 2) {
                while ( j >= 0 && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    count++;
                    j--;
                }
                j++;
                i--;
            }
            else if (state == 3) {
                while ( i >= 0 && !visited[i][j]) {
                    res.push_back(matrix[i][j]);
                    visited[i][j] = true;
                    count++;
                    i--;
                }
                i++;
                j++;
            }

         
            state = (state + 1) % 4;

        }

        return res;

        
    }
};
