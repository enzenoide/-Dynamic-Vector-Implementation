#include "vector-linked.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_linked v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);
    for (int i = 0; i < 10; ++i)
        assert(v.get_at(i) == i);
    assert(v.get_at(10) == -1);
    assert(v.get_at(-1) == -1);
    return 0;
}