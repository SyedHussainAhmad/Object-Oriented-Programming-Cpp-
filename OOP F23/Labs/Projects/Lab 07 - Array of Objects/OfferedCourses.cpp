#include "OfferedCourses.h"

OfferedCourses::OfferedCourses() : noOfCourses(0)
{
}

void OfferedCourses::displayOfferedCourses() const 
{
    cout << "Offered Courses:\n";
    for (int i = 0; i < noOfCourses; i++) 
    {
        cout << "Course " << i + 1 << ":\n";
        courses[i].display();
    }
}

void OfferedCourses::addCourse(const Course& course) 
{
    if (noOfCourses < 10) 
    {
        courses[noOfCourses++] = course;
    }
}

const Course& OfferedCourses::getCourse(int index) const 
{
    if (!(index >= 0 && index < noOfCourses)) 
    {
        exit(0);
    }
    return courses[index];

}
