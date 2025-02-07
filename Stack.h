#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <list>
#include <stdexcept>

template <typename ty>
class Stack {
    std::list<ty> list;

public:
    Stack() = default;
    ~Stack() = default;

    bool empty() const {
        return this->list.empty();
    }

    size_t size() const {
        return this->list.size();
    }

    void push(const ty& val) {
        this->list.push_back(val);
    }

    void pop() {
        if (!this->list.empty()) {
            this->list.pop_back();
        } else {
            throw std::out_of_range("Stack is empty! Cannot pop.");
        }
    }

    ty& top() {
        if (this->list.empty()) {
            throw std::out_of_range("Stack is empty! No top element.");
        }
        return this->list.back();
    }

    const ty& top() const {
        if (this->list.empty()) {
            throw std::out_of_range("Stack is empty! No top element.");
        }
        return this->list.back();
    }

    void clear() {
        this->list.clear();
    }
};

#endif //STACK_STACK_H
