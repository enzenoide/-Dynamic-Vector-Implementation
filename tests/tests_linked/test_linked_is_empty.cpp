#include "vector-linked.hpp"
#include <cassert>
int main(int argc, char *argv[]) {
    vector_linked v;
    assert(v.is_empty());
    v.push_back(1);
    assert(not v.is_empty());
    v.pop_back();
    assert(v.is_empty());
    return 0;
}