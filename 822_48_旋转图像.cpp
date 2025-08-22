#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�
//������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��


//������
//��1��ʹ�ø������飬��i�б�Ϊ��n-i-1�У���matrix[row][col]��λ��Ϊmatrix[col][n-row-1],
//�÷���ȱ����ռ���˶���ľ���ռ�

//��2����ˮƽ����(matrix[row][col]��matrix[n-row-1][col]�����������ضԽ��߷��ۣ�matrix[row][col]��matrix[col][row]������
//�÷���ռ�ݶ���洢�ռ�

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size() ;
        for (int row = 0;row < n / 2;row++) { //�з�ת
            for (int col = 0;col < n;col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[n - row - 1][col];
                matrix[n - row - 1][col] = temp;
            }
        }
        for (int row = 0;row < n - 1 ;row++) { //���Խ��߷�ת
            for (int col = row + 1;col < n ;col++) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }

    }
};