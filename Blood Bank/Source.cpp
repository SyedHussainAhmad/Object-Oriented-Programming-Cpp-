#include "Hospital.h"
#include "Patient.h"
#include "BloodDonor.h"
#include <iostream>
#include <string>

void displayMenu() {
    std::cout << "Hospital Blood Donation System\n";
    std::cout << "1. Add Patient\n";
    std::cout << "2. Add Blood Donor\n";
    std::cout << "3. Request Blood Donor\n";
    std::cout << "4. Generate Bill\n";
    std::cout << "5. Display Patients\n";
    std::cout << "6. Display Donors\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Hospital hospital;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name, gender, bloodType, patientID, illness, hospitalName;
            int age;
            std::cout << "Enter patient name: ";
            std::cin >> name;
            std::cout << "Enter patient age: ";
            std::cin >> age;
            std::cout << "Enter patient gender: ";
            std::cin >> gender;
            std::cout << "Enter patient blood type: ";
            std::cin >> bloodType;
            std::cout << "Enter patient ID: ";
            std::cin >> patientID;
            std::cout << "Enter patient illness: ";
            std::cin >> illness;
            std::cout << "Enter hospital name: ";
            std::cin >> hospitalName;
            Patient patient(name, age, gender, bloodType, patientID, illness, hospitalName);
            hospital.addPatient(patient);
            break;
        }
        case 2: {
            std::string name, gender, bloodType;
            int age;
            bool hasDisease, isPatient;
            std::cout << "Enter donor name: ";
            std::cin >> name;
            std::cout << "Enter donor age: ";
            std::cin >> age;
            std::cout << "Enter donor gender: ";
            std::cin >> gender;
            std::cout << "Enter donor blood type: ";
            std::cin >> bloodType;
            std::cout << "Does the donor have any disease? (1 for yes, 0 for no): ";
            std::cin >> hasDisease;
            std::cout << "Is the donor also a patient? (1 for yes, 0 for no): ";
            std::cin >> isPatient;
            BloodDonor donor(name, age, gender, bloodType, hasDisease, isPatient);
            hospital.addDonor(donor);
            break;
        }
        case 3: {
            std::string bloodType;
            std::cout << "Enter required blood type: ";
            std::cin >> bloodType;
            BloodDonor* donor = hospital.requestDonor(bloodType);
            if (donor != nullptr) {
                std::cout << "Found compatible donor: \n";
                donor->display();
            }
            break;
        }
        case 4: {
            std::string patientID;
            double treatmentCost, bloodCost, travelCost;
            std::cout << "Enter patient ID: ";
            std::cin >> patientID;
            std::cout << "Enter treatment cost: ";
            std::cin >> treatmentCost;
            std::cout << "Enter blood cost: ";
            std::cin >> bloodCost;
            std::cout << "Enter travel cost: ";
            std::cin >> travelCost;

            for (int i = 0; i < hospital.getPatientCount(); ++i) {
                if (hospital.getPatients()[i]->getPatientID() == patientID) {
                    double totalBill = hospital.generateBill(*hospital.getPatients()[i], treatmentCost, bloodCost, travelCost);
                    std::cout << "Total bill: $" << totalBill << "\n";
                    break;
                }
            }
            break;
        }
        case 5: {
            hospital.displayPatients();
            break;
        }
        case 6: {
            hospital.displayDonors();
            break;
        }
        case 7: {
            std::cout << "Exiting...\n";
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }
    return 0;
}
