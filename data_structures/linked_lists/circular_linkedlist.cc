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

    bool Empty();
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
    PrintLinkedList(head_);
}

template <class T>
bool CircularLinkedList<T>::Empty() {
    return not length_;
}
