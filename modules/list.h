#pragma once

#include <stddef.h>

template <class T>
class IList {
public:
    virtual ~IList() {}

    virtual bool Empty() = 0;
    virtual bool Full() = 0;

    virtual void Push(T) = 0;
    virtual void Display() = 0;

    virtual size_t length() = 0;

    virtual T Pop() = 0;
    virtual T Peek() = 0;
};