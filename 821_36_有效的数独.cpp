#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//�����ж�һ�� 9 x 9 �������Ƿ���Ч��ֻ��Ҫ �������¹��� ����֤�Ѿ�����������Ƿ���Ч���ɡ�
//���� 1 - 9 ��ÿһ��ֻ�ܳ���һ�Ρ�
//���� 1 - 9 ��ÿһ��ֻ�ܳ���һ�Ρ�
//���� 1 - 9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
//ֻ����֤��Ч�ԣ�������֤�ɽ���

//���������ÿ�У�ÿ�У�ÿ���Ź������һ����Ϊ[10]��bool�������¼��Ԫ���Ƿ���ֹ�(ʵ���õ�1-9)
//��Ȼ������Ԫ��board[i][j],������row[i],column[j],matrix[i/3*3+j/3]
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