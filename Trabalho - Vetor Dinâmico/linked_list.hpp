#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() { // Construtor
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() { // Destrutor
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() { // Retorna o tamanho
        return this->size_;
    }
    unsigned int capacitty() { // Em lista ligada, capacidade = tamanho. Logo, retorna o tamanho
        return this->size_;
    }
    double percent_occupied() { // Retorna a porcentagem da capacidade usada(detalhes no relatório)
        if (this->size_ == 0){
            return 0.0;
        }

    return 1.0;
    }
    bool insert_at(unsigned int index, int value) { // Insere um valor no índice
          if (index > this->size_)
            return false;
        int_node* current = this->head;
        for (unsigned int i=0 ; i<index ; ++index)
            current = current->next;
        int_node * new_node = new int_node;
        new_node->value = value;
        new_node->next = current;
        new_node->prev = current->prev;
        if (new_node->next != nullptr)
            new_node->next->prev = new_node;
        else 
            this->tail = new_node;
        if (new_node->prev != nullptr)
            new_node->prev->next = new_node;
        else 
            this->head = new_node;
        this->size_++;
    }
    bool remove_at(unsigned int index) { // Remove um valor no índice
    if (index >= this->size_) {
       return false;
    }

    int_node* current = this->head;
    for (unsigned int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    int_node* to_remove = current->next;
    if (to_remove == this->tail) {
        this->tail = current;
    }
    current->next = to_remove->next;

    delete to_remove;
    this->size_--;
    return true;
}
    int get_at(unsigned int index) { // Retorna o valor do índice
            if (index >= this->size_) {
                return -1;
    }

    int_node* cur = this->head;
    for (unsigned int i = 0; i < index; ++i) {
        cur = cur->next;
    }

    return cur->value;
    }
    void clear() { // Limpa o array, ou seja fica com tamanho 0
            if(this->head == nullptr) return;
        int_node* current = this->head->next;
        while(current != nullptr){
            delete current->prev;
            current = current->next;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0; 
    }
    void push_back(int value) { // Adiciona um valor ao final da lista
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        if (this->head == nullptr)
            this->head = new_node;
        else
            this->tail->next = new_node;
        this->tail = new_node;
        this->size_++;
    }
    void push_front(int value) { // Adiciona um valor ao início da lista
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_++;
    }
    bool pop_back() { // Remove um valor do final da lista
        if (this->tail == nullptr)
            return false;
        if (this->head == this->tail) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->size_--;
        return true;
    }
    bool pop_front() { // Remove um valor do começo da lista
        if (this->head == nullptr)
           return false;
        if (this->tail == this->head) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = nullptr;
        }
        this->size_--;
        return true;
    }
    int front() { // Retorna o primeiro valor da lista
        if (this->size() == 0)
            return -1;
        return this->head->value;
    }
    int back() { // Retorna o último valor da lista
        if (this->size() == 0)
            return -1;
        return this->tail->value;
    }
    
bool remove(int value) { // Remove um valor da lista
    int_node* current = this->head;
    while (current != nullptr) {
        if (current->value == value) {
            if (current == this->head) {
                this->head = current->next;
            } else if (current == this->tail) {
                this->tail = current->prev;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            this->size_--;
            return true;
        }

        current = current->next;
    }

    return false;
}

int find(int value) { // Procura um valor na lista e o retorna
    int_node* current = this->head;
    unsigned int index = 0;
    while (current != nullptr) {
        if (current->value == value) {
            return index;
        }

        index++;
        current = current->next;
    }

    return -1;
}

int count(int value) { // Conta a quantidade de vezes que um elemento aparece no array
    int_node* current = this->head;
    int count = 0;
    while (current != nullptr) {
        if (current->value == value) {
            count++;
        }

        current = current->next;
    }

    return count;
}

int sum() {
    int_node* current = this->head;
    int sum = 0;
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
    }

    return sum;
}
};

#endif // __LINKED_LIST_IFRN__