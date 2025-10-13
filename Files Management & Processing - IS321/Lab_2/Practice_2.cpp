#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
Practice 2:
	- Open the "students.txt" and append students from "new students" file to it (without using
	  loop). Below is the contents of "new students" file. After appending the new records,
	  display the file contents of "students.txt", and the total number of students in it.

	- new_students.txt:
	  Dina Ahmed,22,3.59$Ahmed Ramdan,25,4$Mohamed Ali,33,2.38$
*/

int main()
{
    fstream studentsFstream("students.txt", ios::out|ios::in);
    fstream newStudentsFstream("new_students.txt", ios::in);

    if (!studentsFstream.good() || !newStudentsFstream.good())
    {
        cout << "Error opening one of files. Program aborting.\n";
        return -1;
    }

    // Append new students

	newStudentsFstream.seekg (0,newStudentsFstream.end);
	long size = newStudentsFstream.tellg();
	newStudentsFstream.seekg (0);//by default seeks from beginning
	char* buffer = new char[size];
	newStudentsFstream.read (buffer,size);
	studentsFstream.seekp(0,studentsFstream.end);
	studentsFstream.write (buffer,size);

    newStudentsFstream.close();
   

    // Count number of students
    int count=0;
    studentsFstream.seekg(0,studentsFstream.beg);
    char line[28];
    while (studentsFstream.getline(line, 28, '$')) {
        count ++;
        cout<< "student "<<count<<":"<<line<<endl;
    }

    cout<<"Number of students: "<<count;
    studentsFstream.close();
    return 0;
}










