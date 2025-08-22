#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
//��������������������ֱ���ﵽ���ң���ʱ����������ֱ���ﵽ���£�Ȼ��������ϼ����漰�����ַ�ת��
//ÿ�η�ת�ı�־����������ı߽���߷��ʵ���ȥ���ʹ���Ԫ��

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
        int state = 0;//�ң��£�����
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
