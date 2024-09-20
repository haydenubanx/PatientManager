#pragma once
#include <iostream> 
#include <string> 
#include <vector>
#include "Patient.h"


//Class to store Doctor name and vector of doctors patients
class doctor
{
	//Vector of doctor's patients
	std::vector <patient> doctorsPatients;

	//Integer variable to store the max number of patients. I have added this for scalability of the code and so 
	//that if I ever wanted to change the max number of patients I only hve to change it here
	int maxNumberOfPatients = 3;

	//String to store the doctor's name
	std::string doctorName;

public:
	//Adds a patient to the vector list doctorsPatients and also calls the patient function to enter cholesterol 
	//readings for that patient
	void addPatient(std::string newPatientName);

	//Allows the user to select a patient to remove from the vector list doctorsPatients
	void removePatient();

	//Allows the user to add a cholesterol reading to an existing patient as long as that patient is not at the 
	//maximum number of cholesterol readings
	void addCholesterolReadingToExisting();

	//Allows the user to remove a selected cholesterol reading from a selected patient
	void removeCholesterolreading();

	//Takes an integer as input for an index value in the vector list doctorsPatients and then returns the 
	//patient at that index
	patient getPatient(int patientNumber) const;

	//Takes a string as input and sets the doctors name to that string
	void setDoctorName(std::string inputDoctorName);

	//Returns the doctorsName
	std::string getDoctorName() const;

	//Prints the doctors patients and their cholesterol readings 
	void printDoctorsPatients() const;

	//Returns the number of patients currently in the vector list doctorsPatients
	int getNumberOfCurrentPatients() const;

	//Returns the max number of patients allowed in the vector list doctorsPatients
	int getMaxNumberOfPatients() const;



	//Constructors

	//Constructor that takes a string as input and initializes the doctors name to that string
	doctor(std::string inputDoctorName);

	//Default constructor that inititalizes the doctors name to ""
	doctor();

};