#include "vector-linked.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_linked v;
    assert(v.is_empty());
    v.push_back(1);
    assert(not v.is_empty());
    v.clear();
    assert(v.is_empty());
    for (int i=0 ; i<1000 ; ++i)
        v.push_back(i+1*2);
    assert((not v.is_empty()) and (v.size() == 1000));
    v.clear();
    assert(v.is_empty());
    return 0;
}