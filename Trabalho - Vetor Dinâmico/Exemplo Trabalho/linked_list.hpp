#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

#include <stdexcept>

class linked_list {
private:
    struct node {
        int value;
        node* next, * prev;
    };
    node* head, * tail;
    unsigned int size_;

    void init(unsigned int size, int value) { // Inicia head e tail como nullprt
        this->head = nullptr;
        this->tail = nullptr;
        for (unsigned int i = 0; i < size; ++i) // Cria um nó para cada elemento da lista
            this->push_back(value);
    }
public:
    linked_list() { // Construtor padrão com size e value começando com 0
        this->init(0, 0);
    }
    linked_list(unsigned int size) { // Construtor que recebe um parâmetro size
        this->init(size, 0);
    }
    linked_list(unsigned int size, int value) { // Contrutor que recebe size e value como parâmetros
        this->init(size, value);
    }
    ~linked_list() { // Destrutor
        node* cur = this->head;
        while (cur != nullptr) {
            node* rem = cur;
            cur = cur->next;
            delete rem;
        }
    }

    unsigned int size() { // Retorna o tamanho do array
    return this->size_;
    }

    unsigned int capacity() {
    // O tamanho da lista é o mesmo que a sua capacidade.
    return this->size;
}

double percent_occupied() {
    // Se a lista estiver vazia, o percentual ocupado é 0.0.
    if (this->size == 0) {
        return 0.0;
    }

    // O percentual ocupado é igual à quantidade de elementos armazenados
    // dividido pela capacidade da lista.
    return (double)this->size / this->capacity;
}
    void push_back(int value) { // Adiciona um elemento ao final do vetor
        node* new_node = new node;
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
    void push_front(int value) { // Adiciona um elemento ao inicio do vetor
        node* new_node = new node;
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
    void pop_back() { // Remove o último elemento do vetor
        if (this->tail == nullptr)
            throw std::out_of_range("Index out of bounds!");
        if (this->head == this->tail) {
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        }
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = nullptr;
        this->size_--;
    }
    void pop_front() { // Remove o primeiro elemento do vetor
        if (this->head == nullptr)
            throw std::out_of_range("Index out of bounds!");
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
    }
    int front() { // Retorna o primeiro elemento
        if (this->size() == 0)
            throw std::out_of_range("Index out of range!");
        return this->head->value;
    }
    int back() { // Retorna o último elemento
        if (this->size() == 0)
            throw std::out_of_range("Index out of range!");
        return this->tail->value;
    }
    unsigned int index_of(int value) { // Retorna o índice de value e se não achar, throw std
        unsigned int index = 0;
        node* cur = this->head;
        while (cur != nullptr) {
            if (cur->value == value)
                return index;
            index++;
            cur = cur->next;
        }
        throw std::domain_error("Not found exception!");
    }
    void insert_at(unsigned int index, int value) { // Insere um elemento no índice especificado
        if (index > this->size())
            throw std::out_of_range("Index out of bounds!");
        node* cur = this->head;
        for (int i=0 ; i<index ; ++index)
            cur = cur->next;
        node * new_node = new node;
        new_node->value = value;
        new_node->next = cur;
        new_node->prev - cur->prev;
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
void remove_at(unsigned int index) {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds!");
    }

    node* current = this->head;
    for (unsigned int i = 0; i < index - 1; ++i) {
        current = current->next;
    }

    node* to_remove = current->next;
    if (to_remove == this->tail) {
        this->tail = current;
    }
    current->next = to_remove->next;

    delete to_remove;
    this->size--;
}

int get_at(unsigned int index) {
    if (index >= this->size) {
        throw std::out_of_range("Index out of bounds!");
    }

    node* current = this->head;
    for (unsigned int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->value;
}


    void clear() { // Limpa o array
        node * cur = this->head;
        while (cur != nullptr){
            node * to_remove = cur;
            cur = cur->next;
            delete to_remove;
        }
        this->size_ = 0;
    }
};

#endif // __LINKED_LIST_IFRN__