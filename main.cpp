#include <iostream>

int globalVal = 100;     // Data Segment
int globalUninit;        // BSS Segment

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int localVar = 50;           // Stack
    int* heapPtr = new int(200); // Heap

    std::cout << "Data Segment (globalVal)  : " << &globalVal << '\n';
    std::cout << "BSS Segment  (globalUninit) : " << &globalUninit << '\n';
    std::cout << "Heap         (heapPtr)    : " << heapPtr << '\n';
    std::cout << "Stack        (localVar)   : " << &localVar << '\n';

    delete heapPtr; // Clean up Heap memory
    return 0;
}