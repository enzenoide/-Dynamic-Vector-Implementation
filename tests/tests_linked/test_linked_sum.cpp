#include "vector-linked.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_linked v;
    assert(v.is_empty());
    for (int i = 1; i <= 10; ++i)
        v.push_back(i);
    int sum_base = ((1 + 10) * 10) / 2;
    assert(v.sum() == sum_base);
    v.insert_at(2, 10);
    assert(v.sum() == sum_base + 10);
    v.insert_at(5, 11);
    assert(v.sum() == sum_base + 11 + 10);
    v.pop_front();
    assert(v.sum() == sum_base + 11 + 10 - 1);
    v.pop_back();
    assert(v.sum() == sum_base + 11 + 10 - 1 - 10);
    v.clear();
    assert(v.sum() == 0 and v.is_empty());
    assert(v.sum() == 0 and v.is_empty());
    v.push_front(123);
    v.push_front(321);
    v.push_back(111);
    assert(v.sum() == 555);
    return 0;
}