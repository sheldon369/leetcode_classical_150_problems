#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
//根据维基百科上 h 指数的定义：h 代表“高引用次数” ，
//一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个。

//分析：计数排序
//显然有 h <= n,可以维护一个 n+1 维向量(1 - n+1)，每个元素记录大于该索引的值，最后从后往前读取第一个值大于等于索引的值

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> aux(n + 1);
        for (int num : citations) {
            for (int i = 1;i <= num && i <= n;i++) {
                aux[i]++;
            }
        }
        for (int i = n;i >= 0;i--) {
            if (aux[i] >= i) {
                return i;
            }
        }
        return 0;

    }
};

//解2：逆序排序
//比如排序后[6, 5, 3, 1, 0]，如果citations[i] > i，那么前面的数必定大于i，所以找到i的最大值就是答案，因为i从0开始，所以返回结果需要i+1

//解3：二分搜索
//我们需要找到一个值h，它是满足「有h篇论文的引用次数至少为h」的最大值。小于等于h的所有值x都满足这个性质，而大于h的值都不满足这个性质。
 