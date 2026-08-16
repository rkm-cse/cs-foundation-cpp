#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> // for std::sort

struct Student {
    int rollNo;
    std::string name;
    double marks[3]; // marks for 3 subjects
    double totalmarks;
    double cgpa;
    int rank;
};

bool comparebyCGPA(const Student& a, const Student& b) {
    return a.cgpa > b.cgpa;
}

int main()
{
    int totalStudents;
    std::cout << "Enter total number of students : ";
    if (!(std::cin >> totalStudents) || totalStudents <= 0) return 0;

    Student* students = new Student[totalStudents];

    for (int i = 0; i < totalStudents; ++i) {
     std::cout << "\n--- Enter details for Student " << (i + 1) << " ---\n";
        std::cout << "Roll No: ";
        std::cin >> students[i].rollNo;

        std::cout << "Name (Single word): ";
        std::cin >> students[i].name;

        students[i].totalmarks = 0;
        std::cout << "Enter marks for 3 subjects (out of 100): ";
        for (int j = 0; j < 3; ++j) {
            std::cin >> students[i].marks[j];
            students[i].totalmarks += students[i].marks[j];

        }
        students[i].cgpa = (students[i].totalmarks / 300.0) *10.0;
    }
        std::sort(students, students + totalStudents, comparebyCGPA);

       for (int i = 0; i < totalStudents; ++i) {
            students[i].rank = i + 1;
        }
        std::cout << "\n=====================================================================\n";
    std::cout << std::left 
              << std::setw(6)  << "Rank" 
              << std::setw(10) << "Roll No" 
              << std::setw(18) << "Name" 
              << std::setw(14) << "Total Marks" 
              << std::setw(8)  << "CGPA" << '\n';
    std::cout << "---------------------------------------------------------------------\n";

    for (int i = 0; i < totalStudents; ++i) {
    std::cout << std::left 
              << std::setw(6)  << students[i].rank 
              << std::setw(10) << students[i].rollNo 
              << std::setw(18) << students[i].name 
              << std::setw(14) << std::fixed << std::setprecision(2) << students[i].totalmarks 
              << std::setw(8)  << std::fixed << std::setprecision(2) << students[i].cgpa << '\n';
}
std::cout << "=====================================================================\n";

delete[] students;

return 0;
}

