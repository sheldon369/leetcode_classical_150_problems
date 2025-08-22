#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

//编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」 定义为：
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为 1，那么这个数就是快乐数。
//如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

//分析：维护一个map记录出现过的演变数，若重复则说明循环，当然我们并不知道会不会都循环(会，不动点定理)

class Solution {
public:
    bool isHappy(int n) {
        map<int, int>  map;//map记录次数，并且希望不重复不如改为set 搭配 set.count();
        int k = n;
        while (k != 1) {
            int m = 0;
            string s = to_string(k);
            for (int i = 0;i < s.size();i++) {
               m += pow(s[i] - '0', 2);
            }
            k = m;
            map[k]++;
            if (map[k] > 1)
                return  false;
        }
        return true;
        



    }
};