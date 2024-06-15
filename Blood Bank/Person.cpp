#include "Person.h"

// Constructor
Person::Person(const string& name, int age, const string& gender, const string& bloodType)
    : name(name), age(age), gender(gender), bloodType(bloodType) {}

// Destructor
Person::~Person() {}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getGender() const {
    return gender;
}

string Person::getBloodType() const {
    return bloodType;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setGender(const string& gender) {
    this->gender = gender;
}

void Person::setBloodType(const string& bloodType) {
    this->bloodType = bloodType;
}

// Display method
void Person::display() const {
    cout << "Name: " << name << "\nAge: " << age << "\nGender: " << gender << "\nBlood Type: " << bloodType << endl;
}
