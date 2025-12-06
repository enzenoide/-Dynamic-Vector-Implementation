#ifndef __VECTOR_ARRAY_IFRN__
#define __VECTOR_ARRAY_IFRN__
class vector_array {
private:
    int *data;
    unsigned int size_, capacity_; // cada vector vai possuir um atributo size, capacity e increase_size
    void increase_capacity() {// OBS: TIREI O INCREASE_SIZE, PQ NÃO PRECISARIA JÁ QUE A LISTA DOBRA,SERIA DESNECESSARIO
        this -> capacity_ *= 2; // para aumentar a capacidade, somar a capacity cm o increase_size
        int *new_data = new int[this -> capacity_]; // alocar um novo array na memoria com o novo valor de capacity
        for(unsigned int i = 0; i < this -> size_; ++i){
            new_data[i] = data[i]; // copiar o array antigo no array novo
        }
        delete [] this -> data; // deletar o array antigo
        this -> data = new_data; // o array atual vira o novo array
    }

public:
    vector_array() {
        this -> size_ = 0;
        this -> capacity_ = 8;
        this -> data = new int[capacity_];         
    }
    ~vector_array() { // Destrutor
        delete [] this -> data;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this -> size_;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this -> capacity_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual da
        return double(size()) / capacity();               // memória usada.
    }
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if(index > this -> size_){
            return false;
        }
        if(this -> size_ == capacity_){
            increase_capacity();
        }
        for(unsigned int i = this -> size_; i > index; --i){
            data[i] = data[i-1];
        }
        data[index] = value;
        this -> size_++;
        return true;
    }
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if(index >= this -> size_){
            return false;
        }
        for(unsigned int i = index; i < this -> size_ - 1; ++i){
            data[i] = data[i+1];
        }
        this -> size_--;
        if(this -> size_ < this -> capacity_ / 4){ // se o tamanho da lista for menor que 1/4 da capacidade da lista, a lista reduz na metade
            if(this -> capacity_ < 8){
                return true;
            }
            this -> capacity_ /= 2;
            int *new_data = new int[this -> capacity_];
            for(unsigned int i = 0; i < this -> size_; ++i ){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        return true;
    }
    bool is_empty() { // Retorna true se o vetor não contém elementos
        if(this -> size_ == 0){
            return true;
        }
        else{
            return false;
        }
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index                  // −1 se índice inválido
        if(index >= this -> size_ ){
            return -1;
        }
        return data[index];
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        //delete [] data;
        //capacity_ = 100; // QUER Q VOLTE AO ESTADO INICIAL OU SÓ LIMPE?
        //increase_size_ = 100;
        //size_ = 0;
        //data = new int[capacity_];
        this -> size_ = 0;
    }
    void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
        if(this -> size_ >= this -> capacity_){
            increase_capacity();
        }
        data[this -> size_++] = value;
    }
    void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
        insert_at(0,value);
    }
    bool pop_back() {            // Remove um elemento do ``final'' do vetor
        if(this -> size_ == 0){
            return false;
        }
        this -> size_--;
        return true;
    }
    bool pop_front() {           // Remove um elemento do ``início'' do vetor
        if(this -> size_ == 0){
            return false;
        }
        return remove_at(0);
    }
    int back() {                 // Retorna o elemento do ``final'' do vetor
        if(this -> size_ == 0){
            return -1;
        }
        return data[this -> size_ -1];
    }
    int front() {                // Retorna o elemento do ``início'' do vetor
        if(this -> size_ == 0){
            return -1;
        }
        return data[0];
    }
    bool remove(int value) {     // Remove value do vetor caso esteja presente
        int index = find(value);            // Deve retornar true se value foi removido
        if(index == -1){
            return false;
        }
        return remove_at(index);
    }
    int find(int value) {        // Retorna o índice de value, −1 caso value não esteja presente
        for(unsigned int i = 0; i < this -> size_; ++i){
            if(data[i] == value){
                return i;
            }
        }
        return -1;
    }
    int count(int value) {       // Retorna quantas vezes value occorre no vetor
        if(this -> size_ == 0){
            return 0;
        }
        int count = 0;                // Retorna 0 se value não estiver presente
        for(unsigned int i = 0; i < this -> size_; ++i){
            if(data[i] == value){
                count++;
            }
        }
        return count;
    }
    int sum() {                  // Retorna a soma dos elementos do vetor
        int sum = 0;                // Retorna 0 se o vetor estiver vazio
        if(this -> size_ == 0){
            return 0;
        }
        for(unsigned int i = 0; i < this -> size_; ++i){
            sum += data[i];
        }
        return sum;
    }
    bool remove_all(int value){
        bool removed = false; // seta uma variavel bool para false para poder fazer a verificação
        while(remove(value)){ // enquanto tiver valor, (remove = true)  a variavel removed vai ser true
            removed = true; //
        }
        return removed; // retornar a variavel
    }
    bool remove_range(unsigned int a, unsigned int b){
        for(unsigned int i = a; i < b;++i){
            remove(data[i]);
        }
        return true;
    }
};
#endif // __VECTOR_LIST_IFRN__