#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ�� ���ϸ�������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����
//
//���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����
//��1���������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
//��2������ k ��

//������ʵ��˼·�ο�215_27�Ƴ��ض�Ԫ�صĽⷨһ�����ض�Ԫ�ر�Ϊ�ظ�Ԫ��

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  b = 0;
        int  flag = 10000;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != flag) {
                flag = nums[i];
                nums[b] = nums[i];
                b++;
            }
        }
        return b;

    }
};

int main() {
    Solution solution;

    // ��������1
    vector<int> nums1 = { 0,0,1,1,1,2,2,3,3,4 };
 


    int k = solution.removeDuplicates(nums1);

    // ����ϲ����nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // �����1 2 2 3 5 6
    cout << k << endl;
    return 0;
}