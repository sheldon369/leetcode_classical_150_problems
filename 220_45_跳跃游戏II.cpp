#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ������Ϊ n �� 0 ������������ nums����ʼλ��Ϊ nums[0]��
//ÿ��Ԫ�� nums[i] ��ʾ������ i �����ת����󳤶ȡ����仰˵��������� nums[i] �����������ת������ nums[i + j] ��:
//���ص��� nums[n - 1] ����С��Ծ���������ɵĲ����������Ե��� nums[n - 1]��

//����������Ծ��Ϸ�Ļ����ϣ��������жϵ���nums[n - 1]����С��Ծ����
//ֱ���ϸо���Ҫʹ�ö�̬�滮���������Դ���һ��̰�ĵĻ�����ʵ����ʹ�������һ��λ�õ���Ծ������С����֮ǰ��Ҫά����������λ�õ���С��Ծ������

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_step(n);//��ʼ�����������¼����ÿ����������Ͳ���������Ϊn��ȫ����ʼ��Ϊ0
        if (n == 1) {
            return 0;
        }
        else {
            for (int i = 0; i < n;i++) {
                for (int j = i + 1; j <= i + nums[i] && j < n;j++) {
                    int temp = min_step[i] + 1;
                    if (min_step[j] == 0 || min_step[j] > temp) {
                        min_step[j] = temp;
                    }
                }
            }
        }
        return min_step[n - 1];



    }
};

//�Ż�����������
//����step���ӣ����ϸ����ܵ��������[left, right]�������串����n - 1��ʱ�򣬵õ�stepΪ�𰸡�
// 
//��[2, 3, 1, 2, 4, 2, 3]Ϊ����step = 1��ʱ������Ϊ[1, 2](ע���������ָ�����±�)������֮��õ���һ����������[2, 4]������������԰��Ѿ�������Ĳ���ȥ���Դ��O(N)�ĸ��Ӷȣ�Ҳ�����Ƚ�left����Ϊright + 1�ٸ���right