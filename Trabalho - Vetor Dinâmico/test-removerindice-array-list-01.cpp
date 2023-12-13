#include <iostream>
#include <chrono>
#include "array_list.hpp"


using namespace std;


int main(){
    int n;
    
    array_list lista;
    for (int i = 0; i < 10000; i++){
        lista.push_back(i);
    }


    auto inc = chrono::high_resolution_clock::now();


    while (cin>> n) {
        lista.remove_at(n);
    }


    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim - inc;
    cout << "TEMPO TOTAL: " << duracao.count() << endl;
}