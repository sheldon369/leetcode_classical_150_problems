#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ��
//��ʹ�� ԭ�� �㷨��

//������ʹ��O��m+n���ռ䣬��ɨ��һ�ξ��󣬼�¼�������г��ֹ�0

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