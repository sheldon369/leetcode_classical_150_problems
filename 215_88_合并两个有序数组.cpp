#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2��
//������������ m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�

//ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�
//Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       /* ���� ����Ŀ�Ѿ���nums1��Ԥ�����㹻�Ŀռ䣬����nums1����ǵݼ�����������������ÿ��Ԫ��ֻ���������ƶ�������������
            ����������Ӵ�С��дnums1�����ܷ��ʵ�nums1ԭ��������Ԫ��*/
        int index1 = m-1;
        int index2 = n-1;
        for (int i = m + n - 1; i >= 0; i--) {
            //�쳣������һ������������
            if (index1 < 0) {
                nums1[i] = nums2[index2];
                index2--;
                continue;//��ֹindex1 < 0 ���������������nums1[index1]�Ӷ����Խ��
            }
            if (index2 < 0)//��nums2������ϣ���nums1ǰ������ı�
                break;
            if (nums2[index2] >= nums1[index1]) {
                nums1[i] = nums2[index2];
                index2--;
            }
            else {
                nums1[i] = nums1[index1];
                index1--;
            }
        }
    }
   
};

//test
int main() {
    Solution solution;

    // ��������1
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };
    int m = 3;  // nums1����Ч��Ԫ�ظ���
    int n = 3;  // nums2��Ԫ�ظ���

    solution.merge(nums1, m, nums2, n);

    // ����ϲ����nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // �����1 2 2 3 5 6

    return 0;
}

