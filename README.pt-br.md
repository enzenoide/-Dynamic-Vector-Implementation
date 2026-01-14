[ [English](README.md) ] | [ **Português** ]

# 🧮 Implementação de Vetor Dinâmico em C++

Este projeto consiste na implementação de uma estrutura de dados de **Vetor Dinâmico**, desenvolvida para a disciplina de Algoritmos no **IFRN**. O foco foi o gerenciamento manual de memória e a comparação de performance entre arrays e listas ligadas.

## 🎯 Visão Geral
O objetivo foi construir uma biblioteca para manipular coleções dinâmicas de inteiros usando duas abordagens:

* **Implementação baseada em Array:** Utiliza alocação dinâmica com ponteiros e expansão geométrica.
* **Implementação baseada em Lista Ligada:** Utiliza uma lista duplamente ligada com gerenciamento individual de nós.

## 🏗️ Arquitetura Técnica
Biblioteca do tipo *header-only*, implementada em **C++23**.

### 1. Vetor Array (`vector-array.hpp`)
* **Expansão:** Capacidade inicial de 8, dobrando conforme a necessidade.
* **Memória:** Gerenciamento manual com `new` e `delete[]`.
* **Eficiência:** Acesso aleatório $O(1)$.

### 2. Vetor Lista Ligada (`vector-linked.hpp`)
* **Estrutura:** Nós duplamente ligados.
* **Memória:** Alocação dinâmica por elemento.
* **Eficiência:** Inserção no início/fim em $O(1)$.

---

## 🛠️ Funcionalidades
* **Inserção:** `push_back`, `push_front`, `insert_at`.
* **Remoção:** `pop_back`, `pop_front`, `remove_at`, `remove(valor)`, `clear`.
* **Busca:** `get_at`, `find`, `front`, `back`.
* **Análise:** `size`, `capacity`, `count`, `sum`.

## 🧪 Qualidade
* **Testes:** Suite automatizada com **ctest**.
* **Memória:** Validado com **Valgrind** (zero leaks).
* **Ambiente:** Uso de **Dev Containers** (Docker).

---

## 🚀 Como Compilar
1. **Configurar:** `mkdir build && cd build && cmake ..`
2. **Compilar:** `cmake --build .`
3. **Testar:** `ctest --output-on-failure`
