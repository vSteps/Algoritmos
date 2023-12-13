#ifndef __LINKED_SET_IFRN__
#define __LINKED_SET_IFRN__
#include <string>
class linked_set {
private:
    struct node_int{
        int value;
        struct node_int * next, * prev;
    };
    node_int *head, * tail;
    unsigned int size_;
    node_int * get_position(int value){
        node_int * current = this->head;
        while (current != nullptr and current->value != value)
            current = current ->next;
        return current;
    }
public:
    linked_set() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~linked_set() {
        this->clear();
    }
    bool insert(int value) {
        node_int * position = this->get_position(value);
        if (position != nullptr){
            return false;
        } else {
            node_int * node = new node_int;
            node->value = value;
            node->prev = nullptr;
            node->next = this->head;
            this->head = node;
            if (node->next != nullptr)
                node->next->prev = node;
            if (this->tail == nullptr)
                this->tail = this->head;
            this->size_++;
            return true;
        }
            
    }
    bool erase(int value) {
        node_int * position = this->get_position(value);
        if (position == nullptr)
            return false;
        if (position->next != nullptr)
            position->next->prev = position->prev;
        else
            this->tail = position->prev;
        if (position->prev != nullptr)
            position->prev->next = position->next;
        else 
            this->head = position->next;
        delete position;
        this->size_--;
        return true;
    }

    bool find(int value) {
        if (this->get_position(value) != nullptr)
            return true;
        else 
            return false;
    }
    unsigned int size() {
        return this->size_;
    }
    bool empty() {
        return this->head == nullptr;
    }

    void clear() {
        node_int * current = this->head;
        while (current != nullptr){
            node_int * to_remove = current;
            current = current -> next;
            delete to_remove;
        }
        this->size_ = 0;
    }

    std::string to_string(){
        std::string ans = "[";
        node_int *cur = this->head;
        if (cur != nullptr){
            ans+=std::to_string(cur->value);
            cur = cur->next;
            while (cur != nullptr){
                ans+=", ";
                ans+=std::to_string(cur->value);
                cur = cur->next;
            }
        }
        ans+="]";
        return ans;
    }
    
};

#endif // __LINKED_SET_IFRN__