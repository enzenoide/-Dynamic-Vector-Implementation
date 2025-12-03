#include "vector-array.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_array v;
    assert(v.is_empty());
    for (int i = 0 ; i< 10 ; ++i){
        v.push_back(i);
        assert(v.back()== i);
    }
    assert(not v.is_empty());
    v.pop_back();
    assert(v.back() == 8);
    v.pop_front();
    assert(v.back() == 8);
    v.push_front(10);
    assert(v.back() == 8);
    v.insert_at(0, 11);
    assert(v.back() == 8);
    v.insert_at(10, 11);
    assert(v.size() == 11);
    assert(v.back() == 11);
    v.clear();
    v.push_back(13);
    assert(v.front() == v.back());
    v.push_back(23);
    assert(v.front() != v.back());
    assert(v.back()== 23);
    v.insert_at(1, 33);
    assert(v.back() == 23);
    v.push_back(44);
    assert(v.back() == 44);
    return 0;
}