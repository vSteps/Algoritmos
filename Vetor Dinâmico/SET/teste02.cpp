#include <iostream>
#include "set_array.hpp"
int main() {
    Set mySet;

    mySet.insert(5);
    mySet.insert(10);
    mySet.insert(5); // Isso não vai inserir novamente

    std::cout << "Size: " << mySet.getSize() << std::endl; // Deve imprimir 2
    std::cout << "Is 10 in the set? " << mySet.find(10) << std::endl; // Deve imprimir 1 (verdadeiro)
    
    mySet.erase(5);
    std::cout << "Size after erasing 5: " << mySet.getSize() << std::endl; // Deve imprimir 1

    mySet.clear();
    std::cout << "Is the set empty? " << mySet.empty() << std::endl; // Deve imprimir 1 (verdadeiro)

    return 0;
}
