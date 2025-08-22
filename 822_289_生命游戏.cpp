#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

/*����һ������ m �� n �����ӵ���壬ÿһ�����Ӷ����Կ�����һ��ϸ����ÿ��ϸ��������һ����ʼ״̬�� 1 ��Ϊ ��ϸ�� ��live������ 0 ��Ϊ ��ϸ�� ��dead����
ÿ��ϸ������˸�����λ�ã�ˮƽ����ֱ���Խ��ߣ���ϸ������ѭ�����������涨�ɣ�

�����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������
�����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��
�����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������
�����ϸ����Χ������������ϸ�������λ����ϸ�����

��һ��״̬��ͨ������������ͬʱӦ���ڵ�ǰ״̬�µ�ÿ��ϸ�����γɵģ�
����ϸ���ĳ����������� ͬʱ �����ġ����� m x n ������� board �ĵ�ǰ״̬��������һ��״̬��*/

//���������Ƕ�ÿ������Ԫ���������鱣��ÿ��Ԫ����Χ1����������������������numOf1��
//������һԪ��m[i][j],����ֵ������ӵ�m[i-1 - i+1][j-1 - j+1]��
//���ǲ���ֱ�ӽ�numOf1����һȦ�������������ж�����ı߽����⣬��m[i][j]��ֵ������numOf1[i+1][j+1]��

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int numOf1[27][27]{};
        int m = board.size() ;
        int n = board[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                numOf1[i][j] += board[i][j];
                numOf1[i][j+1] += board[i][j];
                numOf1[i][j+2] += board[i][j];
                numOf1[i+1][j] += board[i][j];
                numOf1[i+1][j+2] += board[i][j];
                numOf1[i+2][j] += board[i][j];
                numOf1[i+2][j+1] += board[i][j];
                numOf1[i+2][j+2] += board[i][j];
            }
        }
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == 1) {//��ϸ��
                    if (numOf1[i + 1][j + 1] < 2 || numOf1[i + 1][j + 1] > 3)
                        board[i][j] = 0;
                }
                else {//��ϸ��
                    if (numOf1[i + 1][j + 1] == 3)
                        board[i][j] = 1;
                }
            }
        }


    }
};