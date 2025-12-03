#include "vector-linked.hpp"
#include <cassert>
#include <iostream>


void test_memory_leak_fail() {
    vector_linked *v = new vector_linked();
    for (int i = 0; i < 2000; ++i) {
        v->push_back(i);
    }
    // Aqui há um vazamento de memória,
    // pois o vetor não é destruído
    // e o ponteiro não é liberado
}

int main(int argc, char *argv[]){
        test_memory_leak_fail(); 
    return 0;
}