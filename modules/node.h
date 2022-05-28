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
        next = prev = nullptr;
    };
};