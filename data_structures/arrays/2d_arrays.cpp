#include "print.hh"
using std::cout;

void initialize_2d_array(int** array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = new int[size];
    }
}

void fill_2d_array(int** array, size_t row_size, size_t col_size, int fill) {
    for (size_t row = 0; row < row_size; row++) {
        for (size_t col = 0; col < col_size; col++) {
            array[row][col] = fill;
        }
    }
}

void free_2d_array_memory(int** array, size_t row_size) {
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

    initialize_2d_array(array_2, size);

    // create a 2d array in the heap memory using double pointers (all in heap)
    int** array_3 = new int*[size];

    initialize_2d_array(array_3, size);

    fill_2d_array(array_2, size, size, 3);
    fill_2d_array(array_3, size, size, -1);

    print_2d_array(array_2, size, size);
    print();
    print_2d_array(array_3, size, size);

    free_2d_array_memory(array_2, size);
    free_2d_array_memory(array_3, size);

    delete[] array_3;
    array_3 = nullptr;
}
