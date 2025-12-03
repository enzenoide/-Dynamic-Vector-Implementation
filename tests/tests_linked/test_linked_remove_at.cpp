#include "vector-linked.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
    vector_linked v;
    for (int i=0 ; i<100 ; ++i)
        v.push_back(i);
    assert(v.size() == 100);
    assert(v.remove_at(100) == false);
    assert(v.size() == 100);
    assert(v.remove_at(2) == true);
    assert(v.size() == 99);
    assert(v.get_at(0) == 0);
    assert(v.get_at(1) == 1);
    assert(v.get_at(2) == 3);
    assert(v.get_at(4) == 5);
    return 0;
}