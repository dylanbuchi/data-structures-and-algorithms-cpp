#include <iostream>

#include "linkedlist.cc"

using std::cout;

template <class T>
class DoublyLinkedList : public LinkedList<T> {
public:
    void Display();

    void PushBack(T);
    void PushFront(T);

    void InsertAt(size_t, T);

    T PopFront();
    T PopBack();

    T RemoveAt(size_t);
};

template <class T>
void DoublyLinkedList<T>::Display() {
    this->HandleEmptyLinkedList();

    auto* temp = this->head;

    cout << "[";
    while (temp) {
        cout << temp->data << " <==> ";
        temp = temp->next;
    }

    Print("]");
}

template <class T>
void DoublyLinkedList<T>::PushBack(T data) {
    Node<T>* new_node = new Node{data};

    if (this->Empty())
        this->head = this->tail = new_node;

    else {
        new_node->prev = this->tail;

        this->tail->next = new_node;
        this->tail = new_node;
    }

    this->size++;
}

template <class T>
void DoublyLinkedList<T>::PushFront(T data) {
    Node<T>* new_node = new Node{data};

    if (this->Empty())
        this->head = this->tail = new_node;

    else {
        new_node->next = this->head;
        this->head->prev = new_node;

        this->head = new_node;
    }

    this->size++;
}

template <class T>
T DoublyLinkedList<T>::PopFront() {
    this->HandleEmptyLinkedList();

    T deleted = this->head->data;

    if (this->size == 1) {
        delete this->head;
        this->head = this->tail = nullptr;

    } else {
        auto* next_node = this->head->next;

        this->head->next = next_node->prev = nullptr;

        delete this->head;

        this->head = next_node;
    }

    this->size--;

    return deleted;
}

template <class T>
T DoublyLinkedList<T>::PopBack() {
    this->HandleEmptyLinkedList();

    T deleted = this->tail->data;

    if (this->length() == 1)
        return PopFront();

    else {
        auto* previous_node = this->tail->prev;
        previous_node->next = this->tail->prev = nullptr;

        delete this->tail;

        this->tail = previous_node;
    }

    this->size--;

    return deleted;
}
template <class T>
T DoublyLinkedList<T>::RemoveAt(size_t position) {
    this->HandleEmptyLinkedList();
    this->HandlePosition(position);

    if (position == 1)
        return PopFront();

    if (position == this->size)
        return PopBack();

    auto* current_node = this->GetNodeAt(position);

    T deleted = current_node->data;

    auto* previous_node = current_node->prev;

    current_node->prev = nullptr;

    previous_node->next = current_node->next;

    current_node->next->prev = previous_node;
    current_node->next = nullptr;

    delete current_node;
    current_node = nullptr;

    this->size--;

    return deleted;
}

template <class T>
void DoublyLinkedList<T>::InsertAt(size_t position, T data) {
    if (position == this->size + 1)
        return PushBack(data);

    if (position == 1)
        return PushFront(data);

    this->HandlePosition(position);

    Node<T>* new_node = new Node{data};

    auto* current_node = this->GetNodeAt(position);

    auto* previous_node = current_node->prev;

    new_node->next = current_node;
    new_node->prev = previous_node;

    previous_node->next = new_node;

    current_node->prev = new_node;

    this->size++;
}