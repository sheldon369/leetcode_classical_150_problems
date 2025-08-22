#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//���������ַ�����ransomNote �� magazine ���ж� ransomNote �ܲ����� magazine ������ַ����ɡ�
//������ԣ����� true �����򷵻� false ��
//magazine �е�ÿ���ַ�ֻ���� ransomNote ��ʹ��һ�Ρ�

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0;i < magazine.size();i++) {
            map[magazine[i]]++;
        }
        for (int j = 0;j < ransomNote.size();j++) {
            if (map[ransomNote[j]] <= 0)
                return false;
            else
                map[ransomNote[j]]--;
        }
        return true;
    }
};