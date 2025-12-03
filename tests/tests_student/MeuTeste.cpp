#include <iostream>
#include <cassert>
#include "vector-array.hpp"

int main(){
    vector_array  v;
    assert(v.size() == 0);
    v.push_front(10);
    assert(v.size() == 1);
    v.push_front(20);
    assert(v.size() == 2);
    v.clear();
    return 0;
}