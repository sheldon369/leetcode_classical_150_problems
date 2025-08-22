#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�ء�Ԫ�ص�˳����ܷ����ı䡣Ȼ�󷵻� nums ���� val ��ͬ��Ԫ�ص�������

//���� nums �в����� val ��Ԫ������Ϊ k��Ҫͨ�����⣬����Ҫִ�����²�����
//��1������ nums ���飬ʹ nums ��ǰ k ��Ԫ�ذ��������� val ��Ԫ�ء�nums ������Ԫ�غ� nums �Ĵ�С������Ҫ��
//��2������ k

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //������˫ָ�뷨��ָ��i������������ָ�룩��b��¼��val��ֵ����������дnums[b]�ϵ�ÿ��ֵ
        int  b = 0;
        for (int i = 0;i < nums.size() ;i++) {
            if ( nums[i] != val ) {
                nums[b] = nums[i];
                b++;
            }
        }
        return b;

    }
};


//������˫ָ���Ż���
//ע�⵽��һ�ж��ظ�Ԫ�ؽ������ظ���ֵ���ȷ�˵1��2��3ɾ��2�����Ƕ�1�������ظ���ֵ���ұ����˳�ȥval��ֵ��ԭ�����е�λ�ã��������ȫ����Ҫ�ġ�
//���ǿ��Դ��������߹�ͬ�������飬��ָ���ҵ�����val���Ǹ�ֵ����ָ�뱻��ÿ���ƶ�һ�Σ���ָ�븳ֵ��ָ���ֵ�������ƹ�����ֵ��Ȼ����val�����ظ��Ĳ�����ֱ��˫ָ������
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[--right];
            }
            else {
                left++;
            }
        }
        return left;
    }
};
