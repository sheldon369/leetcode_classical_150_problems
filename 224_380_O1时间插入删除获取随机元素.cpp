#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdlib> //for rand()
using namespace std;

//ʵ��RandomizedSet �ࣺ
//
//RandomizedSet() ��ʼ�� RandomizedSet ����
//bool insert(int val) ��Ԫ�� val ������ʱ���򼯺��в����������� true �����򣬷��� false ��
//bool remove(int val) ��Ԫ�� val ����ʱ���Ӽ������Ƴ���������� true �����򣬷��� false ��
//int getRandom() ����������м����е�һ�����������֤���ô˷���ʱ���������ٴ���һ��Ԫ�أ���ÿ��Ԫ��Ӧ���� ��ͬ�ĸ��� �����ء�
//�����ʵ��������к�����������ÿ�������� ƽ�� ʱ�临�Ӷ�Ϊ O(1) ��

//������
//����Ҫ��ʵ��O(1)���Ӷȣ����������ϣ���find(key)���� ��Ȼ������������ϣ���޷�ʵ��������ؼ����е�һ�������Ƕ���ά��һ��vector��¼����
//��˹�ϣ���ֵ��Ϊ(key,index)����ע����������ά��ĳ���ض�˳��ֻ��Ҫ���ּ�ֵ�ԵĶ�Ӧ��ϵ��
//��vector��erase�������Ӷ�ΪO(n)��������ɾ��ĳһԪ�غ󣬺���Ԫ�ؾ���ǰ���룬������Ҫ������ɾ��Ԫ�ز�����pop_back��������ʵ��O(1)���Ӷ�

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> vec;
public:
    RandomizedSet() {//Ϊ�˷����������ʣ���ʼ������private�����ɸ����ڲ���ȫ�ֱ���

    }

    bool insert(int val) { //��Ԫ�� val ������ʱ���򼯺��в����������� true �����򣬷��� false ��
        if (map.find(val) == map.end()) { //û�ҵ���Ԫ�أ�����Ԫ�ز�����
            vec.push_back(val);
            int n = vec.size();
            map.insert({ val, n - 1 });//map�����ֵ�ԣ�ÿ����ֵ����Ҫ��������������
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val) { //��Ԫ�� val ����ʱ���Ӽ������Ƴ���������� true �����򣬷��� false ��
        if (map.find(val) == map.end()) //û�ҵ���Ԫ�أ�����Ԫ�ز�����
            return false;
        else {
            int index = map[val];
            int n = vec.size();
            n--;
            vec[index] = vec[n];
            vec.pop_back();
            map[vec[n]] = index;
            map.erase(val);
            return true;
        }
    }
            

   
    int getRandom() {
        int randIndex = rand() % vec.size();  // �������
        return vec[randIndex];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
