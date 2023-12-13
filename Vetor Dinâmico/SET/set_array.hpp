#ifndef _-SET_IFRN__
#define __SET_IFRN__

class Set {
private:
    int* data;      // Ponteiro para o array de elementos
    unsigned int capacity; // Capacidade atual do array
    unsigned int size;     // Tamanho atual do conjunto
    void increase_capacity(){
        int* new_data = new int[this->capacity_+10];
        for (int i=0 ; i<this->size_ ; ++i)
        new_data[i] = data[i];
        delete [] this->data;
        this->data = new_data;
        this->capacity_ = this->capacity_+10;
    }
    void find_index(){
        for (int i = 0; i < size; i++) {
            data[i] = value;
    }

public:
    // Construtor
    Set() {
        capacity = 1000;    // Comece com uma capacidade inicial (pode ser ajustada conforme necessário)
        data = new int[capacity];
        size = 0;
    }

    // Destrutor
    ~Set() {
        delete[] data;  // Libera a memória alocada para o array
    }

    // Insere 'value' no conjunto caso ele não esteja presente
    // Retorna verdadeiro caso o elemento seja inserido, falso caso contrário.
    bool insert(int value) {
        if (this->find(value)) {
            return false;  // Elemento já existe
        }

        if (this->size == this->capacity) {
            // Se o array estiver cheio, redimensione-o para acomodar mais elementos
            increase_capacity();
        }
        this->data[size] = value;
        this->size++;
        return true;
    }
    bool erase(int value) {
        int i = find_index(value);
        if (i!= -1){
            for (int j = 1 ; j<this->size -1 ; j++)
                this->data[j] = this->data[j+1];
            this->size--;
            return true
        } else
            return false
    }

    bool find(int value) {
       if (find_index(value))
            return true
        else
            return false
    }

    unsigned int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }

    void clear() {
        size = 0;
    }
};

#endif
