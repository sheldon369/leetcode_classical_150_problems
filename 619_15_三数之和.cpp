#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

//����һ���������� nums ���ж��Ƿ������Ԫ��[nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��
//ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ��
//���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣�����˳�����Ԫ���˳�򲢲���Ҫ��

//������һ��ȷ��ĳ������ʣ�µ��������ҵ�����֮��Ϊһ���ض�����������ʹ��hash�����

//Ϊ�˱����ظ������ǽ���������,��һ��ָ��Ӹ���������0����һ����ֻ�����Ǹ������ڶ�����������Լ��� +���Լ�������������ȫ
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        map<int, int> tab;
        for (int n : nums) {
            tab[n]++;
        }
        map<int, int>::iterator it;
        vector<int> vec;
        for (it = tab.begin();it != tab.end();it++) {
            vec.push_back(it->first);
        }
        int n = vec.size();
        for (int i = 0;  i < n &&vec[i] <= 0;i++) {
            /*if (tab[vec[i]] > 1) {
                if (tab.find(-2 * vec[i]) != tab.end()) {
                    vector<int> temp;
                    temp.push_back(vec[i]);
                    temp.push_back(vec[i]);
                    temp.push_back(-2 * vec[i]);
                    res.push_back(temp);   
                } 
            } */
            tab[vec[i]]--;
            for (int j = i; j < n && vec[j] <= -vec[i] ;j++) {
                if (tab[vec[j]] == 0)//Ӧ�� j = i ʱ��ֻ��һ��vec[i];
                    continue;
                tab[vec[j]]--;
                int remainer = - vec[i] - vec[j];
                if (tab.find(remainer) != tab.end()) {
                    if (tab[remainer] > 0 && remainer >= vec[j]) {
                        vector<int> temp;
                        temp.push_back(vec[i]);
                        temp.push_back(vec[j]);
                        temp.push_back(remainer);
                        res.push_back(temp);
                    }  
                }
                tab[vec[j]]++;
            } 
            tab[vec[i]]++;
        }
       /* if (tab[0] >= 3) {
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(0);
            temp.push_back(0);
            res.push_back(temp);
        }*/
        return res;
       

    }
};
//�����ظ����ı�����ʲô�����Ǳ�������ѭ���Ĵ��ܲ��䣬ֻ��Ҫ��֤��
//�ڶ���ѭ��ö�ٵ���Ԫ�ز�С�ڵ�ǰ��һ��ѭ��ö�ٵ���Ԫ�أ�
//������ѭ��ö�ٵ���Ԫ�ز�С�ڵ�ǰ�ڶ���ѭ��ö�ٵ���Ԫ�ء�











// ��ӡ��Ԫ����
void printResults(const vector<vector<int>>& res) {
    for (const auto& triplet : res) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0},
        {-2, 0, 1, 1, 2},
        {},
        {0, 1, 1},
        {-2, -1, -1, 0, 1, 2}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ":" << endl;
        vector<vector<int>> result = sol.threeSum(testCases[i]);
        printResults(result);
        cout << "--------" << endl;
    }

    return 0;
}