#include "linkedlist.cc"

using std::cout;

template <class T>
class DoublyLinkedList : public LinkedList<T> {
public:
    void Display();
    void PushBack(T);
    void PushFront(T);

    T PopFront();
    T PopBack();
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