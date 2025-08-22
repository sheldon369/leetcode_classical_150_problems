#include <stdio.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

//��һ����·���� n ������վ�����е� i ������վ������ gas[i] ����

//����һ�������������޵ĵ��������ӵ� i ������վ������ i + 1 ������վ��Ҫ�������� cost[i] ����
//������е�һ������վ��������ʼʱ����Ϊ�ա�
//���������������� gas �� cost ���������԰�˳���ƻ�·��ʻһ�ܣ��򷵻س���ʱ����վ�ı�ţ����򷵻� - 1 ��
//������ڽ⣬������ ��֤ ���� Ψһ �ġ�

//������ ��ʼʱ����Ϊ�գ�������Ҫ��֤ gas[i] >= cost[i]
//�����ܴ� x����y�����ǵ��ﲻ��y+1�����x��y����һ��k�����������ܵ���y+1����Ϊ��Ȼ��x�ܵ�k������kʱ������������Ȼ���ڵ���0����ֱ�Ӵ�k����ֻ���������ͼ���
//����difference���������ǵ�Ŀ������difference���ҵ�һ�����У�ʹ�����ǵ�ǰ׺�����Ǵ��ڵ���0.
//����ʹ���߼�ѭ������ά��������ĳ���������ǰ׺��С��0�����´δ���һλ���¼��㼴��


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current = 0;
        int n = gas.size();
        int step = 0;
        vector<int> difference;
        for (int i = 0;i < n;i++) {
            difference.push_back(gas[i] - cost[i]);
        }
        int i = 0;
        while (i < n) {

            while (i < n && difference[i] < 0) i++; // ���������
            if (i >= n) break;

            int total = 0;  // ǰ׺��
            int steps = 0;  // �Ѿ��ߵĲ���
            int start = i;

            // ģ�⻷��·��
            while (steps < n) {
                int idx = (start + steps) % n;
                total += difference[idx];
                if (total < 0) {
                    break; // ��·��������������һλ���������
                }
                steps++;
            }

            if (steps == n) {
                return start;
            }
            else {
                i = i + steps + 1;// ��������ʧ�ܵ������м�վ��
            }
        }

        return -1;
    }
};



int main() {
    Solution sol;
    pair<vector<int>, vector<int>> testCases =
    { {1,2,3,4,5}, {3,4,5,1,2} };  // expected: 3
        
    int result = sol.canCompleteCircuit(testCases.first, testCases.second);
    printf("%d", result);
    return 0;
}