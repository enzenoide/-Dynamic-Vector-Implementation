#include "vector-array.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
int main(int argc, char *argv[]) {
    vector_array v;
    for (int i=0 ; i<100 ; ++i)
        v.push_back(i);
    assert(v.size() == 100);
    assert(v.remove(50));
    assert(v.size() == 99);
    assert(not v.remove(50));
    assert(v.size() == 99);
    assert(v.size() == 99);
    assert(v.insert_at(20,101));
    assert(v.size() == 100);
    assert(v.insert_at(41,101));
    assert(v.size() == 101);
    assert(v.insert_at(63,101));
    assert(v.size() == 102);
    assert(v.remove(101));
    assert(v.size() == 101);
    assert(v.remove(101));
    assert(v.size() == 100);
    assert(v.remove(101));
    assert(v.size() == 99);
    assert(not v.remove(101));
    assert(v.size() == 99);
    assert(v.remove(20)); 
    assert(v.remove(19));
    assert(v.remove(21));
    assert(v.size() == 96);
    return 0;
}