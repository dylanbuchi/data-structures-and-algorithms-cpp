#include "exception.h"
#include "free_memory.h"
#include "iostream"
#include "list.h"
#include "node.h"
#include "print.h"

template <class T>
class QueueLinkedList : public IList<T> {
protected:
    Exception error;

    Node<T>*head, *tail;

    size_t size, initial_capacity;

public:
    QueueLinkedList() : QueueLinkedList(10) {}
    QueueLinkedList(size_t);

    ~QueueLinkedList();

    void HandleEmptyQueue();

    bool Empty();
    bool Full();

    void Push(T);
    void Display();

    size_t length();

    T Pop();
    T Peek();
};

template <class T>
QueueLinkedList<T>::QueueLinkedList(size_t initial_capacity) {
    head = tail = nullptr;
    size = 0;

    this->initial_capacity = initial_capacity;
}

template <class T>
QueueLinkedList<T>::~QueueLinkedList() {
    FreeMemoryFromLinkedList(head);
    head = tail = nullptr;
}

template <class T>
bool QueueLinkedList<T>::Empty() {
    return not size;
}

template <class T>
bool QueueLinkedList<T>::Full() {
    return size == initial_capacity;
}

template <class T>
void QueueLinkedList<T>::Display() {
    auto* temp = head;

    while (temp) {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    }

    Print();
}

template <class T>
void QueueLinkedList<T>::Push(T data) {
    Node<T>* new_node = new Node{data};

    if (Empty())
        head = tail = new_node;
    else {
        tail->next = new_node;
        tail = new_node;
    }

    ++size;
}

template <class T>
size_t QueueLinkedList<T>::length() {
    return size;
}

template <class T>
T QueueLinkedList<T>::Pop() {
    HandleEmptyQueue();

    T deleted = head->data;

    if (size == 1) {
        head->next = tail->next = nullptr;
        delete head;

        head = tail = nullptr;
    }

    else {
        auto* next_node = head->next;

        head->next = nullptr;
        delete head;

        head = next_node;
    }

    --size;

    return deleted;
}

template <class T>
T QueueLinkedList<T>::Peek() {
    HandleEmptyQueue();

    return head->data;
}

template <class T>
void QueueLinkedList<T>::HandleEmptyQueue() {
    if (Empty())
        throw Exception(error.kEmpty);
}
