#ifndef __VECTOR_LINKED_IFRN__
#define __VECTOR_LINKED_IFRN__
class vector_linked {
private:
    struct int_node {
        int value;
        int_node *next, *prev;
    };
    int_node *head, *tail;
    unsigned int size_;

public:
    vector_linked() {
        this -> head = 0;
        this -> tail = 0; 
    }
    ~vector_linked() {
        int_node *current,*to_remove;
        current = this -> head;
        while(current != nullptr){
            to_remove = current;
            current = current -> next;
            delete current;
        }
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        int i = 0;
        if(is_empty()){
            return 0;
        }
        if(head == tail){
            return 1;
        }
        int_node *current = head;
        while(current != nullptr){
            i++;
        }
        return i;
    }
    unsigned int capacity() { // Retorna o espaço
        return 0;
    } // reservado para armazenar os elementos
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0
        return 0;               // com o percentual da memória usada.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        int_node* current = head;
        int_node *new_node = new int_node;
        if(index < 0 || index > size_){
            return false;
        }
        for(int i = 0; i < index; ++i){
            current = current -> next;
        }
        if(this -> head == this -> tail){

        }
        new_node -> prev = current -> prev; // o prev do new_node aponta para o prev do atual
        new_node -> next = current -> next; // o next do new_node aponta para o next do current
        current -> prev -> next = new_node; // o next do prev do current aponta para o new_node
        current -> prev = new_node; // o prev do current aponta para o new_node

        size_++;
        return true;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        return false;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        if(this -> head == 0){
            return true;
        }
        else{
            return false;
        };
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index,
        return -1;                   // −1 se índice inválido
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int_node *current,*to_remove;
        current = this -> head;
        while(current != nullptr){
            to_remove = current;
            current = current -> next;
            delete current;
        }
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        int_node *new_node = new int_node;
        new_node -> value = value; // o valor do new_node aponta para value
        new_node -> next = nullptr; // o next de new_node aponta para NULL
        new_node -> prev = this -> tail; // o anterior do new_node aponta para o atual tail

        if(is_empty()){ // se a lista n tiver head o head aponta para o new_node
            this -> head = new_node;
        }
        else{ // se não
            this -> tail -> next = new_node; // o next do tail aponta para o new_node
        }
        this -> tail = new_node; // o tail agora aponta para o new_node
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        int_node *new_node = new int_node;
        new_node -> value = value;
        new_node -> next = this -> head;
        new_node -> prev = nullptr;
        if(this -> tail == nullptr){
            this -> tail = new_node;
        }
        else{
            this -> head -> prev = new_node;
        }
        this -> head = new_node;
    }
    bool pop_back() { // Remove um elemento do ``final'' do vetor
        if(is_empty()){
            return;
        }
        if(this -> head == this -> tail){
            delete this -> head;
            this -> head = nullptr;
            this -> tail = nullptr;
        }
        this -> tail = this -> tail -> prev;
        delete this -> tail;
        this -> tail -> next = nullptr;
    }
    bool pop_front() { // Remove um elemento do ``início'' do vetor
        if(is_empty()){
            return;
        }
        if(this -> head == this -> tail){
            delete this -> head;
            this -> head = nullptr;
            this -> tail = nullptr;
        }
        this -> head = this -> head -> next;
        delete this -> head -> prev;
        this -> head -> prev = nullptr;
    }
    int back() { // Retorna o elemento do ``final'' do vetor
        if(is_empty()){
            return -1;
        }
        return this -> tail -> value;
    }
    int front() { // Retorna o elemento do ``início'' do vetor
        if(is_empty()){
            return -1;
        }
        return this -> head -> value;
    }
    bool remove(int value) { // Remove value do vetor caso esteja presente
        
    }
    int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
        int i = 0;
        int_node *current = head;
        if(is_empty()){
            return -1;
        }
        if(this -> head == this -> tail){
            return 0;
        }
        while(current != nullptr){
            if(current -> value == value){
                return i;
            }
            else{
                ++i;
            }
        }
        return -1;
    }
    int count(int value) { // Retorna quantas vezes value occorre no vetor
        int count = 0;
        int_node *current = head;
        if(is_empty()){
            return 0;
        }
        if(this -> head == this -> tail){
            return 1;
        }
        while(current != nullptr){
            if(current -> value == value){
                count ++;
            }
        }
        return count;
    }
    int sum() { // Retorna a soma dos elementos do vetor
        int ans = 0;
        int_node *current = head;
        if(is_empty()){
            return 0;
        }
        if(this -> head == this -> tail){
            return 0;
        }
        while(current != nullptr){
            ans += current -> value;
        }
        return ans;
    }
};
#endif // __VECTOR_LINKED_IFRN__