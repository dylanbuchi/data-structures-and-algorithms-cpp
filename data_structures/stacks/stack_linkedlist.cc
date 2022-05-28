#include "exception.h"
#include "free_memory.h"
#include "list.h"
#include "node.h"
#include "print.h"

template <class T>
class StackLinkedList : public IList<T> {
protected:
    Exception error;

    Node<T>* head;

    size_t size;
    size_t initial_capacity;

public:
    StackLinkedList() : StackLinkedList(10) {}
    StackLinkedList(size_t);
    ~StackLinkedList();

    void HandleEmptyStack();

    bool Empty();
    bool Full();

    void Push(T);
    void Display();

    size_t length();

    T Pop();
    T Peek();
};

template <class T>
StackLinkedList<T>::StackLinkedList(size_t initial_capacity) {
    head = nullptr;
    size = 0;

    this->initial_capacity = initial_capacity;
}

template <class T>
StackLinkedList<T>::~StackLinkedList() {
    FreeMemoryFromLinkedList(head);
    head = nullptr;
}

template <class T>
bool StackLinkedList<T>::Empty() {
    return not size;
}

template <class T>
bool StackLinkedList<T>::Full() {
    return size == initial_capacity;
}

template <class T>
void StackLinkedList<T>::Display() {
    auto* temp = head;

    while (temp) {
        Print(temp->data);
        temp = temp->next;
    }
}

template <class T>
void StackLinkedList<T>::Push(T data) {
    Node<T>* new_node = new Node{data};

    if (Empty())
        head = new_node;
    else {
        new_node->next = head;
        head = new_node;
    }

    ++size;
}

template <class T>
size_t StackLinkedList<T>::length() {
    return size;
}

template <class T>
T StackLinkedList<T>::Pop() {
    HandleEmptyStack();

    T deleted = head->data;

    if (size == 1) {
        head->next = nullptr;
        delete head;
        head = nullptr;
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
T StackLinkedList<T>::Peek() {
    HandleEmptyStack();

    return head->data;
}

template <class T>
void StackLinkedList<T>::HandleEmptyStack() {
    if (Empty())
        throw Exception(error.kEmpty);
}
