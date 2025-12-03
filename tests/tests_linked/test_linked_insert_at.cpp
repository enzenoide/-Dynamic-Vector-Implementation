#include "vector-linked.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_linked v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    for (int i = 11; i < 21; ++i)
        v.push_back(i);
    assert(v.size() == 20);
    assert(v.get_at(9) == 9);
    assert(v.get_at(10) == 11);
    assert(v.get_at(19) == 20);
    assert(v.insert_at(10, 10) == true);
    for (int i = 0; i < v.size(); ++i)
        assert(v.get_at(i) == i);
    assert(v.insert_at(30, 1) == false);
    assert(v.size() == 21);
    assert(v.capacity() >= 21);
    return 0;
}