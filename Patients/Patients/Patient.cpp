#include <iostream> 
#include <string> 
#include <vector>
#include "Patient.h"
using namespace std;


	//Sets the name of the patient to the input name
	void patient::setPatientName(string nameOfPatient)
	{
		patientName = nameOfPatient;
	}

	//Returns the name of the patient
	string patient::getPatientName() const
	{
		return patientName;
	}


	//Returns the cholesterol reading at the indexed value
	double patient::getCholesterolReading(int cholesterolReadingIndex) const
	{
		return cholesterolReadings.at(cholesterolReadingIndex);
	}

	//Returns the number of cholesterol readings currently in the vector
	int patient::numberOfCholesterolReadings() const
	{
		return cholesterolReadings.size();
	}


	//Prints the patients name and cholesterol readings
	void patient::printPatientData() const
	{
	
		//Prints the patient name
		cout << getPatientName() << endl;

		//itterates through each cholesterol reading and prints it out
		for (int index = 0; index < numberOfCholesterolReadings(); index++)
		{
			cout << "Cholesterol Reading " << (index + 1) << ": " << getCholesterolReading(index) << endl;
		}

		cout <<  endl;
	}

	//Returns the max number of cholesterol readings
	int patient::getMaxNumberOfCholesterolReadings() const
	{
		return maxNumberOfCholesterolReadings;
	}



	//Constructors

	//Default constructor
	patient::patient()
	{
		patientName = "";
	}

	//Constructor that takes a string input vlue to initialize patient with a name
	patient::patient(string inputPatientName)
	{
		patientName = inputPatientName;
	}











	//Extra Functions

		//This function adds a cholesterol reading to the vector of cholesterol readings
	void patient::addCholesterolReading(double newCholesterolReading)
	{
		cholesterolReadings.push_back(newCholesterolReading);
	}

	//Function to remove a cholesterol level from an existing patient
	void patient::removeCholesterol(int indexToRemove)
	{

		if ((indexToRemove + 1) == numberOfCholesterolReadings())
		{
			cholesterolReadings.pop_back();
		}

		else
		{
			cholesterolReadings.erase(cholesterolReadings.begin() + indexToRemove);
		}

	}