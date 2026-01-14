[ **English** ] | [ [Português](README.pt-br.md) ]

# 🧮 Dynamic Vector Implementation (C++)

This project is a custom implementation of a **Dynamic Vector** data structure, developed for the Algorithms and Data Structures course at **IFRN**. The project focuses on manual memory management and compares two different underlying architectures.

## 🎯 Overview
The goal was to build a robust library to handle dynamic collections of integers using two approaches:

* **Array-based Implementation:** Uses dynamic memory allocation with raw pointers and a geometric expansion strategy (doubling capacity).
* **Linked List Implementation:** Uses a Doubly Linked List where each element is managed independently in memory.

## 🏗️ Technical Architecture
The library is **header-only**, implemented in **C++23**.

### 1. Vector Array (`vector-array.hpp`)
* **Growth Strategy:** Initial capacity of 8 elements, doubling every time `size_ == capacity_`.
* **Memory Management:** Manual allocation/deallocation using `new` and `delete[]`.
* **Efficiency:** $O(1)$ random access.

### 2. Vector Linked (`vector-linked.hpp`)
* **Structure:** Doubly Linked List nodes.
* **Memory Management:** Dynamic allocation per element.
* **Efficiency:** $O(1)$ for insertions at head/tail.

---

## 🛠️ Features Implemented
* **Insertion:** `push_back`, `push_front`, `insert_at`.
* **Removal:** `pop_back`, `pop_front`, `remove_at`, `remove(value)`, `clear`.
* **Search & Access:** `get_at`, `find`, `front`, `back`.
* **Analysis:** `size`, `capacity`, `count`, `sum`.
