#include <iostream>
#include "linked_set.hpp"

int main(){
    linked_set ll01;
    for (int i=1 ; i<=5 ; ++i)
        ll01.insert(i);
    std::cout << ll01.size() << std::endl;
    std::cout << ll01.to_string() << std::endl;
    for (int i=4 ; i>=1 ; --i)
        ll01.insert(i*2);
    std::cout << ll01.size() << std::endl;
    std::cout << ll01.to_string() << std::endl;
    return 0;
}