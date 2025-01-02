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

### 1. **Pointers vs References in C++**

#### **Definition**
- **Pointer**: A variable that stores the memory address of another variable. Pointers can be reassigned and manipulated using arithmetic.
- **Reference**: An alias for another variable. A reference cannot be null, reassigned, or manipulated directly.

#### **Differences Between Pointers and References**
| **Feature**             | **Pointer**                                         | **Reference**                                   |
|-------------------------|---------------------------------------------------|------------------------------------------------|
| **Definition**          | A pointer stores the memory address of a variable. | A reference is an alias for a variable.        |
| **Syntax**              | `int* ptr = &x;`                                  | `int& ref = x;`                                |
| **Nullability**         | Can be `nullptr` (no target).                     | Must always refer to a valid variable.         |
| **Reassignment**        | Can point to a different variable after initialization. | Cannot be reassigned after initialization.     |
| **Dereferencing**       | Requires `*ptr` to access the value.              | Automatically dereferenced when used.          |
| **Arithmetic**          | Can perform pointer arithmetic (`ptr + 1`).       | Pointer arithmetic is not allowed.            |
| **Use Cases**           | Dynamic memory, arrays, complex structures.       | Aliasing variables, simplifying function calls. |

#### **Examples**

##### Pointer Example
```cpp
int x = 10, y = 20;
int* ptr = &x; // Pointer to x
std::cout << *ptr << std::endl; // Prints 10
ptr = &y; // Pointer reassigned to y
std::cout << *ptr << std::endl; // Prints 20
```

##### Reference Example
```cpp
int x = 10, y = 20;
int& ref = x; // Reference to x
std::cout << ref << std::endl; // Prints 10
ref = y; // Assigns y's value to x (does NOT reassign ref)
std::cout << x << std::endl; // Prints 20
```

#### **Key Notes**
- **References Are Safer**:
  - Cannot be null or uninitialized.
  - Cannot be reassigned, so there’s no risk of dangling references.
- **Pointers Are More Flexible**:
  - Can point to `nullptr`.
  - Can change what they point to, making them useful for dynamic memory.

#### **When to Use**
- Use **references** for:
  - Function parameters and return values when aliasing is needed.
  - Simple and safer variable aliases.

- Use **pointers** for:
  - Dynamic memory management.
  - Low-level memory manipulation.

# C++: Classes, Inheritance, Polymorphism, and Virtual Functions

## **1. Classes in C++**

A **class** is a blueprint for creating objects that encapsulate data (variables) and functions (methods) into a single entity.

### **Structure of a Class**
```cpp
class ClassName {
private:
    int privateData; // Accessible only within the class

public:
    int publicData; // Accessible outside the class

    // Constructor
    ClassName(int data) : privateData(data), publicData(0) {}

    // Member function
    void display() {
        std::cout << "Private Data: " << privateData << std::endl;
        std::cout << "Public Data: " << publicData << std::endl;
    }

    // Getter for private data
    int getPrivateData() const { return privateData; }

    // Setter for private data
    void setPrivateData(int value) { privateData = value; }
};
```

### **Key Concepts of Classes**
1. **Encapsulation**: Hides internal details and exposes functionality through public methods.
2. **Access Specifiers**:
   - `private`: Accessible only within the class.
   - `protected`: Accessible within the class and derived classes.
   - `public`: Accessible from anywhere in the program.
3. **Constructors and Destructors**:
   - **Constructor**: Initializes an object when it is created.
     ```cpp
     ClassName obj(10); // Constructor called
     ```
   - **Destructor**: Cleans up resources when the object is destroyed.
     ```cpp
     ~ClassName() { std::cout << "Object destroyed"; }
     ```
4. **Static Members**: Shared across all instances of the class.
   ```cpp
   class MyClass {
   public:
       static int counter; // Shared variable
   };
   int MyClass::counter = 0; // Initialize static member
   ```
5. **Const Member Functions**: Prevent modification of member variables.
   ```cpp
   int getData() const { return privateData; }
   ```

---

## **2. Inheritance in C++**

**Inheritance** allows a class (child/derived class) to inherit attributes and methods from another class (parent/base class).

### **Basic Syntax**
```cpp
class Parent {
public:
    int publicVar;

    void display() {
        std::cout << "Parent Display" << std::endl;
    }
};

class Child : public Parent { // Inherits Parent class
public:
    void show() {
        std::cout << "Child Show" << std::endl;
    }
};

int main() {
    Child obj;
    obj.publicVar = 10; // Access Parent's member
    obj.display();      // Access Parent's method
    obj.show();         // Access Child's method
}
```

### **Types of Inheritance**
1. **Public Inheritance**: 
   - `public` members of the base class remain `public` in the derived class.
   - `protected` members remain `protected`.
2. **Protected Inheritance**:
   - `public` and `protected` members of the base class become `protected` in the derived class.
3. **Private Inheritance**:
   - `public` and `protected` members of the base class become `private` in the derived class.

### **Key Concepts of Inheritance**
1. **Overriding Methods**:
   - A derived class can override base class methods.
     ```cpp
     class Parent {
     public:
         virtual void display() { std::cout << "Parent Display" << std::endl; }
     };

     class Child : public Parent {
     public:
         void display() override { std::cout << "Child Display" << std::endl; }
     };
     ```
2. **Accessing Base Class**:
   - Use `Parent::functionName()` to call the base class method explicitly.
     ```cpp
     Parent::display();
     ```

---

## **3. Polymorphism in C++**

**Polymorphism** allows a single interface to represent different types of behavior.

### **Types of Polymorphism**
1. **Compile-Time Polymorphism (Static Binding)**:
   - Achieved using function overloading or operator overloading.

2. **Run-Time Polymorphism (Dynamic Binding)**:
   - Achieved using inheritance and virtual functions.

### **Compile-Time Polymorphism**
1. **Function Overloading**:
   ```cpp
   class Math {
   public:
       int add(int a, int b) { return a + b; }
       double add(double a, double b) { return a + b; }
   };
   ```
2. **Operator Overloading**:
   ```cpp
   class Complex {
   public:
       int real, imag;

       Complex operator+(const Complex& obj) {
           Complex temp;
           temp.real = real + obj.real;
           temp.imag = imag + obj.imag;
           return temp;
       }
   };
   ```

### **Run-Time Polymorphism**
1. **Virtual Functions**:
   - Ensure that the derived class version of a function is called during runtime.
   ```cpp
   class Parent {
   public:
       virtual void display() { std::cout << "Parent Display" << std::endl; }
   };

   class Child : public Parent {
   public:
       void display() override { std::cout << "Child Display" << std::endl; }
   };

   int main() {
       Parent* p = new Child();
       p->display(); // Calls Child's display() (dynamic dispatch)
       delete p;
   }
   ```
2. **Pure Virtual Functions**:
   - Used to define an interface.
   ```cpp
   class AbstractBase {
   public:
       virtual void display() = 0; // Pure virtual function
   };

   class Derived : public AbstractBase {
   public:
       void display() override {
           std::cout << "Derived Display" << std::endl;
       }
   };
   ```

3. **Virtual Table (vtable)**:
   - A mechanism for dynamic dispatch.
   - The base class and derived class maintain a table of function pointers.
   - At runtime, the vtable is used to resolve the correct function.

---

## **4. Virtual Functions and vtable in Detail**

### **Why Virtual Functions?**
- Without `virtual`, function calls are resolved at compile-time (static dispatch).
- With `virtual`, function calls are resolved at runtime (dynamic dispatch), ensuring the correct derived function is invoked.

### **vtable (Virtual Table)**
1. **How It Works**:
   - Each class with virtual functions has a vtable containing pointers to its virtual functions.
   - Each object has a vptr (virtual pointer) pointing to the vtable of its class.

2. **Example**:
   ```cpp
   class Parent {
   public:
       virtual void display() { std::cout << "Parent Display" << std::endl; }
   };

   class Child : public Parent {
   public:
       void display() override { std::cout << "Child Display" << std::endl; }
   };

   int main() {
       Parent* p = new Child();
       p->display(); // Child's display() is called via vtable
       delete p;
   }
   ```

### **Explicit Base Class Calls**
- Use `Parent::functionName()` to explicitly call the base class version.
   ```cpp
   class Parent {
   public:
       virtual void display() { std::cout << "Parent Display" << std::endl; }
   };

   class Child : public Parent {
   public:
       void display() override {
           std::cout << "Child Display" << std::endl;
           Parent::display(); // Explicitly call Parent's display()
       }
   };

   int main() {
       Child c;
       c.display();
   }
   ```

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

