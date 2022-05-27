#include "linkedlist.h"

#include "exception.h"
#include "node.h"
#include "print.h"

template <class T>
class LinkedList : public ILinkedList<T> {
private:
    Node<T> *ReverseRecursively_(Node<T> *, Node<T> *);
    Node<T> *Reverse_();

protected:
    size_t size;

    Node<T> *head, *tail;

    Node<T> *GetNodeAt(size_t);

    Exception error;

    void HandlePosition(size_t);
    void HandleEmptyLinkedList();

public:
    LinkedList();
    ~LinkedList();

    int Find(T);

    bool Empty();

    void PushFront(T);
    void PushBack(T);

    void InsertAt(size_t, T);

    void Display();
    void Reverse();
    void Set(size_t, T);

    size_t length();

    T PopFront();
    T PopBack();

    T RemoveAt(size_t);
    T Get(T);
};

template <class T>
LinkedList<T>::LinkedList() {
    head = tail = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    if (head) {
        auto *temp = head;
        head = nullptr;

        while (temp) {
            auto *to_delete = temp;
            temp = temp->next;

            delete to_delete;
            to_delete = nullptr;
        }

        temp = nullptr;
    }
}

template <class T>
bool LinkedList<T>::Empty() {
    return not size;
}

template <class T>
void LinkedList<T>::Display() {
    PrintLinkedList(head);
}

template <class T>
void LinkedList<T>::PushFront(T data) {
    Node<T> *new_node = new Node{data};

    if (Empty())
        head = tail = new_node;

    else {
        new_node->next = head;
        head = new_node;
    }

    size++;
}

template <class T>
size_t LinkedList<T>::length() {
    return size;
}

template <class T>
void LinkedList<T>::PushBack(T data) {
    Node<T> *new_node = new Node{data};

    if (Empty())
        head = tail = new_node;

    else {
        tail->next = new_node;
        tail = new_node;
    }

    size++;
}

template <class T>
void LinkedList<T>::InsertAt(size_t position, T data) {
    if (position == size + 1)
        return PushBack(data);

    if (position == 1)
        return PushFront(data);

    HandlePosition(position);

    auto *temp = GetNodeAt(position - 1);

    Node<T> *new_node = new Node{data};

    new_node->next = temp->next;
    temp->next = new_node;

    size++;
}

template <class T>
T LinkedList<T>::PopFront() {
    HandleEmptyLinkedList();

    T deleted;

    if (size == 1) {
        deleted = head->data;

        delete head;

        head = tail = nullptr;

    } else {
        auto *temp = head;

        deleted = temp->data;
        head = temp->next;

        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    size--;

    return deleted;
}

template <class T>
Node<T> *LinkedList<T>::GetNodeAt(size_t position) {
    HandleEmptyLinkedList();
    HandlePosition(position);

    auto *temp = head;

    for (size_t i = 2; i <= position; i++) {
        temp = temp->next;
    }

    return temp;
}

template <class T>
T LinkedList<T>::PopBack() {
    HandleEmptyLinkedList();

    if (size == 1)
        return PopFront();

    auto *previous_node = GetNodeAt(size - 1);

    auto deleted = tail->data;

    delete tail;
    tail = nullptr;

    previous_node->next = nullptr;

    tail = previous_node;

    size--;

    return deleted;
}

template <class T>
T LinkedList<T>::RemoveAt(size_t position) {
    HandleEmptyLinkedList();
    HandlePosition(position);

    if (position == 1)
        return PopFront();

    if (position == size)
        return PopBack();

    auto *previous_node = GetNodeAt(position - 1);
    auto *node_to_delete = previous_node->next;

    auto deleted = node_to_delete->data;

    previous_node->next = previous_node->next->next;

    node_to_delete->next = nullptr;
    delete node_to_delete;
    node_to_delete = nullptr;

    size--;

    return deleted;
}

template <class T>
void LinkedList<T>::HandlePosition(size_t position) {
    if ((position < 1 or position > size))
        throw Exception(error.kInvalidPosition);
}

template <class T>
void LinkedList<T>::HandleEmptyLinkedList() {
    if (Empty())
        throw Exception(error.kEmpty);
}

template <class T>
int LinkedList<T>::Find(T item) {
    HandleEmptyLinkedList();

    auto *temp = head;
    size_t position = 1;
    while (temp) {
        if (temp->data == item)
            return position;

        temp = temp->next;
        position++;
    }

    throw Exception(error.kItemDoesNotExist);
}

template <class T>
T LinkedList<T>::Get(T item) {
    HandleEmptyLinkedList();

    int node_position = Find(item);

    if (node_position < 1)
        throw Exception(error.kItemDoesNotExist);

    return GetNodeAt(node_position)->data;
}

template <class T>
void LinkedList<T>::Reverse() {
    HandleEmptyLinkedList();

    tail = head;
    head = Reverse_();
}

template <class T>
Node<T> *LinkedList<T>::Reverse_() {
    HandleEmptyLinkedList();

    Node<T> *previous_node = nullptr;

    while (head) {
        auto *next_node = head->next;

        head->next = previous_node;
        previous_node = head;
        head = next_node;
    }

    return previous_node;
}

template <class T>
Node<T> *LinkedList<T>::ReverseRecursively_(Node<T> *head, Node<T> *previous_node) {
    HandleEmptyLinkedList();

    if (head == nullptr)
        return previous_node;

    auto *next_node = head->next;
    head->next = previous_node;

    return ReverseRecursively_(next_node, head);
}

template <class T>
void LinkedList<T>::Set(size_t position, T item) {
    HandleEmptyLinkedList();
    HandlePosition(position);

    auto *node = GetNodeAt(position);
    node->data = item;
}