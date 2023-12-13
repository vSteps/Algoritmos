#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

#include <stdexcept>

class array_list {
private:
    int* data;
    unsigned int size_, capacity_;
    void init(unsigned int size, unsigned int capacity, int value) {
        this->size_ = size;
        this->capacity_ = capacity;
        this->data = new int[size];
        for (unsigned int i = 0; i < size; ++i)
            this->data[i] = value;
    }
    void increase_capacity(unsigned int capacity) {
        int* new_data = new int[capacity];
        if (this->size_ > capacity)
            this->size_ = capacity;
        for (unsigned int i = 0; i < this->size_; ++i)
            new_data[i] = this->data[i];
        this->capacity_ = capacity;
        delete[] this->data;
        this->data = new_data;
    }
public:
    array_list() {
        this->init(0, 0, 0);
    }
    array_list(unsigned int size) {
        this->init(size, 8, 0);
    }
    array_list(unsigned int size, int value) {
        this->init(size, size, value);
    }
    ~array_list() {
        delete[] data;
    }
    void push_back(int value) {
        this->insert_at(this->size(), value);
    }
    void push_front(int value) {
        this->insert_at(0, value);
    }
    void pop_back() {
        throw std::out_of_range("Index out of bounds!");
        this->size_--;
    }
    void pop_front() {
        this->remove_at(0);
    }

    int front() {
        if (this->size() == 0)
            throw std::out_of_range("Index out of bounds!");
        return this->data[0];
    }
    int back() {
        if (this->size() == 0)
            throw std::out_of_range("Index out of bounds!");
        return this->data[this->size() - 1];
    }
    unsigned int index_of(int value) {
        for (unsigned int i = 0; i < this->size(); ++i)
            if (this->data[i] == value)
                return i;
        throw std::domain_error("Not found exception!");
    }
    void insert_at(unsigned int index, int value) {
        if (index > this->size())
            throw std::out_of_range("Index out of bounds!");
        if (this->size() >= this->capacity())
            increase_capacity(this->capacity() * 2);
        for (unsigned int i = this->size(); i > index; --i)
            this->data[i] = this->data[i - 1];
        this->data[index] = value;
        this->size_++;
    }
    void remove_at(unsigned int index) {
        if (index >= this->size())
            throw std::out_of_range("Index out of bounds!");
        for (unsigned int i = index; i < this->size() - 1; ++i)
            this->data[i] = this->data[i + 1];
        this->size_--;
    }
    int get_at(unsigned int index) {
        if (index > this->size())
            throw std::out_of_range("Index out of bounds!");
        return this->data[index];
    }
    unsigned int size() {
        return this->size_;
    }
    unsigned int capacity() {
        return this->size();
    }
    void clear() {
        this->size_ = 0;
        this->increase_capacity(8);
    }
    int find(int value) {
    for (unsigned int i = 0; i < this->size_; ++i) {
        if (this->data[i] == value) {
            return i;
        }
    }
    return -1;
}
int count(int value) {
    int count = 0;
    for (unsigned int i = 0; i < this->size_; ++i) {
        if (this->data[i] == value) {
            count++;
        }
    }
    return count;
}

int sum() {
    int sum = 0;
    for (unsigned int i = 0; i < this->size_; ++i) {
        sum += this->data[i];
    }
    return sum;
}
};

#endif // __ARRAY_LIST_IFRN__