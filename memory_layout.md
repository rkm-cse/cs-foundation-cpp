# Technical Note: Memory Layout of a C++ Program

## 1. Executive Summary
When a C++ executable runs, the Operating System allocates virtual memory divided into five primary segments: Text, Data, BSS, Heap, and Stack.

## 2. Memory Regions Breakdown

| Segment | Primary Purpose | Lifetime | Growth Direction |
| :--- | :--- | :--- | :--- |
| **Text** | Executable machine instructions (Read-only) | Program duration | Static |
| **Data** | Initialized global and static variables | Program duration | Static |
| **BSS** | Uninitialized global and static variables (Zeroed by OS) | Program duration | Static |
| **Heap** | Dynamic allocations (`new` / `malloc`) | Manual (`delete`) | Upward (Higher Addresses) |
| **Stack** | Function frames, local variables, return pointers | Automatic (Scope-based) | Downward (Lower Addresses) |

## 3. Real-World Execution Analysis
Addresses inspected from local MSYS2 GCC environment (`main.cpp` execution):

- **Data Segment (`globalVal`):** `0x7ff6a7983000`
- **BSS Segment (`globalUninit`):** `0x7ff6a7987030`
- **Heap (`heapPtr`):** `0x21b547a02c0`
- **Stack (`localVar`):** `0xcf90dffe6c`

### Key Takeaways
1. Data and BSS sit adjacent in memory during binary initialization.
2. Stack memory resides at significantly higher addresses compared to Heap allocations.
3. Heap memory requires explicit management (`delete[]`) to prevent memory leaks.