# 📘 Data Structures in C++

This repository contains C++ implementations of fundamental data structures built from scratch as part of my one-week intensive training with **OppoTrain**.

---

## 🧠 Implemented Data Structures

### ✅ Day 1

#### 1. Dynamic Array

- **Path:** `dynamic_array/DynamicArray.cpp`
- **Description:** Custom implementation of a dynamic array with automatic resizing, insertion, deletion, and traversal functionalities.

#### 2. Singly Linked List

- **Path:** `linked_list/SinglyLinkedList.cpp`
- **Description:** A singly linked list supporting:
  - Insertion at head and tail
  - Deletion by value
  - Traversal and display

#### 3. Stack

- **Using Array**
  - **Path:** `stack/StackArray.cpp`
  - **Description:** A stack implemented using a fixed-size array with push, pop, peek, and isEmpty operations.

- **Using Linked List**
  - **Path:** `stack/StackLinkedList.cpp`
  - **Description:** A dynamic stack using singly linked list logic for efficient push/pop in O(1) time.

---

### ✅ Day 2

#### 4. Queue

- **Using Array**
  - **Path:** `queue/QueueArray.cpp`
  - **Description:** A simple queue implemented with an array using front and rear pointers.

- **Using Linked List**
  - **Path:** `queue/QueueLinkedList.cpp`
  - **Description:** Queue using singly linked list with enqueue at tail and dequeue at head.

#### 5. Doubly Linked List

- **Path:** `linked_list/DoublyLinkedList.cpp`
- **Description:** A list with forward and backward links, supporting insertion and deletion from both ends.

#### 6. Circular Linked List

- **Path:** `linked_list/CircularLinkedList.cpp`
- **Description:** A circular version of a singly linked list where the tail points back to the head.

---

## 🔧 How to Compile & Run

Use the following commands in your terminal to compile and run individual files:

### Day 1 Commands

```bash
# Dynamic Array
g++ -o dynamic_array_app dynamic_array/DynamicArray.cpp
./dynamic_array_app

# Singly Linked List
g++ -o linked_list_app linked_list/SinglyLinkedList.cpp
./linked_list_app

# Stack using Array
g++ -o stack_array_app stack/StackArray.cpp
./stack_array_app

# Stack using Linked List
g++ -o stack_linked_app stack/StackLinkedList.cpp
./stack_linked_app


### Day 2 Commands

# Queue using Array
g++ -o queue_array_app queue/QueueArray.cpp
./queue_array_app

# Queue using Linked List
g++ -o queue_linked_app queue/QueueLinkedList.cpp
./queue_linked_app

# Doubly Linked List
g++ -o doubly_linked_list_app linked_list/DoublyLinkedList.cpp
./doubly_linked_list_app

# Circular Linked List
g++ -o circular_linked_list_app linked_list/CircularLinkedList.cpp
./circular_linked_list_app

