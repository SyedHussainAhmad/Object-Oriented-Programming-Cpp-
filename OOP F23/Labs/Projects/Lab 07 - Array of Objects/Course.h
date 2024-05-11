#ifndef COURSE_H
#define COURSE_H
#include"String.h"
#include<iostream>
using namespace std;

class Course
{
    String name;
    String ID;

public:
    Course();
    Course(const String& name, int ID);
    String getName() const;
    String getID() const;
    void display() const;
};
Sample runs :
Course c1(“OOP”, “CC - 121”);
Student std{ “Jerry”, “121” };
std.enrollCourse(c1);
std.enrollCourse(Course(“DSA”, “CC - 122”));
std.displayCourses();
std.unEnrollCourse(Course(“OOP”, “CC - 121”));
std.displayCourses();


#endif // !COURSE_H