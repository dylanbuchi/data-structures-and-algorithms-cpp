#pragma once

#include <stddef.h>

template <class T>
class IList {
public:
    virtual ~IList() {}

    virtual bool Empty() = 0;

    virtual void Push() = 0;
    virtual void Display() = 0;

    virtual T Pop() = 0;
    virtual T Peek() = 0;
};