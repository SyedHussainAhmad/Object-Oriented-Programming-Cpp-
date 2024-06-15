#include "Hospital.h"

// Constructor
Hospital::Hospital() : patientCount(0), donorCount(0), patientCapacity(10), donorCapacity(10) {
    patients = new Patient * [patientCapacity];
    donors = new BloodDonor * [donorCapacity];
}

// Destructor
Hospital::~Hospital() {
    for (int i = 0; i < patientCount; i++) {
        delete patients[i];
    }
    delete[] patients;

    for (int i = 0; i < donorCount; i++) {
        delete donors[i];
    }
    delete[] donors;
}

// Resize patient array
void Hospital::resizePatients() {
    patientCapacity *= 2;
    Patient** newPatients = new Patient * [patientCapacity];
    for (int i = 0; i < patientCount; i++) {
        newPatients[i] = patients[i];
    }
    delete[] patients;
    patients = newPatients;
}

// Resize donor array
void Hospital::resizeDonors() {
    donorCapacity *= 2;
    BloodDonor** newDonors = new BloodDonor * [donorCapacity];
    for (int i = 0; i < donorCount; i++) {
        newDonors[i] = donors[i];
    }
    delete[] donors;
    donors = newDonors;
}

// Add patient
void Hospital::addPatient(const Patient& patient) {
    if (patientCount == patientCapacity) {
        resizePatients();
    }
    patients[patientCount++] = new Patient(patient);
}

// Add donor
void Hospital::addDonor(const BloodDonor& donor) {
    if (donorCount == donorCapacity) {
        resizeDonors();
    }
    donors[donorCount++] = new BloodDonor(donor);
}

// Generate bill for a patient
double Hospital::generateBill(const Patient& patient, double treatmentCost, double bloodCost, double travelCost) const {
    double totalCost = treatmentCost + bloodCost + travelCost;
    std::cout << "Bill for patient " << patient.getName() << ":\n";
    std::cout << "Treatment Cost: $" << treatmentCost << "\n";
    std::cout << "Blood Cost: $" << bloodCost << "\n";
    std::cout << "Travel Cost: $" << travelCost << "\n";
    std::cout << "Total Cost: $" << totalCost << "\n";
    return totalCost;
}

// Pay donor for donating blood
void Hospital::payDonor(const BloodDonor& donor, double amount) {
    std::cout << "Paying donor " << donor.getName() << " $" << amount << " for donating blood.\n";
}

// Request for a blood donor
BloodDonor* Hospital::requestDonor(const std::string& bloodType) {
    for (int i = 0; i < donorCount; i++) {
        if (donors[i]->isCompatible(Patient("", 0, "", bloodType,"","",""))) {
            return donors[i];
        }
    }
    std::cout << "No compatible donor found for blood type: " << bloodType << std::endl;
    return nullptr;
}

// Display all patients
void Hospital::displayPatients() const {
    std::cout << "Patients:\n";
    for (int i = 0; i < patientCount; i++) {
        patients[i]->display();
        std::cout << std::endl;
    }
}

// Display all donors
void Hospital::displayDonors() const {
    std::cout << "Donors:\n";
    for (int i = 0; i < donorCount; i++) {
        donors[i]->display();
        std::cout << std::endl;
    }
}

// Getters for patient and donor counts and lists
int Hospital::getPatientCount() const {
    return patientCount;
}

int Hospital::getDonorCount() const {
    return donorCount;
}

Patient** Hospital::getPatients() const {
    return patients;
}

BloodDonor** Hospital::getDonors() const {
    return donors;
}