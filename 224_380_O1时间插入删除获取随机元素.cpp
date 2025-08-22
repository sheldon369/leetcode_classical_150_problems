#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstdlib> //for rand()
using namespace std;

//实现RandomizedSet 类：
//
//RandomizedSet() 初始化 RandomizedSet 对象
//bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
//bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
//int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
//你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

//分析：
//查找要想实现O(1)复杂度，必须借助哈希表的find(key)函数 ，然而单单依靠哈希表无法实现随机返回集合中的一项，因此我们额外维护一个vector记录索引
//因此哈希表键值对为(key,index)，关注到我们无需维护某个特定顺序，只需要保持键值对的对应关系，
//且vector的erase函数复杂度为O(n)，本质是删除某一元素后，后续元素均向前补齐，我们需要交换待删除元素并调用pop_back（）函数实现O(1)复杂度

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> vec;
public:
    RandomizedSet() {//为了方便调用与访问，初始化放在private中生成该类内部的全局变量

    }

    bool insert(int val) { //当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
        if (map.find(val) == map.end()) { //没找到该元素，即该元素不存在
            vec.push_back(val);
            int n = vec.size();
            map.insert({ val, n - 1 });//map插入键值对，每个键值对需要用中括号括起来
            return true;
        }
        else {
            return false;
        }
    }

    bool remove(int val) { //当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
        if (map.find(val) == map.end()) //没找到该元素，即该元素不存在
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
        int randIndex = rand() % vec.size();  // 随机索引
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
