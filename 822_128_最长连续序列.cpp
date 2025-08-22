#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

//����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
//������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣

//������O��n�������ȶ��������������������ʹ��set�ų��ظ�Ԫ�أ��������Ƕ�ÿ��Ԫ�ؽ��к�̵Ĳ��ҡ�
//һ�������������Ǵ����е��м俪ʼ���ң���Ȼ��������ʹ�ø��Ӷ�������n����������ǲ���ǰ��֤����Ԫ��Ϊ�׸�����

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        unordered_set<int> set;
        for (int n : nums) {
            set.insert(n);
        }
        for (int n : set) {//��setԪ�ؽ��б���
            int currentNum = n;
            int  currentLength = 1;
            if (!set.count(currentNum - 1)) {
                while (set.count(currentNum + 1)) {
                    currentNum++;
                    currentLength++;
                }
            }
            ans = max(ans, currentLength);
        }
        return ans;


    }
};

