#pragma once
#include <iostream> 
#include <string> 
#include <vector>



class patient
{
	//Vector to store the cholesterol readings for this patient
	std::vector <double> cholesterolReadings;

	//Variable to store the max number of cholesterol readings. I have included it here so I would
	//Only need to change it at one place in the future
	int maxNumberOfCholesterolReadings = 5;

	//String to store the patients name
	std::string patientName;

public:
	//Function to set the patients name. Takes a string as input and that string becomes the doctors name
	void setPatientName(std::string nameOfPatient);

	//Returns the patients name
	std::string getPatientName() const;

	//Adds a cholesterol reading to the vector list cholesterolReadings.
	void addCholesterolReading(double newCholesterolReading);
	
	//Takes an integer as an index point in the vector list cholesterolReadings and returns the cholesterol
	//reading at that point
	double getCholesterolReading(int cholesterolReadingIndex) const;

	//Returns the number of cholesterol readings currently in the vector list cholesterolReadings
	int numberOfCholesterolReadings() const;

	//Removes a cholesterol reading from the vector list cholesterolReadings at the index of the integer
	//passed into the function.
	void removeCholesterol(int indexToRemove);

	//Prints the patients name and cholesterol readings when called
	void printPatientData() const;

	//Returns the maximum number of cholesterol readings
	int getMaxNumberOfCholesterolReadings() const;
	



	//Constructors

	//Default constructor, initializes the patients name to ""
	patient();

	//Takes a string as input and initializes the patients name to that string
	patient(std::string inputPatientName);


};