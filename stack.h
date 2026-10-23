
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <cstddef>

template <typename T>
class Stack : public std::vector<T>
{
public:
    Stack() : std::vector<T>() {}

    ~Stack() = default;

    bool empty() const {
        return std::vector<T>::empty();
    }

    size_t size() const {
        return std::vector<T>::size();
    }

    void push(const T& item) {
        std::vector<T>::push_back(item);
    }

    void pop() {
        if (std::vector<T>::empty()) {
            throw std::underflow_error("Cannot pop an empty stack");
        }

        std::vector<T>::pop_back();
    }

    const T& top() const {
        if (std::vector<T>::empty()) {
            throw std::underflow_error("Cannot access top of an empty stack");
        }

        return std::vector<T>::back();
    }
};

#endif
