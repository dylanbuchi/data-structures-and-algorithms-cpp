#include "exception.h"
#include "list.h"
#include "node.h"
#include "print.h"

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
};

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
    head_ = tail_ = nullptr;
    length_ = 0;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
    delete head_;
    delete tail_;

    head_ = tail_ = nullptr;
}

template <class T>
void CircularLinkedList<T>::Display() {
    PrintLinkedList(head_);
}