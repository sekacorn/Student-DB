#include <iostream>
#include "StudentDB.h"
#include <string>
using namespace std;

int main() {
    int choice = 0;
    string studentName = " ";
    string studentBirth = " ";
    string studentMajor = " ";
    Student<int> *nextNode = nullptr;
    Student<int> *prevNode = nullptr;
    Student<string> *Pupil3 = nullptr;
    string Targetname = " ";
    Course *Class = nullptr;
    Course *next = nullptr;
    Course *prev = nullptr;
    Course *courseNext = nullptr;
    char Terminate = ' ';
    int a = 0;
    string courseId = " ";
    string realDepartment = " ";
    string realSemester = " ";
    string TargetCourse = " ";
    string realGrade = " ";
    StudentDB<string> *Mylist;
    Student<string> *MyList2;
    string choice1 = " ";
    string choice2 = " ";
    string choice3 = " ";
    string choice4 = " ";
    string choice5 = " ";
    bool bob = false;
    int numOfstudent = 0;

    // Pre-fills name, date of birth, major, and courses for the database
    studentName = "john";
    studentBirth = "05-12-1992";
    studentMajor = "Math";
    Mylist = new StudentDB<string>;
    numOfstudent = Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor, numOfstudent);

    studentName = "Tom";
    studentBirth = "05-12-1992";
    studentMajor = "Math";
    numOfstudent = Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor, numOfstudent);

    studentName = "Jillian";
    studentBirth = "05-12-1992";
    studentMajor = "Math";
    numOfstudent = Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor, numOfstudent);

    studentName = "Adam";
    studentBirth = "05-12-1992";
    studentMajor = "Math";
    numOfstudent = Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor, numOfstudent);

    courseId = "COSC2";
    realDepartment = "ComputerScience";
    realSemester = "Fall";
    Targetname = "Tom";

    MyList2 = new Student<string>;
    MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment, realSemester, Targetname, realGrade);

    courseId = "ENG";
    realDepartment = "ComputerScience";
    realSemester = "Fall";
    Targetname = "Adam";

    MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment, realSemester, Targetname, realGrade);

    courseId = "BIO";
    realDepartment = "ComputerScience";
    realSemester = "Fall";
    Targetname = "Jillian";

    MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment, realSemester, Targetname, realGrade);

    courseId = "MATH";
    realDepartment = "ComputerScience";
    realSemester = "Fall";
    Targetname = "Tom";
    MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment, realSemester, Targetname, realGrade);
    courseId = "PSYC";
    realDepartment = "ComputerScience";
    realSemester = "Fall";
    Targetname = "Tom";
    MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment, realSemester, Targetname, realGrade);

    while (!bob) {
        choice = PrintMenu(Pupil3);
        if (choice == 1) { // Prints the student
            Mylist->Print(Pupil3, Class);
        } else if (choice == 2) { // Searches for student
            cout << "Please enter the student's name" << endl;
            cin.ignore(256, '\n');
            getline(cin, Targetname);
            Mylist->PrintStudentandCourse(Pupil3, Class, Targetname);
        } else if (choice == 3) { // Updates Student courses
            cout << "Please Enter a course you would like to change" << endl;
            cin.ignore(256, '\n');
            getline(cin, TargetCourse);
            cout << "Please enter a student whose course you want to change" << endl;
            getline(cin, Targetname);
            cout << "Please enter the new name for the course" << endl;
            getline(cin, courseId);
            cout << "Please enter the Department of the course" << endl;
            getline(cin, realDepartment);
            cout << "Please enter semester" << endl;
            getline(cin, realSemester);
            cout << "Please enter Grade for the course" << endl;
            getline(cin, realGrade);
            cout << "Are you sure you want to change the course? Type 'y' for yes or 'n' for no" << endl;
            getline(cin, choice4);
            if (choice4 == "Y" || choice4 == "y") {
                // Call update
                MyList2->updateCourse(Pupil3, Targetname, TargetCourse, courseId, realDepartment, realSemester, realGrade);
            }
        } else if (choice == 4) { // Updates Student record
            cout << "Please enter the student you would want to update" << endl;
            cin.ignore(256, '\n');
            getline(cin, Targetname);
            cout << "Please Enter new name of Student" << endl;
            getline(cin, studentName);
            cout << "StudentName " << studentName << endl;
            cout << "Please Enter student Date of Birth separated by e.g MM-DD-YYYY" << endl;
            getline(cin, studentBirth);
            cout << "Please enter the student's Major" << endl;
            getline(cin, studentMajor);
            cout << "Are you sure you want changes? Enter 'y' for yes or 'n' for no" << endl;
            getline(cin, choice2);
            if (choice2 == "Y" || choice2 == "y") {
                // call update
                Mylist->updateStudent(Pupil3, Targetname, studentName, studentBirth, studentMajor);
            }
        } else if (choice == 5) { // Adds a Student
            cout << "Please Enter name of new Student" << endl;
            cin.ignore(256, '\n');
            getline(cin, studentName);
            cout << "Please Enter student Date of Birth separated by e.g MM-DD-YYYY" << endl;
            getline(cin, studentBirth);
            cout << "Please enter the student's Major" << endl;
            getline(cin, studentMajor);
            cout << "Are you sure you want to add this student? Enter 'y' for yes or 'n' for no" << endl;
            getline(cin, choice5);
            if (choice5 == "Y" || choice5 == "y") {
                // call insert student
                numOfstudent = Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor, numOfstudent);
            }
        } else if (choice == 6) { // Adds a course to student
            choice1 = ' ';
            choice3 = ' ';
            cout << "Please enter a student whose course you want to add" << endl;
            //cin.ignore(256,'\n');
            getline(cin, Targetname);
            cout << "Please enter the name for the course" << endl;
            getline(cin, courseId);
            cout << "Please enter the Department of the course" << endl;
            getline(cin, realDepartment);
            cout << "Please enter semester" << endl;
            getline(cin, realSemester);
            cout << "Please enter Grade for the course" << endl;
            getline(cin, realGrade);
            cout << "Are you sure you want to change the course? Type 'y' for yes or 'n' for no" << endl;
            getline(cin, choice1);
            if (choice1 == "Y" || choice1 == "y") {
                // Call Insert course
                MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment, realSemester, Targetname,
                                      realGrade);
            }
        } else if (choice == 7) { // Deletes a student
            choice1 = " ";
            cout << "Please Enter Name of student you want to delete" << endl;
            cin.ignore(256, '\n');
            getline(cin, Targetname);
            cout << "Are you sure you want to change the course? Enter 'y' for yes or 'n' for no" << endl;
            getline(cin, choice1);
            if (choice1 == "Y" || choice1 == "y") {
                // Call Delete student
                numOfstudent = Mylist->deleteStudent(Pupil3, Targetname, numOfstudent);
            }
        } else if (choice == 8) { // Deletes a student's course
            cout << "Please enter a student whose course you want to delete" << endl;
            getline(cin, Targetname);
            cout << "Please enter the name for the course you want to delete" << endl;
            getline(cin, courseId);
            cout << "Are you sure you want to change the course? Type 'y' for yes or 'n' for no" << endl;
            getline(cin, choice3);
            if (choice3 == "Y" || choice3 == "y") {
                // Call delete course
                MyList2->deleteCourse(Pupil3, Class, Targetname, courseId);
            }
        } else if (choice == 9) {
            bob = true;
        }
    }
    Mylist->Print(Pupil3, Class);
    return 0;
}

int PrintMenu(Student<string> *Pupil3) {
    int answer = 0;
    cout << "Please enter 1 to print all students, 2 to search for a student by name, 3 to update student's course,";
    cout << " 4 to update a student record, 5 to add a student, 6 to add a course to a student,";
    cout << " 7 to delete a student, 8 to delete a student's course, or 9 to exit" << endl;
    cin >> answer;
    return answer;
}
