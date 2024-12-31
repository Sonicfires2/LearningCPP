# C++ Learning Project

## Overview
This project is a learning exercise in C++ programming. It explores key concepts in the language, including data types, memory management, loops, conditionals, and advanced topics like pointers and smart pointers. The goal is to understand how to write clean, efficient C++ code while learning about common practices and pitfalls.

---

## Basic Key Concepts

### 1. **Program Behavior**
- **`return 0`**: Indicates that the program ran successfully.
- Any other return value signifies an error.

---

### 2. **Console Output Peculiarities**
- Printing strings using `std::cout` may append a `%` character in certain terminal environments.
- **Mitigation**:
  - Add `\n` at the end of your output.
  - Use `std::endl`, but note that it flushes the buffer.

---

### 3. **Defining and Initializing Variables**
- Syntax: `[data type] [variable name] = [value];`
  ```cpp
  int file_size = 100;
  ```
- Multiple variables of the same type can be defined on one line:
  ```cpp
  int x = 10, y = 3;
  ```
- **Constants**:
  ```cpp
  const double pi = 3.14;
  ```

---

### 4. **Common Data Structures**

#### **Primitive Types**
```cpp
int number = 10;
float pi = 3.14f;
const float const_pi = 3.14f;
```

#### **Namespaces**
```cpp
namespace movement {
    void up() { /* ... */ }
    void down() { /* ... */ }
    void left() { /* ... */ }
    void right() { /* ... */ }
}
```

#### **Arrays**
```cpp
int numbers[5] = {1, 2, 3, 4, 5};
std::cout << "Second element: " << numbers[1] << std::endl;
```

#### **Vectors (Dynamic Arrays)**
```cpp
#include <vector>
std::vector<int> nums = {1, 2, 3};
nums.push_back(4); // {1, 2, 3, 4}
nums.pop_back();   // {1, 2, 3}
nums.insert(nums.begin() + 1, 10); // {1, 10, 2, 3}
nums.erase(nums.begin() + 2);      // {1, 10, 3}
```

---

### 5. **Loops**
#### **For Loops**
```cpp
for (int i = 0; i < 10; ++i) {
    std::cout << "Iteration: " << i << std::endl;
}
```

#### **Range-Based For Loops**
```cpp
for (int num : numbers) {
    std::cout << "Value: " << num << std::endl;
}
```

#### **While Loops**
```cpp
int counter = 10;
while (counter > 0) {
    std::cout << counter-- << std::endl;
}
```

---

### 6. **Conditionals**
```cpp
int age = 19;
if (age < 18) {
    std::cout << "Minor" << std::endl;
} else {
    std::cout << "Adult" << std::endl;
}
```

---

### 7. **Switching Variables Using Bitwise Operators**
```cpp
int a = 10, b = 20;
a = a ^ b;
b = a ^ b;
a = a ^ b;
```
---

### 8. **Naming Conventions**
Popular styles include:
- `file_size` (Snake Case)
- `FileSize` (Pascal Case)
- `fileSize` (Camel Case)
- `iFileSize` (Hungarian Notation)

---

## Notes
- `\n` vs `std::endl`:
  - `\n` adds a newline without flushing the buffer.
  - `std::endl` adds a newline **and** flushes the buffer.
- Pre-increment (`++n`) in a loop increments the variable before execution of the loop body.

---

## Other Key Concepts

### 1. **Pointers**
Pointers are variables that store memory addresses. They allow direct memory access and manipulation.
```cpp
int x = 10;
int* ptr = &x; // ptr stores the address of x
std::cout << "Value: " << *ptr << std::endl; // Dereference pointer
```

### 2. **Classes** (Polymorphism, Overloading, Scoping)
Classes define objects with properties and methods.
```cpp
class MyClass {
public:
    void greet() { std::cout << "Hello!" << std::endl; }
};

MyClass obj;
obj.greet();
```
Polymorphism allows different behaviors for the same function call.
Function overloading allows multiple functions with the same name but different parameters.

### 3. **Stack vs Heap**
- **Stack**: Memory for local variables. Automatically managed, faster.
- **Heap**: Dynamically allocated memory. Must be manually managed with `new` and `delete`.
```cpp
int* ptr = new int(10); // Allocate on heap
delete ptr;            // Free heap memory
```

### 4. **Memory Allocation**
- `malloc`/`free`: C-style allocation.
- `new`/`delete`: C++ allocation.
- **Smart Pointers** manage memory automatically to prevent leaks.

### 5. **Smart Pointers**
```cpp
#include <memory>
std::unique_ptr<int> p = std::make_unique<int>(42);
std::cout << *p << std::endl;
```

### 6. **File I/O**
```cpp
#include <fstream>
std::ofstream outFile("example.txt");
outFile << "Hello, File!";
outFile.close();
```

### 7. **System Calls**
System calls are requests from a program to the OS for resources (e.g., `read`, `write`).

### 8. **Random Number Generation**
```cpp
#include <random>
std::mt19937 gen(std::random_device{}());
std::uniform_int_distribution<> dist(1, 100);
std::cout << dist(gen) << std::endl;
```

### 9. **Parallelism**
Using threads for concurrent execution.
```cpp
#include <thread>
void task() { std::cout << "Task running" << std::endl; }
std::thread t(task);
t.join();
```

---

## Running the Program
1. Compile the program:
   ```bash
   g++ -std=c++11 main.cpp -o main
   ```
2. Run the binary:
   ```bash
   ./main
   ```

---

## Resources
- [C++ Official Documentation](https://cplusplus.com)
- [C++ Standard Library Reference](https://en.cppreference.com)
- [Learn C++ Tutorials](https://www.learncpp.com)

---

## License
This project is licensed under the MIT License. Feel free to modify and distribute it.

---

Happy Coding! 🎉


---

## Running the Program
1. Compile the program:
   ```bash
   g++ -std=c++11 main.cpp -o main
   ```
2. Run the binary:
   ```bash
   ./main
   ```

---

## Resources
- [C++ Official Documentation](https://cplusplus.com)
- [C++ Standard Library Reference](https://en.cppreference.com)
- [Learn C++ Tutorials](https://www.learncpp.com)

---

## License
This project is licensed under the MIT License. Feel free to modify and distribute it.
Happy Coding! 🎉

---

