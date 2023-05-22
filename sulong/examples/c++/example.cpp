#include <iostream>

int* tornadoMap(int(*f)(int, int), const int *input) {
    int* output = (int *)malloc(81000 * sizeof(int));
    for (int i = 0; i < 81000; i++) {
        output[i] = f(input[i], input[i]);
    }
    return output;
}

int main(int argc, char** argv) {

    // Example: vector function
    const int size = 81000;
    int *input = (int *) malloc(size * sizeof(int));
    int *output = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        input[i] = 2;
    }

    // Example of a map operator in C++
    auto mapFunction = [](const int value, const int value2) {
        return value * 77 + value2;
    };

    for (int i = 0; i < 10000; i++) {
//        output = tornadoMap(mapFunction, input, size);
        output = tornadoMap(mapFunction, input);
    }

    std::cout << "Result: #" << 0 << " = " << output[0] << "\n";
}