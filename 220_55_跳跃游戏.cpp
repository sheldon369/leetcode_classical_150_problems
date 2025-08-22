#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


//����һ���Ǹ��������� nums �������λ������� ��һ���±� �������е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
//�ж����Ƿ��ܹ��������һ���±꣬������ԣ����� true �����򣬷��� false ��

//������һ��������ʵ�����������ܴﵽ��λ�ñ�Ȼ�������ģ��������ֻ��Ҫά���������ܷ��ʵ�����±꣬�ж����Ƿ���ڵ���n-1����

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0;
        int i = 0; // iΪ��ǰ����λ��
        while (i <= max_index) {
            int temp = i + nums[i];
            if (temp >= max_index) {
                max_index = temp;
                if (max_index >= nums.size() - 1) { //��������ڴ��ж�����true,��������Ҫ��֤�����ܶ�ĸ���max_index����������ж���׼Ϊtemp >= max_index
                    //�����ж���׼Ϊ temp > max_index�����ж�nums = [0]ʱ�������У���Ȼ��������ִܵ�ĩβ���������ж�Ϊfalse
                    return true;
                }
            }
            i++;
        }

   
        return false;

    }
};