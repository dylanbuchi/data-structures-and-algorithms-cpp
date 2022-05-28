
#include <iostream>

#include "exception.h"
#include "print.h"
#include "queue_array.cc "

template <class T>
class CircularQueue : public QueueArray<T> {
private:
    size_t rear;

    void SetNextPositionFor(size_t &);

public:
    CircularQueue() : CircularQueue<T>(10) {}

    CircularQueue(size_t initial_capacity) : QueueArray<T>(initial_capacity) {
        rear = 0;
    }

    void Display();
    void Push(T);

    T Pop();
};

template <class T>
void CircularQueue<T>::Push(T item) {
    if (not this->Full()) {
        this->queue[rear] = item;

        SetNextPositionFor(rear);

        this->size++;
    }
}

template <class T>
T CircularQueue<T>::Pop() {
    this->HandleEmptyQueue();

    T deleted = this->queue[this->front];

    SetNextPositionFor(this->front);

    this->size--;

    return deleted;
}

template <class T>
void CircularQueue<T>::SetNextPositionFor(size_t &index) {
    index = (index + 1) % this->initial_capacity;
}

template <class T>
void CircularQueue<T>::Display() {
    if (this->Empty())
        return Print("[]");

    size_t index = this->front;

    for (size_t i = 0; i < this->size; ++i) {
        std::string comma_space = (i < this->size - 1) ? ", " : "";
        std::cout << this->queue[index] << comma_space;

        SetNextPositionFor(index);
    }

    Print();
}