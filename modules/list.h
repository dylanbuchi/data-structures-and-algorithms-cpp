#pragma once

template <class T>
class IList {
public:
    virtual ~IList() {}

    virtual int Find(T) = 0;

    virtual bool Empty() = 0;

    virtual void InsertAt(size_t, T) = 0;

    virtual void PushFront(T) = 0;
    virtual void PushBack(T) = 0;

    virtual void Display() = 0;

    virtual void Set(size_t, T) = 0;

    virtual size_t length() = 0;

    virtual T PopFront() = 0;
    virtual T PopBack() = 0;

    virtual T RemoveAt(size_t) = 0;

    virtual T Get(T) = 0;
};