#ifndef __SET_IFRN__
#define __SET_IFRN__

class Set {
private:
    int* current;
    int *to_remove;
public:
    // Construtor
    Set() {
    lista1->head=0;
    lista1->tail=0;
    return 0;
    }


    ~Set(){
    current = this->first;
    while (current!=0){
    to_remove = current;
    current = current->next;
    delete current;
}
}
    }
    // Insere 'value' no conjunto caso ele não esteja presente
    // Retorna verdadeiro caso o elemento seja inserido, falso caso contrário.
    bool insert(int value) {
    
    }
    bool erase(int value) {

    }

    bool find(int value) {

    unsigned int getSize() {
    }

    bool empty() {
    }

    void clear() {
    }
};
#endif