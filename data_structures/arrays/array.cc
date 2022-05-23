#include "exception.h"
#include "print.h"

template <class T>
class Array {
private:
    const std::string kIndexOutOfBoundsString{"Index out of bounds"};
    const std::string kEmptyArrayString{"The array is empty"};

    const size_t kResizeValue{2};

    T* array_;

    size_t length_{0};
    size_t capacity_{0};

    void Resize_(T*& array);

    int LinearSearch_(T target);

    int BinarySearch_(T target);
    int RecursiveBinarySearch_(T target, size_t start, size_t end);

public:
    Array(size_t capacity);
    Array() : Array(10){};
    ~Array();

    void PushBack(T item);
    void InsertAt(size_t index, T item);

    void Display();
    void Set(size_t index, T item);

    bool Find(T target);
    bool Full();
    bool Empty();

    T Search(T item);
    T Get(size_t index);

    T RemoveAt(size_t index);
    T PopBack();

    size_t length();
    size_t capacity();
    size_t IndexOf(T item);
};

template <class T>
Array<T>::Array(size_t capacity) {
    if ((int)capacity < 1)
        throw Exception("Can't create an array with less than one item");

    array_ = new T[capacity];
    capacity_ = capacity;
}

template <class T>
Array<T>::~Array() {
    delete[] array_;
}

template <class T>
size_t Array<T>::length() {
    return length_;
}

template <class T>
void Array<T>::InsertAt(size_t index, T item) {
    if ((int)index < 0 or index > length_)
        throw Exception(kIndexOutOfBoundsString);

    if (index == length_) {
        return PushBack(item);
    }

    if (Full())
        Resize_(array_);

    for (size_t i = length(); i > index; i--)
        array_[i] = array_[i - 1];

    array_[index] = item;

    length_++;
}

template <class T>
bool Array<T>::Full() {
    return length_ == capacity_;
}

template <class T>
bool Array<T>::Empty() {
    return not length_;
}

template <class T>
void Array<T>::Display() {
    printArray(array_, length_);
}

template <class T>
void Array<T>::PushBack(T item) {
    if (Full())
        Resize_(array_);

    array_[length_] = item;
    length_++;
}

template <class T>
void Array<T>::Resize_(T*& array) {
    size_t new_capacity = capacity_ * kResizeValue;

    T* new_array = new T[new_capacity];

    for (size_t i = 0; i < length_; i++)
        new_array[i] = array_[i];

    delete[] array;
    array = nullptr;

    array = new_array;
    capacity_ = new_capacity;
}

template <class T>
T Array<T>::RemoveAt(size_t index) {
    if (Empty())
        throw Exception(kEmptyArrayString);

    if (index < 0 or index >= length_)
        throw Exception(kIndexOutOfBoundsString);

    if (index == length_ - 1)
        return PopBack();

    T deleted = array_[index];

    for (size_t i = index; i < length_; i++) {
        array_[i] = array_[i + 1];
    }

    length_--;
    return deleted;
}

template <class T>
T Array<T>::PopBack() {
    if (Empty())
        throw Exception(kEmptyArrayString);

    length_--;
    T deleted = array_[length_];
    return deleted;
}

template <class T>
int Array<T>::LinearSearch_(T target) {
    for (size_t i = 0; i < length_; i++) {
        if (array_[i] == target)
            return i;
    }

    return -1;
}

template <class T>
int Array<T>::BinarySearch_(T target) {
    size_t start, end;

    start = 0;
    end = length_ - 1;

    while (start <= end) {
        size_t mid = start + (end - start) / 2;

        T mid_item = array_[mid];

        if (mid_item == target)
            return mid;

        if (mid_item > target)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

template <class T>
int Array<T>::RecursiveBinarySearch_(T target, size_t start, size_t end) {
    if (start > end)
        return -1;

    size_t mid = start + (end - start) / 2;

    T mid_item = array_[mid];

    if (mid_item == target)
        return mid;

    if (mid_item > target)
        return RecursiveBinarySearch_(target, start, mid - 1);
    else
        return RecursiveBinarySearch_(target, mid + 1, end);
}

template <class T>
bool Array<T>::Find(T target) {
    return BinarySearch_(target) != -1;
}

template <class T>
size_t Array<T>::IndexOf(T item) {
    int index = BinarySearch_(item);

    if (index == -1)
        throw Exception("Item does not exist!");

    return index;
}

template <class T>
size_t Array<T>::capacity() {
    return capacity_;
}

int main() {
    return 0;
}
