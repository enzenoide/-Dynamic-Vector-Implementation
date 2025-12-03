#include "vector-array.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
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

    for (int i = 0; i < n; ++i) {
        int x;
        input >> x;
        v.push_front(x);
    }

    file.close();
    std::cout << "Tamanho: " << v.size() << ", Capacidade: " << v.capacity() << std::endl;
    assert(v.size() == n);
    assert(v.capacity() >= n);
    return 0;
}