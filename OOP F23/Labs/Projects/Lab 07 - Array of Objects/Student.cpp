#include "Student.h"

Student::Student(const String& name, int ID) : name(name), ID(ID), courseList(nullptr), coursesCount(0) 
{
}

Student::~Student() 
{
    delete[] courseList;
    coursesCount = 0;
}

String Student::getName() const 
{
    return name;
}

String Student::getID() const 
{
    return ID;
}

void Student::enrollCourse(Course& course) 
{
    courseList[coursesCount] = &course;
    coursesCount++;
}

void Student::unEnrollCourse(const String& courseID) 
{
    bool findFlag = false;
    int i = 0;
    while(i < coursesCount && !findFlag) 
    {
        if (courseList[i]->getID() == courseID) 
        {
            findFlag = true;
            for (int j = i; j < coursesCount - 1; ++j) 
            {
                courseList[j] = courseList[j + 1];
            }
            courseList[coursesCount - 1] = nullptr;
            coursesCount--;
        }
        i++;
    }
}

void Student::displayCourses() const
{
    cout << "Student’s Enrolled Courses:\n";
    for (int i = 0; i < coursesCount; i++) 
    {
        cout << "Course " << i + 1 << ":\n";
        courseList[i]->display();
    }
}
