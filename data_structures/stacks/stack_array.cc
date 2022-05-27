#include "exception.h"
#include "list.h"
#include "print.h"

template <class T>
class StackArray {
private:
    T* stack_;
    int top_;
    size_t capacity_;

protected:
    size_t size;
    Exception error;

public:
    StackArray() : StackArray(10) {}
    StackArray(size_t);
    ~StackArray();

    size_t length();
};

template <class T>
StackArray<T>::StackArray(size_t size) {
    if (size < 1)
        throw Exception(error.kInvalidValue);

    stack_ = new T[size];
    capacity_ = size;

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