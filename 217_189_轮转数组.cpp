#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

//解1：借助额外数组，空间复杂度O(n)
//遍历原数组，将原数组下标为 i 的元素放至新数组下标为(i + k)modn 的位置，最后将新数组拷贝至原数组即可。


//解2：环状替换*
//方法一中使用额外数组的原因在于如果我们直接将每个数字放至它最后的位置，这样被放置位置的元素会被覆盖从而丢失。因此，我们设置变量temp暂存被覆盖的元素，不断将被覆盖元素放置其正确位置。
//这其实相当于在一个有n个元素的环上以步长k进行运动，假设运动了a次，运动了b圈，我们有 ak = bn, 即以该模式运动必然能回到起始点，且第一次回到起点时我们必然遍历了a个不同的元素，第一次回到起点时有  ak = bn = delta, a, b均为正整数，则 delta = lcm(k,n),我们遍历了 a = delta / k = lcm(k,n) / k个元素。
//当回到原点后，我们随即开始从后一个元素开始新的遍历，共需要重复 n / (lcm(k, n) / k) = nk / lcm(k,n) = gcd(k,n) 次。


//解3：双重翻转
//该方法基于如下的事实：当我们将数组的元素向右移动 k 次后，尾部 k mod n 个元素会移动至数组头部，其余元素向后移动 k mod n 个位置。
//该方法为数组的翻转：我们可以先将所有元素翻转，这样尾部的 k mod n 个元素就被移至数组头部，然后我们再翻转[0, (k mod n) − 1] 区间的元素和[k mod n, n−1] 区间的元素即能得到最后的答案。


class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;//k有可能超过n，必须取mod，否则访问数组会越界
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k , n - 1);

    }

    void reverse(vector<int>& nums, int begin, int end) {//翻转数组
        int temp = 0;
        int n = end - begin + 1;
        for (int i = 0;i < n / 2;i++) {
            temp = nums[begin + i];
            nums[begin + i] = nums[end - i];
            nums[end - i] = temp;
        }
     


    }
};