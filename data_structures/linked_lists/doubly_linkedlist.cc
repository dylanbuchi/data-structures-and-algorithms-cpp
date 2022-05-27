#include "linkedlist.cc"

using std::cout;

template <class T>
class DoublyLinkedList : public LinkedList<T> {
public:
    void Display();
    void PushBack(T);
    void PushFront(T);
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
