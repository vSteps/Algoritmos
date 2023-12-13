#include <iostream>
#include <chrono>
#include "array_list.hpp"


using namespace std;


int main(){
    array_list lista;
    for (int i = 0; i < 10000; i++){
        lista.push_front(i);
    }


    auto inc = chrono::high_resolution_clock::now();


    for (int i = 0; i < 10000; i++){
        lista.pop_back();
    }


    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim - inc;


    cout << "TEMPO TOTAL: " << duracao.count() << endl;
}