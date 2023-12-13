#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
private:
    int* data;
    unsigned int size_, capacity_; 
    void increase_capacity() { //aumenta a capacidade do array
        int* new_data = new int[this->capacity_+1000]; // É mais eficiente dobrar a capacidade do array
        for (unsigned int i = 0; i < this->size_; ++i) // (detalhes no relatório)
            new_data[i] = this->data[i];
        this->capacity_ = this->capacity_+1000;
        delete[] this->data;
        this->data = new_data;
    }
public:
    array_list() { // Construtor
        data = new int[1000];
        this->size_ = 0;
        this->capacity_ = 1000;
    }
    ~array_list() { // Destrutor
        delete[] data;
    }
    unsigned int size() { // Retorna o tamanho
        return this->size_;
    }
    unsigned int capacity() { // Retorna a capacidade
        return this->capacity_;
    }
    double percent_occupied() { // Retorna a % da capacidade usada
     if (this->size_ == 0){
            return 0.0;
        }

    return (double)this->size_ / this->capacity_;
    }
    bool insert_at(unsigned int index, int value) { // Insere um valor no índice
        if (index > this->size())
            return false;
        if (this->size() >= this->capacity())
            increase_capacity();
        for (unsigned int i = this->size(); i > index; --i)
            this->data[i] = this->data[i - 1];
        this->data[index] = value;
        this->size_++;
        return true;
    }
    bool remove_at(unsigned int index) { // Remove no índice
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // Retorna o valor do índice
        if (index >= this->size_)
            return -1; // Se o índice nao for válido, retorna -1
        return this->data[index];
    }
    void clear() {
        this->size_ = 0;
    }
    void push_back(int value) { // Inserir na última posição
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) { // Inserir na primeira posição
        this->insert_at(0, value);
    }
    bool pop_back() { // Remove na última posição
        if(this->size_ == 0){
            return false;
        }
        this->size_--;
        return true;
    }
    bool pop_front() { // Remove na primeira posição
        if(this->size_ == 0){
            return false;
        }
        
        for (unsigned int i = 0; i < this->size_ - 1; ++i)
            this->data[i] = this->data[i + 1];
        this->size_--;
        return true;
    }
    int front(){ // Retorna o primeiro elemento
        if (this->size_ == 0){
            return -1;
        }
        return this->data[0];
    }
    int back(){ // Retorna o último elemento
        if (this->size_ == 0){
            return -1;
        }
        return this->data[size_ -1];
    }
    bool remove(int value) { // Remove um elemento pelo valor
        for (unsigned int i = 0; i < this->size_; ++i)
            if (this->data[i] == value){
                for (unsigned int i; i < this->size_ - 1; ++i)
                    this->data[i] = this->data[i + 1];
            this->size_--;
            return true;
        }
        return false;
    }
    int find(int value) { // Procura um valor e retorna o índice dele na lista
        for (unsigned int i = 0; i < this->size_; ++i){
            if (this->data[i] == value)
                return i;
                }
                  return -1;        // Se nao encontrar, retorna -1
        }
    int count(int value) { // Conta a quantidade de vezes que um elemento aparece no array
        int qtd =0;
        for (unsigned int i = 0; i < this->size_; ++i)
            if (this->data[i] == value){
                qtd++;
            }
        return qtd;
    }
    int sum() { // Retorna a soma de todos os elementos do array
        if (this->size_ == 0){
            return -1;
        }
        int sum = 0;
        for(unsigned int i = 0; i<this->size_; i++){
            sum = sum+this->data[i];
        }
        return sum;
    }
};


#endif // __ARRAY_LIST_IFRN__