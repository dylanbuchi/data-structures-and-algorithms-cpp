#include "exception.h"
#include "list.h"
#include "print.h"

template <class T>
class StackArray : public IList<T> {
private:
    size_t capacity_;

    int top_;

    T* stack_;

protected:
    Exception error;

    size_t size;

    void HandleEmptyStack();

public:
    StackArray() : StackArray(10) {}
    StackArray(size_t);

    ~StackArray();

    size_t length();

    bool Empty();
    bool Full();

    void Display();
    void Push(T);

    T Pop();
    T Peek();
};

template <class T>
StackArray<T>::StackArray(size_t initial_capacity) {
    if (initial_capacity < 1)
        throw Exception(error.kInvalidValue);

    stack_ = new T[initial_capacity];
    capacity_ = initial_capacity;

    top_ = -1;
    size = 0;
}

template <class T>
StackArray<T>::~StackArray() {
    delete[] stack_;
}

template <class T>
size_t StackArray<T>::length() {
    return size;
}

template <class T>
bool StackArray<T>::Empty() {
    return not size;
}

template <class T>
bool StackArray<T>::Full() {
    return size == capacity_;
}

template <class T>
void StackArray<T>::Display() {
    PrintArray(stack_, size);
}

template <class T>
void StackArray<T>::Push(T item) {
    if (not Full()) {
        stack_[++top_] = item;
        size++;
    }
}

template <class T>
T StackArray<T>::Pop() {
    HandleEmptyStack();

    T deleted = stack_[top_--];
    size--;

    return deleted;
}

template <class T>
T StackArray<T>::Peek() {
    HandleEmptyStack();

    return stack_[top_];
}

template <class T>
void StackArray<T>::HandleEmptyStack() {
    if (Empty())
        throw Exception(error.kEmpty);
}
