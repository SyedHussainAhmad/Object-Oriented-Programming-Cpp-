#ifndef FAMILY_H
#define FAMILY_H

#include "Person.h"
#include <string>
#include <iostream>

class Family {
private:
    Person** familyMembers;
    int memberCount;
    int capacity;

    void resize();

public:
    Family();
    ~Family();

    void addFamilyMember(const Person& member);

    // Get family members with the same blood type
    Person** getMatchingBloodTypeMembers(const std::string& bloodType, int& count) const;

    // Display all family members
    void displayFamilyMembers() const;
};

#endif // FAMILY_H
