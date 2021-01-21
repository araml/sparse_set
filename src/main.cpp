#include <iostream>
#include <sparse_set.h>

auto main() -> int {
    sparse_set<int> s;
    s.insert(20, 5);
    s.insert(6, 10);
    s.insert(0, 1);

    for (auto &e : s) {
        std::cout << e << std::endl;
    }

    s.erase(6);

    std::cout << std::endl;

    for (auto &e : s) {
        std::cout << e << std::endl;
    }

    s.insert(15, 333);
    std::cout << std::endl;
    for (auto &e : s) {
        std::cout << e << std::endl;
    }
    std::cout << "mhm" << std::endl;
}
