#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm> //max
using namespace std;

//���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��

//����������ÿ���±꣬�ֱ��ҵ������ߵ�����lmax���ұ���ߵ�����rmax��������ܽ���ˮ min{lmax,rmax} - ����߶�

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmax(n);
        vector<int> rmax(n);
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] > max) {
                max = height[i];
            }
            lmax[i] = max;
        }
        max = 0;
        for (int i = n-1; i >= 0; i--) {
            if (height[i] > max) {
                max = height[i];
            }
            rmax[i] = max;
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(lmax[i], rmax[i]) - height[i];
        }
        return result;

    }
};