#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person 
{
protected:
    string name;
    int age;
    string gender;
    string bloodType;

public:
    Person(const string& name, int age, const string& gender, const string& bloodType);
    virtual ~Person();

    // Accessor methods
    string getName() const;
    int getAge() const;
    string getGender() const;
    string getBloodType() const;

    // Mutator methods
    void setName(const string& name);
    void setAge(int age);
    void setGender(const string& gender);
    void setBloodType(const string& bloodType);

    // Display method
    virtual void display() const;
};

#endif // PERSON_H
