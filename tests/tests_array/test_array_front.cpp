#include "vector-array.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
    vector_array v;
    assert(v.is_empty());
    for (int i= 0 ; i< 10 ; ++i){
        v.push_back(i);
    }
    assert(not v.is_empty());
    assert(v.front() == 0);
    v.pop_front();
    assert(v.front() == 1);
    v.push_front(10);
    assert(v.front() == 10);
    v.insert_at(0, 11);
    assert(v.front() == 11);
    assert(v.size() == 11);
    v.clear();
    v.push_back(13);
    assert(v.front()== 13);
    v.push_back(23);
    assert(v.front()== 13);
    v.insert_at(1, 33);
    assert(v.front()== 13);
    v.push_front(44);
    assert(v.front() == 44);
    return 0;
}