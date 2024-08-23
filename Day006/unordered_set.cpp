#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;

    // 插入元素
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);

    // 检查元素是否存在
    if (mySet.count(20)) {
        std::cout << "20 is in the set." << std::endl;
    }

    // 删除元素
    mySet.erase(20);

    // 遍历集合
    for (const int& element : mySet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 获取集合大小
    std::cout << "Set size: " << mySet.size() << std::endl;

    // 清空集合
    mySet.clear();

    return 0;
}
