#ifndef OFFERED_COURSES_H
#define OFFERED_COURSES_H
#include"Course.h"

class OfferedCourses
{
    Course courses[10]; //at max, 10 courses can be offered in a semester.
    int noOfCourses;    //represents the actual number of courses currently offered in semester

public:
    OfferedCourses();
    void displayOfferedCourses() const;
    void addCourse(const Course& course);
    const Course& getCourse(int index) const;
};

#endif // !OFFERED_COURSES_H
