#include "exception.h"
#include "linkedlist.cc"
#include "list.h"
#include "node.h"
#include "print.h"

using std::cout;

template <class T>
class CircularLinkedList : public LinkedList<T> {
public:
    void Display();
    void PushBack(T);
    void PushFront(T);
};

template <class T>
void CircularLinkedList<T>::Display() {
    auto *temp = this->head;

    do {
        cout << temp->data << " --> ";
        temp = temp->next;

    } while (temp != this->head);

    Print();
}

template <class T>
void CircularLinkedList<T>::PushFront(T data) {
    auto *new_node = new Node{data};

    if (this->Empty()) {
        new_node->next = new_node;
        this->head = this->tail = new_node;

    } else {
        new_node->next = this->head;
        this->head = new_node;
        this->tail->next = this->head;
    }

    this->size++;
}

template <class T>
void CircularLinkedList<T>::PushBack(T data) {
    Node<T> *new_node = new Node{data};

    if (this->Empty()) {
        new_node->next = new_node;
        this->head = this->tail = new_node;

    } else {
        this->tail->next = new_node;
        this->tail = new_node;
        this->tail->next = this->head;
    }

    this->size++;
}