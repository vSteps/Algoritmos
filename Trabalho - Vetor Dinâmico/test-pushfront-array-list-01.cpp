#include <iostream>
#include <chrono>
#include "array_list.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    array_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_front(x);
        l1.insert_at(2,x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    if (not (l1.size() == n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
    std::cout << l1.size() << std::endl;
    std::cout << l1.capacity() << std::endl;
    std::cout << l1.percent_occupied() << std::endl;

    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front :"
        << elapsed.count() << std::endl;
    return 0;


}