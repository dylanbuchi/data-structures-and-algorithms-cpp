#include "exception.h"
#include "print.h"

using std::string;

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        delete next;
        next = nullptr;
    };
};

template <class T>
class LinkedList {
private:
    const string kEmptyLinkedListString_ = "Empty linked list";

    Node<T> *head_, *tail_;
    size_t length_;

public:
    LinkedList();
    ~LinkedList();

    bool Empty();

    void PushFront(T);
    void Display();

    size_t length();
};

template <class T>
LinkedList<T>::LinkedList() {
    head_ = tail_ = nullptr;
    length_ = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    delete head_;
    delete tail_;

    head_ = tail_ = nullptr;
}

template <class T>
bool LinkedList<T>::Empty() {
    return not length_;
}

template <class T>
void LinkedList<T>::Display() {
    if (Empty())
        throw Exception(kEmptyLinkedListString_);

    PrintLinkedList(head_);
}

template <class T>
void LinkedList<T>::PushFront(T data) {
    Node<T> *new_node = new Node{data};

    if (Empty())
        head_ = tail_ = new_node;

    else {
        new_node->next = head_;
        head_ = new_node;
    }

    length_++;
}

template <class T>
size_t LinkedList<T>::length() {
    return length_;
}
