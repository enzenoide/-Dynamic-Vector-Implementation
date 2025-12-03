#include "vector-linked.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_linked v;
    assert(v.is_empty());
    for (int i = 0 ; i < 10 ; ++i){
        v.push_back(i*2);
    }
    for (int i=9 ; i >= 0 ; --i){
        assert(v.find(i*2) == i);
        assert(v.find(i*2 + 1) == -1);
    }
    assert(v.pop_front());
    for (int i=1 ; i<10 ; ++i){
        assert(v.find(i*2) == i-1);
        assert(v.find(i*2 + 1) == -1);
    }
    return 0;
}