#include "free_memory.h"
#include "node.h"

template <class T>
class StackLinkedList {
protected:
    Node<T>* head;
    size_t size;

public:
    StackLinkedList();
    ~StackLinkedList();
};

template <class T>
StackLinkedList<T>::StackLinkedList() {
    head = nullptr;
    size = 0;
}

template <class T>
StackLinkedList<T>::~StackLinkedList() {
    FreeMemoryFromLinkedList(head);
    head = nullptr;
}
