#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int studentCount;
    std::cout << "Enter number of students: ";
    if (!(std::cin >> studentCount) || studentCount <= 0) {
        return 0;
    }

    // Allocate dynamic array on the Heap
    double* gpaArray = new double[studentCount];

    // Read GPAs
    for (int i = 0; i < studentCount; ++i) {
        std::cin >> gpaArray[i];
    }

    // Calculate Average GPA
    double sum = 0.0;
    for (int i = 0; i < studentCount; ++i) {
        sum += gpaArray[i];
    }
    double average = sum / studentCount;

    std::cout << "Average GPA: " << std::fixed << std::setprecision(2) << average << '\n';

    // Cleanup Heap allocation
    delete[] gpaArray;

    return 0;
}