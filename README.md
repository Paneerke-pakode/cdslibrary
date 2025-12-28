# Custom Data Structure Library (C)

A modular, reusable data structure library implemented from scratch in C.
Designed with clean APIs, explicit error handling, and manual memory control.

## Features
- Singly Linked List
- Stack (array-based)
- Queue (circular array)
- Binary Search Tree
- Max Heap / Priority Queue
- HashMap (separate chaining)

## Design Goals
- Encapsulation via opaque structs
- Consistent error semantics
- No global state
- Manual memory management
- Test-driven validation

## Build Instructions

```bash
mkdir build
cd build
cmake ..
make
