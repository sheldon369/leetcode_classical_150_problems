#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ�ó��ִ����������ε�Ԫ��ֻ�������� ������ɾ����������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

//����������˫ָ�룬�������ö���flag��¼��Ԫ���Ƿ��ظ���

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  b = 0;//b��¼��ȷ������������
        int  pre = 10000;
        int  flag = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != pre) {
                flag = 0;
                pre = nums[i];
                nums[b] = nums[i];
                b++;
            }
            else if (nums[i] == pre && flag == 0) {//�����ظ�Ԫ��
                //�˴��������else�������ϸ�if��ɶԺ������޸�֮��������½��������б�
                flag = 1;
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
    vector<int> nums1 = { 1,1,1,2,2,3 };



    int k = solution.removeDuplicates(nums1);

    // ����ϲ����nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // �����1 2 2 3 5 6
    cout << k << endl;
    return 0;
}