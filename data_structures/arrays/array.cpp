#include "print.hh"

using std::cin;

template <typename T>
class Array {
private:
    T* _array;
    size_t _length;
    size_t _size;

    bool _full();
    void _resize();

public:
    Array<T>() {
        _size = 10;
        _array = new T[_size];
        _length = 0;
    }

    Array<T>(size_t size) {
        this->_size = size;
        _array = new T[size];
        _length = 0;
    }

    ~Array<T>() {
        delete[] _array;
    }

    int get_size();
    int get_length();

    bool empty();
    void display();

    void append(T value);
    void insert_at(size_t index, T value);

    T remove_at(size_t index);
    T pop();

    int search(T object);
};

template <class T>
void Array<T>::_resize() {
    size_t new_size = _size * 2;

    T* new_array = new T[new_size];

    for (size_t i = 0; i < _length; i++) {
        new_array[i] = _array[i];
    }

    delete[] _array;
    _array = new_array;
    _size = new_size;
}

template <class T>
bool Array<T>::_full() {
    return _size == _length;
}

template <class T>
int Array<T>::get_size() {
    return _size;
}

template <class T>
int Array<T>::get_length() {
    return _length;
}

template <class T>
bool Array<T>::empty() {
    return not _length;
}

template <class T>
void Array<T>::display() {
    if (empty())
        return;

    print();
    cout << "[";
    for (size_t i = 0; i < _length; i++)
        cout
            << _array[i] << (i < _length - 1 ? ", " : "");

    print("]");
}

template <class T>
void Array<T>::append(T value) {
    if (_full())
        _resize();

    _array[_length++] = value;
}

template <class T>
void Array<T>::insert_at(size_t index, T value) {
    if (not index and empty()) {
        append(value);
        return;
    }

    if (index < 0 or index >= _length)
        return;

    if (_full())
        _resize();

    _length++;

    for (auto i = _length; i > index; i--) {
        _array[i] = _array[i - 1];
    }
    _array[index] = value;
}

template <class T>
T Array<T>::remove_at(size_t index) {
    if (empty() or index < 0 or index >= _length)
        return NULL;

    if (index == _length - 1) {
        return pop();
    }

    T deleted = _array[index];

    for (size_t i = index; i < _length - 1; i++) {
        _array[i] = _array[i + 1];
    }

    _length--;

    return deleted;
}

template <class T>
T Array<T>::pop() {
    if (empty())
        return NULL;

    size_t last_index = _length - 1;

    T deleted = _array[last_index];

    _array[last_index] = NULL;

    _length--;
    return deleted;
}

template <class T>
int Array<T>::search(T object) {
    if (empty())
        return -1;

    for (size_t i = 0; i < _length; i++)
        if (_array[i] == object)
            return i;

    return -1;
}

int main() {
    int size;

    print("Enter size of the Array: ");
    cin >> size;

    Array<int> array(size);

    int choice;
    size_t index;
    int value;

    while (true) {
        print("1 - Insert");
        print("2 - Append");
        print("3 - Pop");
        print("4 - Remove");
        print("5 - Exit");

        cin >> choice;

        switch (choice) {
        case 1:
            print("Insert element at index: ");

            cin >> index >> value;

            array.insert_at(index, value);
            array.display();

            break;
        case 2:
            print("Append an element: ");

            cin >> value;

            array.append(value);
            array.display();

            break;
        case 3:
            print("Pop last element: ");

            array.pop();
            array.display();

            break;
        case 4:
            print("Remove an element at index: ");

            cin >> index;

            array.remove_at(index);
            array.display();

            break;

        default:
            print("Exit");
            return 0;
        }

        if (array.empty()) {
            print("Exit");
            return 0;
        }
    }
}
