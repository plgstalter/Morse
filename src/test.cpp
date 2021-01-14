#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
    std::vector<int> test;
    test.push_back(3);
    test.resize(0);
    test.push_back(2);
    test.push_back(4);
    std::vector<int>::iterator res = std::find(test.begin(), test.end(), 3);
    int index = std::distance(test.begin(), res);
    std::cout << index << std::endl;
    return 0;
}
