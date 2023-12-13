#include <iostream>
#include <chrono>
#include "array_list.hpp"


using namespace std;


int main(){
    int n;
    array_list lista;
    auto inc = chrono::high_resolution_clock::now();


    while (cin >> n){
        lista.insert_at (2, n);
    }


    auto fim = chrono::high_resolution_clock::now();
    auto duracao = fim - inc;


    cout << "TEMPO TOTAL: " << duracao.count() << endl;
}