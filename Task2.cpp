#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;


double gradeToPoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1; 
    }
}

int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    double overallCredits = 0, overallGradePoints = 0;

    for (int sem = 1; sem <= numSemesters; sem++) {
        int numCourses;
        cout << "\nEnter the number of courses in Semester " << sem << ": ";
        cin >> numCourses;

        double totalCredits = 0, totalGradePoints = 0;

        cout << "\n--- Enter Course Details for Semester " << sem << " ---\n";
        for (int i = 1; i <= numCourses; i++) {
            char grade;
            double credit;

            cout << "\nCourse " << i << ":\n";
            cout << "Enter grade (A, B, C, D, F): ";
            cin >> grade;
            cout << "Enter credit hours: ";
            cin >> credit;

            double gradePoint = gradeToPoint(grade);
            if (gradePoint == -1) {
                cout << "? Invalid grade entered. Try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                i--;
                continue;
            }

            totalCredits += credit;
            totalGradePoints += gradePoint * credit;
        }

        if (totalCredits > 0) {
            double semesterGPA = totalGradePoints / totalCredits;
            overallCredits += totalCredits;
            overallGradePoints += totalGradePoints;

            cout << fixed << setprecision(2);
            cout << "\n?? Semester " << sem << " Results:\n";
            cout << "Total Credits: " << totalCredits << endl;
            cout << "Total Grade Points: " << totalGradePoints << endl;
            cout << "Semester GPA: " << semesterGPA << endl;
            cout << "----------------------------\n";
        } else {
            cout << "?? No valid courses entered for Semester " << sem << ".\n";
        }
    }

    if (overallCredits > 0) {
    double finalCGPA = overallGradePoints / overallCredits;
    cout << fixed << setprecision(2);
    cout << "\n=====================================\n";
    cout << "?? Final Cumulative CGPA: " << finalCGPA << endl;
    cout << "=====================================\n";
    } else {
    cout << "\n?? No valid data entered. CGPA cannot be calculated.\n";
    }

    cout << "\nProgram Finished ? Press Enter to exit...\n";
    cin.ignore();  
    cin.get();     
    return 0;
}

