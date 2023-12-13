#include <iostream>
#include <vector>

// Função para verificar se há três números em uma lista que formam um triângulo retângulo
bool verificaTrianguloRetangulo(const std::vector<int>& lista) {
    // Verifica se a lista tem pelo menos três elementos
    if (lista.size() < 3) {
        std::cout << "A lista não possui elementos suficientes para formar um triângulo retângulo." << std::endl;
        return false;
    }

    // Loop para todas as combinações possíveis de três números na lista
    for (size_t i = 0; i < lista.size() - 2; ++i) {
        for (size_t j = i + 1; j < lista.size() - 1; ++j) {
            for (size_t k = j + 1; k < lista.size(); ++k) {
                int lado1 = lista[i];
                int lado2 = lista[j];
                int hipotenusa = lista[k];

                // Aplica o Teorema de Pitágoras
                if (lado1 * lado1 + lado2 * lado2 == hipotenusa * hipotenusa) {
                    std::cout << "Triângulo retângulo encontrado: " << lado1 << ", " << lado2 << ", " << hipotenusa << std::endl;
                    return true;
                }
            }
        }
    }

    std::cout << "Nenhum triângulo retângulo encontrado na lista." << std::endl;
    return false;
}

int main() {
    // Exemplo de uso da função
    std::vector<int> minhaLista = {3, 4, 5, 6, 8};

    verificaTrianguloRetangulo(minhaLista);

    return 0;
}
