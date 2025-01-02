#include <iostream>
#include <string>


int main(int agrc, char **argv) {
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

    //Input/Output
    int age1;
    std::string name;
    std::cout << "Please type name and age: " << std::endl;
    // std::cin >> name; // Inplicit new line
    // std::cin >> age1;
    std::cin >> name >> age1; // Implicit same line input
    std::cout << "Hello " << name << ", you are " << age1 << " years old!" << std::endl;

    // clearing the input buffer so that it get rid of the "\n" symbol from previous cin
    // calls. If not cleared, getline and the next cin will not work because they only
    // see the /n symbol left over from the previous /n. 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Data Input with spaces
    std::string full_name_with_space;
    int age3;
    std::cout << "Please enter your fullname: " << std::endl;
    std::getline(std::cin, full_name_with_space);
    std::cin >> age3;
    std::cout << "Hello " << full_name_with_space << ". You are " 
              << age3 << " years old!" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Array of Characters (aka String) and auto keyword
    char characterArray[5] = {'H', 'e', 'l', 'l', 'o'}; 
    for (auto character : characterArray) {
        std::cout << character;
    }
    std::cout << std::endl;
    // The line below is a bug, sometime it works, sometime it doesn't
    std::cout << "Printing characterArray without termnial symbol at the end: " 
              << characterArray << std::endl;

    // Pointers, References and Smart Pointers
    // Declaring a pointer (aka reference)
    int int_value {45}; // List initilization (type of direct initilization) 
    // => Prevent narrowing conversions 
    // It will through an error at compile time if you do narrowing conversions
    
    double double_value(33.65); // Direct initialization => Most efficient

    int copy_int_value = 22; // Copy Initilization => Allows impliccit conversion

    int& reference_to_int_value_1{int_value};
    int& reference_to_int_value_2 = int_value;
    double& reference_to_float_value_1{double_value};
    double& reference_to_double_value_2 = double_value;

    std::cout << "int_value: " << int_value << std::endl; 
    std::cout << "double_value: " << double_value << std::endl; 
    std::cout << "reference to int_value_1: " << reference_to_int_value_1 << std::endl; 
    std::cout << "reference to int_value_2: " << reference_to_int_value_2 << std::endl; 
    std::cout << "double_value: " << double_value << std::endl; 
    std::cout << "reference to double_value_1: " << reference_to_float_value_1 << std::endl; 
    std::cout << "reference to double_value_2: " << reference_to_double_value_2 << std::endl; 

    // Pointer
    char *pointer_to_char {nullptr};
    char lmao = 'F';
    pointer_to_char = &lmao;
    std::cout << "Pointer value: " << * pointer_to_char << std::endl;

    // Pointer to char can do sth special
    // char * pointer_message {"Hello World!"}; 
    std::string pointer_message {"Hello World!"}; 
    // char * pointer_message {"Hello World!"}; 
    // Some compiler may refuse to compile this code
    std::cout << "Char pointer value: " << pointer_message << std::endl;
    // However, an array of char would still work
    char array_of_char[] {"Hello array of Chars!"};
    std::cout << "Char array value: " << array_of_char << std::endl;

    // Dynamic Memory Allocation
    int * pointer_to_num_1 {nullptr};
    int num_1 = 10;
    pointer_to_num_1 = &num_1;
    // WARNING: DO NOT WRITE INTO UNINITIAlIZED POINTER
    // DONT: int p_num; *p_num = 55;
    // Always initialized pointers before using them

    // Alocation with new and delete keyword
    int * p_number4{nullptr};
    p_number4 = new int; // This is now stored in the HEAP
    std::cout << "Int stored on HEAP: " << p_number4 << std::endl;
    // Once done, always delete the variable and point the pointer to null pointer
    delete p_number4;
    p_number4 = nullptr; 
    // Pointer in C++ works the same as C, except for vitual table in classes in C++

    // Classes
    // Members and functions of classes are private by default
    // We add the keyword public to make it public
    class Cylinder {
        const double PI = 3.14;
        public:
            double base_radius {1.0};
            double height {1.0};
        public:
            double volume() {
                return PI * base_radius * base_radius * height;
            }
    };

    Cylinder cylinder1;
    std::cout << "Volume is " << cylinder1.volume() << std::endl;

    // Virtual function are use to do runtime polymorphism
    // Example of non virtual function:
    class Parent {
        public:
            void display() {
                std::cout << "PARENT DISPLAY" << std::endl;
            };
    }; 
    class Child {
        public:
            void display () override {
                std::cout << "CHILD DISPLAY" << std::endl;
            };
    };
    Parents* pp = new Child()
    pp->display() // We are calling the parents' display() method here
    // This is because pp is defined to a a pointer to Parents*
    // The example below will use virtual function
        class VParent {
        public:
            virtual void display() {
                std::cout << "PARENT DISPLAY" << std::endl;
            };
    }; 
    class VChild {
        public:
            void display () override {
                std::cout << "CHILD DISPLAY" << std::endl;
            };
    };
    Parents* pp = new Child();
    pp->display(); // This will result in CHILD DISPLAY
    // This is runtime polymorphism
    // Underneath:
    // Classes and Objects with virtual functions
    // will have a vtable pointer, this points
    // to a of virtual functions of that class/object
    // If a derived class override a virtual function,
    // the base class virtual function will change that
    // entry to match the new overriding function.

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