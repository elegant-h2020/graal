#include <iostream>

int* compute(int(*f)(int), const int *input, const int size) {
    int* output = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        output[i] = f(input[i]);
    }
    return output; 
}

int main(int argc, char** argv) {

    std::cout << "Hello\n";

    auto f = [=](int i) {
        std::cout << "Hello lambda\n";
        return i;
    };

    auto result = f(3);


    // Example: vector function
    const int size = 10;
    int* input = (int *)malloc(size * sizeof(int));
    int* output = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        input[i] = i;
    }

    auto vectorFunction = [=](int *input, int *output, const int size) {
        for (int i = 0; i < size; i++) {
            output[i] = input[i] * 2;
        }
        return 0;
    };

    vectorFunction(input, output, size);

    for (int i = 0; i < size; i++) {
        std::cout << "Result: #" << i << " = " << output[i] << "\n";
    }

    // Example of a map operator in C++
    auto mapFunction = [](const int value) {
        return value * 10;
    };

    output = compute(mapFunction, input, size);

    for (int i = 0; i < size; i++) {
        std::cout << "Result: #" << i << " = " << output[i] << "\n";
    }


}