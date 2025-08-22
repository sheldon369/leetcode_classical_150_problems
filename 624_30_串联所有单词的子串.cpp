#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

//����һ���ַ��� s ��һ���ַ������� words�� words �������ַ��� ������ͬ��
//s �е� �����Ӵ� ��ָһ������  words �������ַ���������˳�����������������Ӵ���
//�������д����Ӵ��� s �еĿ�ʼ������������� ����˳�� ���ش𰸡�

//��������ĳ������ʼƥ�䣬�����ʱƥ��ɹ����򴰿�end++��ƥ��ʧ�ܣ�Ҫô�������ظ���words�����ݣ���ʱbegin++��Ҫô��������������ݣ�begin end����Ϊend+1

//ע:�÷�������182����ʱ
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words[0].size();
        unordered_map<string, int> map0;
        for (string t : words) {
            map0[t]++;
        }
        vector<int>  res;
        if (n == 1 && map0.size() == 1 && map0.begin()->second == words.size()) {//��Ե�182�����������Ż���ʵ��û����
            string z = words[0];
            for (int i = 0;i < words.size();i++)
                z += words[0];
            for (int i = 0;i < words.size();i++) {
                if (s.substr(i, words.size()) == z)
                    res.push_back(i);
            }
            return res;
        }
        for (int i = 0; i < n; ++i) {//���Դ����п��ܵ�ƫ�ƿ�ʼɨ��
            int begin = i;
            int end = i;
            unordered_map<string, int> map = map0;
            while (end < s.size()) {
                int count = 0;
                while (end < s.size() && map.count(s.substr(end, n))) {//��ѭ���������ҵ���ȫ�������е�Ԫ��
                    while (end < s.size() && map[s.substr(end, n)] > 0) {
                        map[s.substr(end, n)]--;
                        end += n;
                        count++;
                        if (count == words.size()) {//ƥ��ɹ���ָ�״̬
                            res.push_back(begin);
                        }
                    }//�˳�ѭ����˵���ҵ����������ظ���Ԫ�أ�����begin
                    if (end >= s.size())//����end�������ޣ����Խ��
                        break;
                    map[s.substr(begin, n)]++;
                    begin += n;
                    count--;
                } //�˳�ѭ����˵���ҵ��˷�����Ԫ�أ���ʱ����begin,end
                end += n ;
                begin = end;
                map.clear();
                map = map0;
            }

        }

        return res;

    }
};

//��ʱ�Ż���map->unordered_map,
//substr��ǰ���棬�����ظ�����
//����map��Ϊmap�ĸ���
//map.find ��Ϊ map.count