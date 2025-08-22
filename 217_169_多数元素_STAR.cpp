#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n / 2 ⌋ 的元素
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。

//解1：哈希表
//采用键值对存储数据，键对应元素的值，值对应该元素出现的次数，同时在扫描过程中维护值最大的键值对，最终输出对应的键

//解2：排序
//若数组有序且下标从0开始，且存在一元素common为众数，数量超过了n/2，则下标为n/2的元素必为common

//解3：随机化
//众数占据了数组中的大部分，所以随机选取一个元素，大概率该元素是众数，我们选取元素后对其进行判定。

//解4：分治
//将数组不停划分直到长度为1，唯一的元素显然是众数，随后两两会合。若两段众数一致均为i，则众数为i；若众数不一致，则需要选出新的众数

//解5: Boyer - Moore 投票算法
//如果我们把众数记为 + 1，把其他数记为 −1，将它们全部加起来，显然和大于 0，从结果本身我们可以看出众数比其他数多。
class Solution5 {
public:
    int majorityElement(vector<int>& nums) {
        int common = 0;//记录众数
        int times = 0;//记录众数此时出现的次数
        for (int num : nums) {
            if (times == 0) {
                common = num;
                times++;
            }
            else if (num == common) {//此处需要加入else，保证if执行完毕后进入下一个loop，或者不加else，if中删去times++
                times++;
            }
            else {
                times--;
            }
        }
        return common;

    }
};
