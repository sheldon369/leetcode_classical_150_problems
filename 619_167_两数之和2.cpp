#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//����һ���±�� 1 ��ʼ���������� numbers ���������Ѱ� �ǵݼ�˳������  ��
//������������ҳ��������֮�͵���Ŀ���� target ����������
//������һ����Ч�𰸣�ֻʹ�ó������Ķ���ռ�

//����������ָ�룬ab��b��������λ����target��Ԫ�أ�����ʧ�ܣ���a�����ƶ�һλ��b������Χ��Сһλ

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int begin = 0;
        int end = 1;
        while (end < numbers.size()-1 && numbers[0] + numbers[end] < target) end++;//endָ���λ��������֮�� ���ڵ���target ����ָ������ĩβ
        while (begin < end) {
            int i = end;
            while (i > begin) {
                if (numbers[begin] + numbers[i] == target) {
                    res.push_back(begin + 1);
                    res.push_back(i + 1);
                    return res;
                }
                else if (numbers[begin] + numbers[i] < target) {//����b����begin��С�����Сb������
                    begin++;
                    continue;
                }
                i--;
            }
            begin++;
         
        }
        return res;
    
        

    }
};