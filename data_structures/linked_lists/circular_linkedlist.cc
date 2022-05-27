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

    T PopFront();
    T PopBack();
};

template <class T>
void CircularLinkedList<T>::Display() {
    this->HandleEmptyLinkedList();

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

template <class T>
T CircularLinkedList<T>::PopFront() {
    this->HandleEmptyLinkedList();

    T deleted;

    if (this->size == 1) {
        deleted = this->head->data;

        this->head->next = nullptr;
        delete this->head;

        this->head = this->tail = nullptr;

    } else {
        auto *temp = this->head;

        deleted = temp->data;

        this->head = temp->next;
        this->tail->next = this->head;

        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    this->size--;

    return deleted;
}

template <class T>
T CircularLinkedList<T>::PopBack() {
    this->HandleEmptyLinkedList();

    if (this->size == 1)
        return PopFront();

    auto *previous_node = this->GetNodeAt(this->size - 1);

    auto deleted = this->tail->data;

    this->tail->next = nullptr;
    delete this->tail;
    this->tail = nullptr;

    this->tail = previous_node;
    this->tail->next = this->head;

    this->size--;

    return deleted;
}