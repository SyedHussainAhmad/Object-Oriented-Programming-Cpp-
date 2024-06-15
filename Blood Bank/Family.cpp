#include "Family.h"

// Constructor
Family::Family() : memberCount(0), capacity(10) {
    familyMembers = new Person * [capacity];
}

// Destructor
Family::~Family() {
    for (int i = 0; i < memberCount; i++) {
        delete familyMembers[i];
    }
    delete[] familyMembers;
}

// Resize the array
void Family::resize() {
    capacity *= 2;
    Person** newMembers = new Person * [capacity];
    for (int i = 0; i < memberCount; i++) {
        newMembers[i] = familyMembers[i];
    }
    delete[] familyMembers;
    familyMembers = newMembers;
}

// Add a family member
void Family::addFamilyMember(const Person& member) {
    if (memberCount == capacity) {
        resize();
    }
    familyMembers[memberCount++] = new Person(member);
}

// Get family members with the same blood type
Person** Family::getMatchingBloodTypeMembers(const std::string& bloodType, int& count) const {
    count = 0;
    for (int i = 0; i < memberCount; i++) {
        if (familyMembers[i]->getBloodType() == bloodType) {
            ++count;
        }
    }
    Person** matchingMembers = new Person * [count];
    int index = 0;
    for (int i = 0; i < memberCount; i++) {
        if (familyMembers[i]->getBloodType() == bloodType) {
            matchingMembers[index++] = familyMembers[i];
        }
    }
    return matchingMembers;
}

// Display all family members
void Family::displayFamilyMembers() const {
    for (int i = 0; i < memberCount; i++) {
        familyMembers[i]->display();
        std::cout << std::endl;
    }
}
