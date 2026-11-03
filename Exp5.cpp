#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;
};

int main()
{
    vector<Student> students =
    {
        {"Arun", 85, ' '},
        {"Naveen", 72, ' '},
        {"Kumar", 91, ' '},
        {"Ravi", 65, ' '}
    };

    // Sort by marks
    sort(students.begin(), students.end(),
    [](Student a, Student b)
    {
        return a.mark > b.mark;
    });

    // Assign grades
    transform(students.begin(), students.end(),
              students.begin(),
    [](Student s)
    {
        if (s.mark >= 90)
            s.grade = 'A';
        else if (s.mark >= 75)
            s.grade = 'B';
        else if (s.mark >= 50)
            s.grade = 'C';
        else
            s.grade = 'F';

        return s;
    });

    // First student scoring above 80
    auto it = find_if(students.begin(), students.end(),
    [](Student s)
    {
        return s.mark > 80;
    });

    // Total marks
    int total = accumulate(students.begin(),
                           students.end(),
                           0,
    [](int sum, Student s)
    {
        return sum + s.mark;
    });

    float average =
        (float)total / students.size();

    cout << "Student Grade Analyzer\n";
    cout << "----------------------\n";
    cout << "Name\tMark\tGrade\n";

    for (Student s : students)
    {
        cout << s.name << "\t"
             << s.mark << "\t"
             << s.grade << endl;
    }

    if (it != students.end())
    {
        cout << "\nFirst student scoring above 80: "
             << it->name << endl;
    }

    cout << "\nTotal Marks: "
         << total << endl;

    cout << "Average Mark: "
         << average << endl;

    // NEW FEATURE
    cout << "\n--- Class Report ---\n";

    cout << "Class Topper: "
         << students[0].name
         << " (" << students[0].mark << " marks)"
         << endl;

    if (average >= 80)
        cout << "Class Performance: Excellent" << endl;
    else if (average >= 60)
        cout << "Class Performance: Good" << endl;
    else
        cout << "Class Performance: Needs Improvement" << endl;

    return 0;
}