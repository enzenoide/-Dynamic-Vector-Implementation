#include "vector-array.hpp"
#include <cassert>
#include <fstream>
#include <iostream>

// Este teste considera que o push_back() foi implementado corretamente
// e já passou por testes anteriores.
int main(int argc, char *argv[]) {
    std::istream *stream = &std::cin;
    std::ifstream file;
    if (argc > 2) {
        std::cerr << "Uso: " << argv[0] << " [arquivo]" << std::endl;
        return 1;
    } else if (argc == 2) {
        file.open(argv[1]);
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
            return 1;
        }
        stream = &file;
    }
    std::istream &input = *stream;
    vector_array v;
    int n;
    input >> n;
    // Teste de inserção no final do vetor
    for (int i = 0; i < n; ++i) {
        int x;
        input >> x;
        v.push_back(x);
    }

    file.close();
    // Exibe o tamanho e a capacidade do vetor
    std::cout << "Tamanho: " << v.size() << ", Capacidade: " << v.capacity() << std::endl;
    assert(v.size() == n);
    assert(v.capacity() >= n);
    // Teste de remoção do último elemento
    for (int i = 0; i < n; ++i) {
        assert(v.front() == true); // Verifica se a remoção foi bem-sucedida
    }
    assert(v.pop_front() == false); 
    assert(v.size() == 0); // Verifica se o vetor está vazio após todas as remoções
    std::cout << "Tamanho: " << v.size() << ", Capacidade: " << v.capacity() << std::endl;
    return 0;
}