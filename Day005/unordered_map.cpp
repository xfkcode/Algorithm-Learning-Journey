#include <iostream>
#include <unordered_map>
#include <string>
#include <stdlib.h>

int main() {
    std::unordered_map<std::string, int> myMap;

    myMap["apple"] = 1;
    myMap["banana"] = 2;
    myMap["orange"] = 3;

    std::string key = "apple";
    if(myMap.find(key)!=myMap.end()) {
        std::cout << key << ": " << myMap[key] << std::endl;
    } else {
        std::cout << key << " not found" << std::endl;
    }

    myMap["apple"] = 10;
    myMap.erase("banana");

    for(const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    system("pause");
    return 0;
}