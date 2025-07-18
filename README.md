
---

## 🧠 Implemented Data Structures

### ✅ Day 1 – Basics

#### 1. Dynamic Array

- **Path:** `dynamic_array/DynamicArray.cpp`
- **Description:** Custom implementation of a dynamic array with:
  - Automatic resizing (doubling strategy)
  - Insertion, deletion
  - Traversal
- **Time Complexities:**
  - Access: `O(1)`
  - Insert (end): `Amortized O(1)`
  - Delete: `O(n)`
- **Space Complexity:** `O(n)`

#### 2. Singly Linked List

- **Path:** `linked_list/SinglyLinkedList.cpp`
- **Features:**
  - Insert at head/tail
  - Delete by value
  - Traverse and print
- **Time Complexities:**
  - Insert/Delete: `O(1)` at head, `O(n)` at tail
  - Search/Traverse: `O(n)`
- **Space Complexity:** `O(n)`

#### 3. Stack

- **Using Array**
  - **Path:** `stack/StackArray.cpp`
  - **Time:** Push/Pop/Peek: `O(1)`
  - **Space:** `O(n)`
- **Using Linked List**
  - **Path:** `stack/StackLinkedList.cpp`
  - **Time:** Push/Pop: `O(1)`
  - **Space:** `O(n)`

---

### ✅ Day 2 – Intermediate Linked Structures

#### 4. Queue

- **Using Array**
  - **Path:** `queue/QueueArray.cpp`
  - **Time:** Enqueue/Dequeue: `O(1)` (if circular), else `O(n)`
  - **Space:** `O(n)`
- **Using Linked List**
  - **Path:** `queue/QueueLinkedList.cpp`
  - **Time:** Enqueue/Dequeue: `O(1)`
  - **Space:** `O(n)`

#### 5. Doubly Linked List

- **Path:** `linked_list/DoublyLinkedList.cpp`
- **Features:** 
  - Forward/backward traversal
  - Insert/delete from both ends
- **Time Complexities:**
  - Insert/Delete: `O(1)` at ends, `O(n)` by value
  - Traverse: `O(n)`
- **Space Complexity:** `O(n)`

#### 6. Circular Linked List

- **Path:** `linked_list/CircularLinkedList.cpp`
- **Description:** Tail node links back to head, forming a cycle
- **Time Complexities:**
  - Insert/Delete: `O(1)` at head/tail
  - Traverse: `O(n)`
- **Space Complexity:** `O(n)`

---

### ✅ Day 3 – Behavioral Interview Preparation

#### 👨‍💼 Exponent Preparation

- Registered on [Exponent](https://www.tryexponent.com)
- Completed mock behavioral interview prep
- Created STAR-format answers for 5 popular behavioral questions

#### 📄 File:

- All responses stored in: `behavioral_responses.md`

---

## 💡 How to Compile & Run

Use these commands to build and run each file:

### Example (Linux/macOS terminal or Git Bash for Windows):

```bash
# Compile
g++ -o stack_array_app stack/StackArray.cpp

# Run
./stack_array_app
