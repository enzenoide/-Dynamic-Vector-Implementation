#include "vector-linked.hpp"
#include <cassert>
#include <iostream>

void test_memory_leak_ok1() {
    vector_linked v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    assert(v.size() == 1000);
    v.insert_at(10, 200);
    v.pop_back();
    assert(v.size() == 1000);
    v.remove_at(200);
    v.remove(500);
    assert(v.size() == 998);

    while (!v.is_empty()) { 
        v.pop_back();
    }
    for (int i = 0; i < 200; ++i) {
        v.push_back(i);
    }
    assert(v.size() == 200);
    v.push_front(1000);
    v.clear();
    assert(v.size() == 0);
    v.push_back(1001);
    assert(v.size() == 1);
    v.push_front(1002);
    assert(v.size() == 2);
    v.insert_at(1, 1003);
    assert(v.size() == 3);
    assert(v.front() == 1002);
    assert(v.back() == 1001);
    v.pop_front();
    assert(v.size() == 2);
    assert(v.front() == 1003);
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 1003);
    assert(v.front() == 1003);
    v.pop_back();
    assert(v.size() == 0);
    for (int i = 0; i < 500; ++i) {
        v.push_back(i);
        v.push_front(10000 + i);
        if (i % 5 == 0) {
            v.pop_back();
            if (i % 8 == 0) {
                v.pop_front();
            }
            if (i % 71 == 0) {
                v.remove_at(i / 2);
            }
        }
    }
    while (!v.is_empty()) {
        v.pop_front();
    }
}

void test_memory_leak_ok2() {
    vector_linked *v = new vector_linked;
    for (int i = 0; i < 1000; ++i) {
        v->push_back(i);
    }
    assert(v->size() == 1000);
    while (!v->is_empty()) {
        v->pop_back();
    }
    for (int i = 0; i < 10000; ++i) {
        v->push_back(i);
    }
    v->clear();
    assert(v->size() == 0);
    delete v;
}
int main(int argc, char *argv[]) {
    test_memory_leak_ok1();
    test_memory_leak_ok2();
    return 0;
}