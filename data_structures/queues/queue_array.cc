#include <iostream>

#include "exception.h"
#include "list.h"
#include "print.h"

template <class T>
class QueueArray : IList<T> {
protected:
    Exception error;
    T* queue;

    int rear;

    size_t front;

    size_t initial_capacity;
    size_t size;

public:
    QueueArray() : QueueArray(10) {}
    QueueArray(size_t);

    ~QueueArray();

    bool Empty();
    bool Full();

    void Push(T);
    void Display();

    size_t length();

    T Pop();
    T Peek();

    void HandleEmptyQueue();
};

template <class T>
QueueArray<T>::QueueArray(size_t initial_capacity) {
    this->initial_capacity = initial_capacity;

    queue = new T[initial_capacity];

    front = size = 0;
    rear = -1;
}

template <class T>
QueueArray<T>::~QueueArray() {
    delete[] queue;
    queue = nullptr;
}

template <class T>
bool QueueArray<T>::Empty() {
    return not size;
}

template <class T>
bool QueueArray<T>::Full() {
    return size == initial_capacity;
}

template <class T>
void QueueArray<T>::Push(T item) {
    if (not Full()) {
        queue[++rear] = item;
        ++size;
    }
}

template <class T>
void QueueArray<T>::HandleEmptyQueue() {
    if (Empty())
        throw Exception(error.kEmpty);
}

template <class T>
T QueueArray<T>::Pop() {
    HandleEmptyQueue();

    T deleted = queue[front++];

    --size;
    return deleted;
}

template <class T>
T QueueArray<T>::Peek() {
    HandleEmptyQueue();

    return queue[front];
}

template <class T>
void QueueArray<T>::Display() {
    if (Empty())
        return Print("[]");

    for (size_t i = front; i <= (size_t)rear; ++i) {
        std::string comma_space = (i < (size_t)rear) ? ", " : "";
        std::cout << queue[i] << comma_space;
    }

    Print();
}

template <class T>
size_t QueueArray<T>::length() {
    return size;
}
