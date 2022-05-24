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
    const string kInvalidPosition_ = "Invalid position";

    Node<T> *head_, *tail_;
    size_t length_;

public:
    LinkedList();
    ~LinkedList();

    bool Empty();

    void PushFront(T);
    void PushBack(T);
    void InsertAt(size_t, T);

    void Display();

    size_t length();

    T PopFront();
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

template <class T>
void LinkedList<T>::PushBack(T data) {
    Node<T> *new_node = new Node{data};

    if (Empty())
        head_ = tail_ = new_node;

    else {
        tail_->next = new_node;
        tail_ = new_node;
    }

    length_++;
}

template <class T>
void LinkedList<T>::InsertAt(size_t position, T data) {
    if (position == length_ + 1)
        return PushBack(data);

    if (position == 1)
        return PushFront(data);

    if ((position < 1 or position > length_))
        throw Exception(kInvalidPosition_);

    Node<T> *temp = head_;

    for (size_t i = 2; i < position; i++)
        temp = temp->next;

    Node<T> *new_node = new Node{data};

    new_node->next = temp->next;
    temp->next = new_node;

    length_++;
}

template <class T>
T LinkedList<T>::PopFront() {
    T deleted;

    if (Empty())
        throw Exception(kEmptyLinkedListString_);

    if (length_ == 1) {
        deleted = head_->data;

        delete head_;

        head_ = tail_ = nullptr;

    } else {
        auto *temp = head_;

        deleted = temp->data;
        head_ = temp->next;

        temp->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    length_--;

    return deleted;
}