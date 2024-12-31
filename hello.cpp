#include <iostream>



int main() {
    int file_size = 100, counter = 0;
    std::cout << "\n";
    std::cout << "Old file size: ";
    std::cout << file_size << std::endl;
    std::cout << "Switching variables using bitwise" << std::endl;
    file_size = file_size ^ counter;
    counter = file_size ^ counter;
    file_size = file_size ^ counter; 
    std::cout << "New file size: ";
    std::cout << file_size << std::endl;

    const double pi = 3.14;

    // integer
    // integer on integer action can only birth int
    // and not float
    int x = 10, y = 3, z = x + y;
    std::cout << "Old z: " << z << "\n";

    // double
    double z_double = static_cast<double>(x) / y;
    std::cout << "New z as double: " << z_double << "\n";

    // Array
    int numbers[5] = {1,2,3,4,5};
    std::cout << "Second element in array numbers: " 
              << numbers[1] << "\n"; 
    // vector, aka dynamic array
    // vector comes with automatic memory management
    // When a vector get copied, its content is copied
    // When an array is copied, its pointer is copied
    std::vector<int> dynamicNumbers = {1,2,3,4,5};

    // For loops
    for (int i = 0; i < 10; ++i) {
        std::cout << "Iteration: " << i << "\n";
        std::cout << ++i << "\n";  
    }
    // For loops, but more modern, aka iterators
    for (int num : numbers) {
        std::cout << "Iterator with array at: " << num << "\n";
    }
    for (int num : dynamicNumbers) {
        std::cout << "Iterator with std::vector<int> array at: " << num << "\n";
    }

    // Conditional
    int age = 19;
    if (age < 18) {
        std::cout << "Children/Teenager" << "\n";
    } else {
        std::cout << "Young Adult/Adult" << "\n";
    }

    int counterForWhileLoop = 10;
    while (counterForWhileLoop > 0) {
        std::cout << "In while loop: " 
                  << counterForWhileLoop << "\n";
        counterForWhileLoop--;
    }

    // - Still need to talk about Pointer
    // - Classes (Polymorphism, Overloading, Scope)
    // - Stack vs Heap
    // - In depth Heap, memory allocator
    // - System Calls (SYSCALL for CSC 456)
    // - Memory allocation, data copy behavirals of  
    // data structures. Also about the lifecycle of 
    // data structures as well. 
    // - Smart pointers
    // - Standard Library
    // - Reading/write from/to console
    // - Reading from files 
    // - Writing to files
    // - Narrowing
    // - Generating Random Numbers
    // - Parallelism 
    
    return 0;
}