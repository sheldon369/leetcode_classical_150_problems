#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//n ������վ��һ�š�����һ���������� ratings ��ʾÿ�����ӵ����֡�����Ҫ��������Ҫ�󣬸���Щ���ӷַ��ǹ���
//ÿ���������ٷ��䵽 1 ���ǹ���
//���������������ָ��ߵĺ��ӻ��ø�����ǹ���
//�����ÿ�����ӷַ��ǹ������㲢������Ҫ׼���� �����ǹ���Ŀ ��

//�� :5 7 8 3 4 2 1
//������������ֽ�Ϊ�������ҹ���
//����򣺴������ҷ��䣬������Ԫ��Ϊa ,b �����rate(b) > rate(a),�� num[b] = num[a] + 1 ,���� num[b] = 1
//ͨ��������죬���Ǳ�֤�д����������������Ԫ�鹹������ͷ��䣬�������Ԫ����Ҫ�������󣬽��ж����ж�
//�ҹ��򣺴���������䣬������Ԫ��Ϊa ,b �����rate(a) > rate(b),�� temp = num[a] + 1 ,num[b] = max{num[b],temp}

//���ģ����Ƿ�������������״ͼ����Ȼ���ɲ�������״ͼ�������ӵķ�����Ϊ
//1231211 ->  1231321,�κ�һ����1���� a ��Ȼ����һ�ν����� a-1�������ǵ���Ʊ�֤��ÿһ����1����������һ�˵�a-1 �������



class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int result = 0;
        vector<int> assign(n);
        assign[0] = 1;
        for (int i = 1;i < n;i++) {
            if (ratings[i] > ratings[i - 1]) {
                assign[i] = assign[i - 1] + 1;
            }
            else {
                assign[i] = 1;
            }
        }
        for (int i = n - 2;i >= 0;i--) {
            if (ratings[i] > ratings[i + 1]) {
                int temp = assign[i + 1] + 1;
                if (assign[i] < temp) {
                    assign[i] = temp;
                }
            }
        }
        for (int nums : assign) {
            result += nums;
        }
        return result;

    }
};