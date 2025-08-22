#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
//另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       /* 分析 ：题目已经在nums1中预留了足够的空间，由于nums1本身非递减，即有序，则重排序每个元素只可能向右移动，不可能向左；
            故我们如果从大到小重写nums1，则能访问到nums1原本的所有元素*/
        int index1 = m-1;
        int index2 = n-1;
        for (int i = m + n - 1; i >= 0; i--) {
            //异常处理，有一个数组遍历完成
            if (index1 < 0) {
                nums1[i] = nums2[index2];
                index2--;
                continue;//防止index1 < 0 后续代码继续访问nums1[index1]从而造成越界
            }
            if (index2 < 0)//若nums2插入完毕，则nums1前面无需改变
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

    // 测试用例1
    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 2, 5, 6 };
    int m = 3;  // nums1中有效的元素个数
    int n = 3;  // nums2的元素个数

    solution.merge(nums1, m, nums2, n);

    // 输出合并后的nums1
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;  // 输出：1 2 2 3 5 6

    return 0;
}

