#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

/*给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。
每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，
其中细胞的出生和死亡是 同时 发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。*/

//分析：我们对每个矩阵元素设置数组保存每个元素周围1数量的总数，保留在数组numOf1中
//对于任一元素m[i][j],它的值都将添加到m[i-1 - i+1][j-1 - j+1]中
//我们不妨直接将numOf1扩充一圈，这样就无需判定额外的边界问题，即m[i][j]的值保存在numOf1[i+1][j+1]中

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
                if (board[i][j] == 1) {//活细胞
                    if (numOf1[i + 1][j + 1] < 2 || numOf1[i + 1][j + 1] > 3)
                        board[i][j] = 0;
                }
                else {//死细胞
                    if (numOf1[i + 1][j + 1] == 3)
                        board[i][j] = 1;
                }
            }
        }


    }
};