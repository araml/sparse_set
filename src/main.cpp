#include <iostream>
#include <sparse_set.h>

auto main() -> int {
    sparse_set<int> s;
    s.insert(20, 5);
    s.insert(6, 10);
    s.insert(0, 1);

    std::cout << s[20] << " " << s[0] << " " << s[6] << std::endl;

    for (auto &e : s) {
        std::cout << e << std::endl;
    }

    std::cout << "mhm" << std::endl;
}
