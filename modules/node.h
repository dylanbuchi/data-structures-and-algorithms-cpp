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