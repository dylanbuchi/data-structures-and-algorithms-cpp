#include "list.h"

template <class T>
class StackArray : public IList<T> {
private:
    T* stack;
    int top;

protected:
    size_t size;

public:
};