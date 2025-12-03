#include "vector-array.hpp"
#include <cassert>
#include <iostream>

void test_memory_leak_ok1() {
    vector_array v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
        // Pode haver vazamento de memória aqui se não usarmos 
        // o vetor corretamente
        // ou se a classe vector_array não gerenciar a memória corretamente
    }
    assert(v.size() == 1000);
    // Não há vazamento de memória aqui, 
    // pois o vetor é destruído ao final do escopo
    while (!v.is_empty()) {
        v.pop_back(); // Limpa o vetor
    }
    for (int i = 0; i < 200; ++i) {
        v.push_back(i);
        // Pode haver vazamento de memória aqui 
        // se a classe vector_array não gerenciar a memória corretamente
    }
    v.clear(); // Limpa o vetor novamente
    assert(v.size() == 0);
    
}

void test_memory_leak_ok2() {
    vector_array *v = new vector_array;
    for (int i = 0; i < 1000; ++i) {
        v->push_back(i);
        // Pode haver vazamento de memória aqui a 
        // classe vector_array não gerenciar a memória corretamente
    }
    assert(v->size() == 1000);
    // Não há vazamento de memória aqui, 
    // pois o vetor é destruído ao final do escopo
    while (!v->is_empty()) {
        v->pop_back(); // Limpa o vetor
    }
    for (int i = 0; i < 10000; ++i) {
        v->push_back(i);
        // Pode haver vazamento de memória aqui se não usarmos 
        // o vetor corretamente
        // ou se a classe vector_array não gerenciar a memória corretamente
    }
    v->clear(); // Limpa o vetor novamente
    assert(v->size() == 0);
    delete v; // Libera o vetor para evitar vazamento de memória
}

int main(int argc, char *argv[]){
    test_memory_leak_ok1();
    test_memory_leak_ok2();
    return 0;
}