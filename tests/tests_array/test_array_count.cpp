#include "vector-array.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_array v;
    assert(v.is_empty());
    for (int i = 0; i < 100; ++i)
        v.push_back(i * 3);
    for (int i = 0; i < 100; ++i)
        v.push_back(i * 2);
    for (int i = 50; i < 100; ++i)
        v.push_back(i);
    assert(v.size() == 250);
    assert(v.count(222) == 1);
    assert(v.count(153) == 1);
    assert(v.count(154) == 1);
    assert(v.count(156) == 2);
    assert(v.count(159) == 1);
    assert(v.count(161) == 0);
    assert(v.count(96) == 3);
    assert(v.count(250) == 0);
    assert(v.count(98) == 2);
    assert(v.count(95) == 1);
    assert(v.count(155) == 0);
    return 0;
}