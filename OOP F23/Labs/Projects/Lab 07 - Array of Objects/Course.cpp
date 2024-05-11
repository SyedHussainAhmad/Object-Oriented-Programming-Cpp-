#include "Course.h"

Course::Course() :name(""), ID("")
{
}

Course::Course(const String& name, int ID) : name(name), ID(ID)
{
}

String Course::getName() const 
{
    return name;
}

String Course::getID() const 
{
    return ID;
}

void Course::display() const 
{
    cout << "Name: "; 
    name.display();
    cout << "\nID: ";
    ID.display();
    cout << '\n';
}
