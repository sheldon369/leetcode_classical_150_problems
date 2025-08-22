#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��
//��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�

//�� ��Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣

//������������Դ洢��int�����У��Ҳ�����ʹ�ó�����������ǲ������������Ԫ�صĳ˻��ٳ���ĳԪ�������ֵ(���ʣ��������Ԫ��0����÷���ʧЧ��)
//���ǿ�����ǰ׺�� �Լ� ��׺�ͷֱ�洢 i֮ǰ�Լ�֮���Ԫ�صĺͣ��ռ临�Ӷ� O��2n��

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> pre(n);
        vector<int> suc(n);
        int product = 1;
        pre[0] = 1;
        suc[n-1] = 1;
        for (int i = 1;i < n;i++) {
            product *= nums[i - 1];
            pre[i] = product;
        }
        product = 1;
        for (int i = n-2;i >= 0 ;i--) {
            product *= nums[i + 1];
            suc[i] = product;
        }
        for (int i = 0;i < n;i++) {
            answer[i] = pre[i] * suc[i];
        }
        return answer;
    }
};

//��2���Ż��ռ临�Ӷ�Ϊ0��1��
//��Ȼ���Ǳ���ʹ��answer���洢���յĴ𰸣���answer�������һ���ű�ʹ��
//�����ǿ��Բ���anwser�洢ԭ���е�pre���飬����������productʵ�ʼ�¼���ۻ���suc��ֱ�Ӹ���answer[i] = product * answer[i]���ɣ���÷�û�н��ö���Ŀռ�