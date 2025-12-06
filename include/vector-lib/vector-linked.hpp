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
        int_node *current = this -> head;
        int_node *to_remove;
        while(current != nullptr){
            to_remove = current;
            current = current -> next;
            delete to_remove;
        }
        this -> head = nullptr;
        this -> size_ = 0;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        unsigned int i = 0;
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
        return size();
    } // reservado para armazenar os elementos
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0
        return size()/size();               // com o percentual da memória usada.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        int_node* current = head;
        int_node *new_node = new int_node;
        new_node -> value = value;
        if(index > size_){
            return false;
        }
        if(size_ == 0){
            head = new_node;
            tail = new_node;
            new_node -> prev = nullptr;
            new_node -> next = nullptr;
        }
        else if(index == 0){
            new_node -> prev = nullptr;
            new_node -> next = head;
            head -> prev = new_node;
            head = new_node;
        }
        else if(index == size_){
            new_node -> next = nullptr;
            new_node -> prev = tail;
            tail -> next = new_node;
            tail = new_node;
        }
        else{
        
        for(unsigned int i = 0; i < index - 1; ++i){
            current = current -> next;
        }
        new_node -> prev = current;
        new_node -> next = current -> next;
        current -> next -> prev = new_node;
        current -> next = new_node;
        }
        size_++;
        return true;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        int_node *to_delete = head;
        if(index > size_ || size_ == 0){
            return false;
        }
        for(unsigned i = 0; i < index; ++i){
            to_delete = to_delete -> next;
        }
        if(to_delete == head){
            head = to_delete -> next;
        }
        if(to_delete == tail){
            tail = to_delete -> prev;
        }
        if(to_delete -> next != nullptr){
            to_delete -> next -> prev = to_delete -> prev;
        }
        if(to_delete -> prev != nullptr){
            to_delete -> prev -> next = to_delete -> next;
        }

        delete to_delete;
        size_--;
        return true;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        if(this -> head == nullptr){
            return true;
        }
        else{
            return false;
        };
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index,                   // −1 se índice inválido
        if(index >= size_ || size_ == 0){
            return -1;
        }
        int_node *current = head;
        for(unsigned i = 0; i < index; ++i){
            current = current -> next;
        }
        return current -> value;
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int_node *current = this -> head;
        int_node *to_remove;
        while(current != nullptr){
            to_remove = current;
            current = current -> next;
            delete to_remove;
        }
        this -> head = nullptr;
        this -> size_ = 0;
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
        int_node *to_delete = tail;
        if(is_empty()){
            return false;
        }
        if(this -> head == this -> tail){
            delete this -> head;
            this -> head = nullptr;
            this -> tail = nullptr;
        }
        else{
        this -> tail = to_delete -> prev;
        this-> tail -> next = nullptr;
        delete to_delete;

        }
        size_--;
        return true;
        
    }
    bool pop_front() { // Remove um elemento do ``início'' do vetor
        if(is_empty()){
            return false;
        }
        if(this -> head == this -> tail){
            delete this -> head;
            this -> head = nullptr;
            this -> tail = nullptr;
        }
        this -> head = this -> head -> next;
        delete this -> head -> prev;
        this -> head -> prev = nullptr;
        return true;
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
        return false;
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