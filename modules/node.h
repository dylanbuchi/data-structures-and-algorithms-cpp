#pragma once

template <class T>
class Node {
public:
    T data;
    Node<T> *next, *prev;

    Node(T data) {
        this->data = data;
        next = prev = nullptr;
    }

    ~Node() {
        auto *temp = next;
        delete next;

        if (temp != prev) {
            delete prev;
            prev = nullptr;
        }

        temp = next = nullptr;
    };
};