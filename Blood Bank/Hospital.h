#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include "BloodDonor.h"
#include <string>
#include <iostream>

class Hospital {
private:
    Patient** patients;
    BloodDonor** donors;
    int patientCount;
    int donorCount;
    int patientCapacity;
    int donorCapacity;

    void resizePatients();
    void resizeDonors();

public:
    Hospital();
    ~Hospital();

    // Add patient and donor
    void addPatient(const Patient& patient);
    void addDonor(const BloodDonor& donor);

    // Generate bill for a patient
    double generateBill(const Patient& patient, double treatmentCost, double bloodCost, double travelCost) const;

    // Pay donor for donating blood
    void payDonor(const BloodDonor& donor, double amount);

    // Request for a blood donor
    BloodDonor* requestDonor(const string& bloodType);

    // Display all patients and donors
    void displayPatients() const;
    void displayDonors() const;
    // Getters for patient and donor counts and lists
    int getPatientCount() const;
    int getDonorCount() const;
    Patient** getPatients() const;
    BloodDonor** getDonors() const;
};

#endif // HOSPITAL_H
