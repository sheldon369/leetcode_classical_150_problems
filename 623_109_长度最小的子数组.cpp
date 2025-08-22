#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;


//����һ������ n ���������������һ�������� target ��
//�ҳ����������������ܺʹ��ڵ��� target �ĳ�����С�� ������[numsl, numsl + 1, ..., numsr - 1, numsr] ��
//�������䳤�ȡ���������ڷ��������������飬���� 0 ��

//����������ȫ��������ֻҪ��û����target�Ϳ��Լӣ������˾ʹ���һ�������¿�ʼ,���ǿ���ά�ֻ������ڣ�������������
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0;//start�������£����sum�������ʼλ��
        int end = 0;//end��������
        int sum = 0;//�������ڵ���ֵ
        int res = n + 1;//ȫ�����Ž�
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {//�������ɾ����Ϊǰ׺���ʿ���ɾ�����
                res = min(end - start + 1, res);
                sum -= nums[start];
                start++;
            }
            end++;
         }
        res = res > n ? 0 : res;
        return res;

    }
};

