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
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;
    std::cout << l1.size() << " eh o tamanho" << std::endl;
    std::cout << l1.percent_occupied() <<" eh o percentual"<< std::endl;
    std::cout << l1.capacity() << " eh a capacidade" << std::endl;
    std::cout << l1.find(5) << " (-1) se nao achou, (indice) se achou"<< std::endl;
    std::cout << l1.front() << " eh o primeiro elemento"<< std::endl;
    std::cout << l1.back() << " eh o ultimo elemento" <<std::endl;
    std::cout << l1.count(100) << " vezes que esse numero aparece no array" <<std::endl;
    std::cout << l1.sum() << " eh a soma dos elementos do array" <<std::endl;
    std::cout << l1.get_at(2) << " eh o valor do indice desejado" << std::endl;
    l1.clear();
    std::cout << l1.size() <<" para testar o clear" << std::endl;
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front : "
        << elapsed.count() << std::endl;
    return 0;

}