#include "exception.h"
#include "list.h"
#include "node.h"
#include "print.h"

using std::cout;

template <class T>
class CircularLinkedList : public IList<T> {
private:
    Exception error_;

    Node<T> *head_, *tail_;

    size_t length_;

public:
    CircularLinkedList();
    ~CircularLinkedList();

    void Display();

    bool Empty();

    size_t length();

    void PushBack(T);
    void PushFront(T);
};

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
    head_ = tail_ = nullptr;
    length_ = 0;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
    if (head_) {
        auto *temp = head_;
        head_ = nullptr;

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
void CircularLinkedList<T>::Display() {
    auto *temp = head_;

    do {
        cout << temp->data << " --> ";
        temp = temp->next;

    } while (temp != head_);

    Print();
}

template <class T>
bool CircularLinkedList<T>::Empty() {
    return not length_;
}

template <class T>
size_t CircularLinkedList<T>::length() {
    return length_;
}

template <class T>
void CircularLinkedList<T>::PushBack(T data) {
    Node<T> *new_node = new Node{data};

    if (Empty()) {
        new_node->next = new_node;
        head_ = tail_ = new_node;
    } else {
        tail_->next = new_node;
        tail_ = new_node;
        tail_->next = head_;
    }

    length_++;
}

template <class T>
void CircularLinkedList<T>::PushFront(T data) {
    auto *new_node = new Node{data};

    if (Empty()) {
        new_node->next = new_node;
        head_ = tail_ = new_node;
    } else {
        new_node->next = head_;
        head_ = new_node;
        tail_->next = head_;
    }

    length_++;
}
