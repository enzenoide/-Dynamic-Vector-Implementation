#ifndef __VECTOR_ARRAY_IFRN__
#define __VECTOR_ARRAY_IFRN__
class vector_array {
private:
    int *data;
    unsigned int size_, capacity_;
    void increase_capacity() {}

public:
    vector_array() {         // Construtor
    }
    ~vector_array() { // Destrutor
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return 0;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return 0;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da
        return 0;               // memória usada.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        return false;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        return false;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        return false;
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index,
        return -1;                   // −1 se índice inválido
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
    }
    bool pop_back() {            // Remove um elemento do ``final'' do vetor
        return false;
    }
    bool pop_front() {           // Remove um elemento do ``início'' do vetor
        return false;
    }
    int back() {                 // Retorna o elemento do ``final'' do vetor
        return -1;
    }
    int front() {                // Retorna o elemento do ``início'' do vetor
        return -1;
    }
    bool remove(int value) {     // Remove value do vetor caso esteja presente
        return false;            // Deve retornar true se value foi removido
    }
    int find(int value) {        // Retorna o índice de value, −1 caso value não esteja presente
        return -1;
    }
    int count(int value) {       // Retorna quantas vezes value occorre no vetor
        return 0;                // Retorna 0 se value não estiver presente
    }
    int sum() {                  // Retorna a soma dos elementos do vetor
        return 0;                // Retorna 0 se o vetor estiver vazio
    }
};
#endif // __VECTOR_LIST_IFRN__