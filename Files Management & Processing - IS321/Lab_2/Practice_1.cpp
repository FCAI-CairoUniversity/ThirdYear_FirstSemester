#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
Practice 1:
    - Write student record of his name, id, and grade for any number of students, as long as the
      user enters character "y" to add more records. Add the students records to file
      "students.txt". Each record in the file should be delimited by '$'.

    - Student record format:
        Name, ID, Grade delim
        char[20], int, float char

    - Example: Mohamed Ali,33,2.$
*/

// Declare student structure for the record.
struct Student
{
    char name[20];
    int id;
    float grade;
};

int main()
{
    fstream studentsFstream("students.txt", ios::out);
    Student s;
    char more = 'n';

    if (!studentsFstream.good())
    {
        cout << "Error opening file. Program aborting.\n";
        return -1;
    }

    do{
        cout << "\n Student Name: \n";
        cin.getline(s.name, 20);
        studentsFstream<<s.name<<',';

        cout << "\n Student ID:\n";
        cin>>s.id;
        studentsFstream<<s.id<<',';

        cout << "\n Student grade: \n";
        cin>>s.grade;
        studentsFstream.precision(2);
        studentsFstream<<s.grade<<'$';

        cout << "Do you want to enter more students?";
        cin >> more;
        cin.ignore();

    } while (toupper(more) == 'Y');

    studentsFstream.close();

    return 0;
}
