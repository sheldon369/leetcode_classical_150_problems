#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵���(i, 0) ��(i, height[i]) ��
//�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
//�����������Դ�������ˮ����

//����������ͽ���ˮ�Ƚ��񣬵�������ȫ��ͬ������򵥵Ķ�
//ѡ���������� i,h[i] �Լ�j,h[j]����ˮ������Ϊ j-i * min{h[i],h[j]}
//��ķ���������ƥ�䣬�����ֵO(n2)
//�Ż��������˿�ʼ��ÿ���ƶ��̵�һ�ߣ����������ڱ��Ŀ����ԣ���֮������ƶ��ϳ���һ�ߣ�����ֻ���ܱ�С
//���ڴ˲����£����Ǳ���������ʹ��ǰ�������������

class Solution {
public:
    int maxArea(vector<int>& height) {
        int column = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int h = height[i] > height[j] ? height[j] : height[i];
            int current = (j - i) * h;
            if (current > column)
                column = current;
            if (h == height[i])
                i++;
            else
                j--;

        }
        return column;

    }
};