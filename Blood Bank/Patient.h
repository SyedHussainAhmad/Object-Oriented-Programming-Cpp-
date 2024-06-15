#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person 
{
private:
    string patientID;
    string illness;
    string hospitalName;

public:
    Patient(const string& name, int age, const string& gender, const string& bloodType,
        const string& patientID, const string& illness, const string& hospitalName);
    ~Patient();

    string getPatientID() const;
    string getIllness() const;
    string getHospitalName() const;

    void setPatientID(const string& patientID);
    void setIllness(const string& illness);
    void setHospitalName(const string& hospitalName);

    void display() const override;
};

#endif // PATIENT_H
