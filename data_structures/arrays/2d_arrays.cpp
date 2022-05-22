#include "print.hh"

using std::cout;

void initialize2dArray(int** array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = new int[size];
    }
}

void fill2dArray(int** array, size_t row_size, size_t col_size, int fill) {
    for (size_t row = 0; row < row_size; row++) {
        for (size_t col = 0; col < col_size; col++) {
            array[row][col] = fill;
        }
    }
}

void free2dArrayMemory(int** array, size_t row_size) {
    for (size_t row = 0; row < row_size; row++) {
        delete array[row];
        array[row] = nullptr;
    }
}

int main() {
    // create a 2d array in the stack memory
    char array[2][2] = {{'A', 'B'}, {'C', 'D'}};

    size_t array_size = 2;

    for (size_t row = 0; row < array_size; row++) {
        cout << "[";
        for (size_t col = 0; col < array_size; col++)
            cout
                << array[row][col] << (col < array_size - 1 ? ", " : "");
        print("]");
    }

    print();

    // create a 2d array in the heap memory, (only columns in heap)
    int* array_2[3];

    size_t size = 3;

    initialize2dArray(array_2, size);

    // create a 2d array in the heap memory using double pointers (all in heap)
    int** array_3 = new int*[size];

    initialize2dArray(array_3, size);

    fill2dArray(array_2, size, size, 3);
    fill2dArray(array_3, size, size, -1);

    print2dArray(array_2, size, size);
    print();
    print2dArray(array_3, size, size);

    free2dArrayMemory(array_2, size);
    free2dArrayMemory(array_3, size);

    delete[] array_3;
    array_3 = nullptr;
}
