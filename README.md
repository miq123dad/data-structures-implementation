# 📘 Data Structures in C++

This repository contains C++ implementations of fundamental data structures built from scratch as part of my one-week intensive training with **OppoTrain**.

---

## 🧠 Implemented Data Structures (Day 1)

### ✅ 1. Dynamic Array
- **Path:** `dynamic_array/DynamicArray.cpp`
- **Description:** Custom implementation of a dynamic array with automatic resizing, insertion, deletion, and traversal functionalities.

### ✅ 2. Singly Linked List
- **Path:** `linked_list/SinglyLinkedList.cpp`
- **Description:** A singly linked list supporting:
  - Insertion at head and tail
  - Deletion by value
  - Traversal and display

### ✅ 3. Stack
- **Using Array**
  - **Path:** `stack/StackArray.cpp`
  - **Description:** A stack implemented using a fixed-size array with push, pop, peek, and isEmpty operations.

- **Using Linked List**
  - **Path:** `stack/StackLinkedList.cpp`
  - **Description:** A dynamic stack using singly linked list logic for efficient push/pop in O(1) time.

---

## 🔧 How to Compile & Run

Use these commands in your terminal:

### Compile & Run Dynamic Array
```bash
g++ -o dynamic_array_app dynamic_array/DynamicArray.cpp
./dynamic_array_app

### Compile & Run Singly Linked List
g++ -o linked_list_app linked_list/SinglyLinkedList.cpp
./linked_list_app

### Compile & Run Stack (Array-based)
g++ -o stack_array_app stack/StackArray.cpp
./stack_array_app

### Compile & Run Stack (Linked List-based)
g++ -o stack_linked_app stack/StackLinkedList.cpp
./stack_linked_app

