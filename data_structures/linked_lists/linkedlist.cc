#include "exception.h"
#include "list.h"
#include "node.h"
#include "print.h"

using std::string;

template <class T>
class LinkedList : public IList<T> {
private:
    size_t length_;

    Node<T> *head_, *tail_;

    Node<T> *GetNodeAt_(size_t);

    Node<T> *ReverseRecursively_(Node<T> *, Node<T> *);
    Node<T> *Reverse_();

    Exception error_;

    void HandlePosition_(size_t);
    void HandleEmptyLinkedList_();

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

    HandlePosition_(position);

    auto *temp = GetNodeAt_(position - 1);

    Node<T> *new_node = new Node{data};

    new_node->next = temp->next;
    temp->next = new_node;

    length_++;
}

template <class T>
T LinkedList<T>::PopFront() {
    HandleEmptyLinkedList_();

    T deleted;

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

template <class T>
Node<T> *LinkedList<T>::GetNodeAt_(size_t position) {
    HandleEmptyLinkedList_();
    HandlePosition_(position);

    auto *temp = head_;

    for (size_t i = 2; i <= position; i++) {
        temp = temp->next;
    }

    return temp;
}

template <class T>
T LinkedList<T>::PopBack() {
    HandleEmptyLinkedList_();

    if (length_ == 1)
        return PopFront();

    auto *previous_node = GetNodeAt_(length_ - 1);

    auto deleted = tail_->data;

    delete tail_;
    tail_ = nullptr;

    previous_node->next = nullptr;

    tail_ = previous_node;

    length_--;

    return deleted;
}

template <class T>
T LinkedList<T>::RemoveAt(size_t position) {
    HandleEmptyLinkedList_();
    HandlePosition_(position);

    if (position == 1)
        return PopFront();

    if (position == length_)
        return PopBack();

    auto *previous_node = GetNodeAt_(position - 1);
    auto *node_to_delete = previous_node->next;

    auto deleted = node_to_delete->data;

    previous_node->next = previous_node->next->next;

    node_to_delete->next = nullptr;
    delete node_to_delete;
    node_to_delete = nullptr;

    length_--;

    return deleted;
}

template <class T>
void LinkedList<T>::HandlePosition_(size_t position) {
    if ((position < 1 or position > length_))
        throw Exception(error_.kInvalidPosition);
}

template <class T>
void LinkedList<T>::HandleEmptyLinkedList_() {
    if (Empty())
        throw Exception(error_.kEmpty);
}

template <class T>
int LinkedList<T>::Find(T item) {
    HandleEmptyLinkedList_();

    auto *temp = head_;
    size_t position = 1;
    while (temp) {
        if (temp->data == item)
            return position;

        temp = temp->next;
        position++;
    }

    throw Exception(error_.kItemDoesNotExist);
}

template <class T>
T LinkedList<T>::Get(T item) {
    HandleEmptyLinkedList_();

    int node_position = Find(item);

    if (node_position < 1)
        throw Exception(error_.kItemDoesNotExist);

    return GetNodeAt_(node_position)->data;
}

template <class T>
void LinkedList<T>::Reverse() {
    HandleEmptyLinkedList_();

    tail_ = head_;
    head_ = Reverse_();
}

template <class T>
Node<T> *LinkedList<T>::Reverse_() {
    HandleEmptyLinkedList_();

    Node<T> *previous_node = nullptr;

    while (head_) {
        auto *next_node = head_->next;

        head_->next = previous_node;
        previous_node = head_;
        head_ = next_node;
    }

    return previous_node;
}

template <class T>
Node<T> *LinkedList<T>::ReverseRecursively_(Node<T> *head, Node<T> *previous_node) {
    HandleEmptyLinkedList_();

    if (head == nullptr)
        return previous_node;

    auto *next_node = head->next;
    head->next = previous_node;

    return ReverseRecursively_(next_node, head);
}

template <class T>
void LinkedList<T>::Set(size_t position, T item) {
    HandleEmptyLinkedList_();
    HandlePosition_(position);

    auto *node = GetNodeAt_(position);
    node->data = item;
}