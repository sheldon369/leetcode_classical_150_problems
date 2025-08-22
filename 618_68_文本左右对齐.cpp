#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <list>
using namespace std;

//����һ���������� words ��һ������ maxWidth �������Ű浥�ʣ�ʹ���Ϊÿ��ǡ���� maxWidth ���ַ������������˶�����ı���
//��Ӧ��ʹ�� ��̰���㷨�� �����ø����ĵ��ʣ�Ҳ����˵�������ܶ����ÿ���з��õ��ʡ���Ҫʱ���ÿո� ' ' ��䣬ʹ��ÿ��ǡ���� maxWidth ���ַ���
//Ҫ�󾡿��ܾ��ȷ��䵥�ʼ�Ŀո����������ĳһ�е��ʼ�Ŀո��ܾ��ȷ��䣬�������õĿո���Ҫ�����Ҳ�Ŀո�����
//�ı������һ��ӦΪ����룬�ҵ���֮�䲻�������Ŀո�

//������������Ҫȷ��һ�����ж��ٸ����ʣ�������x���������x-1���ո�ӦС�ڵ���maxWidth
//�����һ���⣬���Ҫ���ȷ���ո�����Ҫ��ʣ��ռ���Կո�������������������ߵĿո����
//���һ�ж��⴦��

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> length;
        vector<string> res;
        for (string s : words) {
            length.push_back(s.size());
        }
        int i = 0;
        while (i < words.size()) {
            int sum = -1;//���⴦������һ����֮ǰ�Ŀ�λ
            int begin = i;
            string temp = "";
            while (i < words.size()) {
                sum = sum + 1 + length[i];
                if (sum > maxWidth)
                    break;
                i++;
            }//i����ָ����һ�е���λ
            //if (i < words.size()) {//��ʱiָ��պó���������λ��������ǻ���һλ
            //    i--;
            //}
            if (i == words.size() ||i - begin ==1) {//���Ѿ���������β,���һ��
                for (int k = begin; k < i; k++) {
                    temp += words[k];
                    if (k != i - 1) temp += " ";
                }
                temp += string(maxWidth - temp.size(), ' ');
                res.push_back(temp);
                continue;
            }
           
          
            int end = i;
            int total_length = 0;
            for (int j = begin;j < end;j++) {
                total_length += length[j];
            }
            //if (end - begin == 1) {//�ر�������ֻ������һ���ַ�
            //    res.push_back(words[begin]);
            //    continue;
            //}
            int product = (maxWidth - total_length)/(end - begin - 1);//��һ�п���end - begin -1 =0
            int remainder = (maxWidth - total_length) - product * (end - begin - 1);
            
            int repeat = 1;
            for (int j = begin;j < end;j++) {
                temp = temp + words[j];
                for (int m = 0;m < product;m++)
                    temp = temp + " ";
                if (repeat <= remainder) {
                    temp = temp + " ";
                    repeat++;
                }
          
            }
            temp = temp.substr(0, maxWidth);
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
    int maxWidth = 16;

    vector<string> result = sol.fullJustify(words, maxWidth);

    cout << "Justified Text:\n";
    for (const string& line : result) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}