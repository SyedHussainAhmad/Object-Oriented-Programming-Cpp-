#ifndef BLOODDONOR_H
#define BLOODDONOR_H

#include "Person.h"
#include <string>
#include <iostream>

class BloodDonor : public Person {
private:
    bool hasDisease;
    bool isPatient;

public:
    BloodDonor(const std::string& name, int age, const std::string& gender, const std::string& bloodType, bool hasDisease, bool isPatient);
    ~BloodDonor();

    // Accessor methods
    bool getHasDisease() const;
    bool getIsPatient() const;

    // Mutator methods
    void setHasDisease(bool hasDisease);
    void setIsPatient(bool isPatient);

    // Check compatibility
    bool isCompatible(const Person& patient) const;

    // Display method
    void display() const override;
};

#endif // BLOODDONOR_H
