#include <iostream> 
#include <string> 
#include <vector>
#include "Doctor.h"
using namespace std;





	//This function adds a new patient to the vector list of patients stored in doctor.
	//This function takes a string of the name of the patient as input, creates a class object for that patient,
	//gives the option for the user to input cholesterol readings for that patient, and then 
	//adds the patient to the vector
	void doctor::addPatient(string newPatientName)
	{
			//Variable to store the temporary cholesterol readings as they are passed into the vector
			float tempCholesterolReading;
			
			//Creates a new patient object with patient name set to the user input
			patient newPatient(newPatientName);

			//Print statements prompting the user to enter cholesterol readings or enter -1 to continue
			cout << "Enter a Cholesterol Readings for this patient";
			cout << "pressing 'ENTER' after each one,\nor press '-1' when you are finished to continue.\n\n";
			cout << "Please note each patient may have a maximum of " << newPatient.getMaxNumberOfCholesterolReadings();
			cout << " cholesterol readings.\n\n";

			//While loop to make sure that their are no more than the maximum number of cholesterol readings entered. 
			//After the max number reading is entered, the program proceeds back to the menu for the next input
			while (newPatient.numberOfCholesterolReadings() < newPatient.getMaxNumberOfCholesterolReadings())
			{
				//Prompt for the user to enter a cholesterol reading
				cout << "Cholesterol Reading: ";

				//Stores user input for the cholesterol reading into the temporary variable
				cin >> tempCholesterolReading;
				cout << endl << endl;

				//Error Checking to make sure the cholesterol value is positive or -1 to return to the menu
				while (cin.fail() || (tempCholesterolReading < 0 && tempCholesterolReading != -1))
				{
					cout << "Entry Invalid. Cholesterol Reading must be positive a numeric value";
					cout << "or enter -1 to return to the menu. \n\n";
					cout << "Cholesterol Reading: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> tempCholesterolReading;
					cout << endl << endl;
				}


				//If the user enters -1 then the while loop exits to add the patient to the vector
				if (tempCholesterolReading == -1)
				{
					break;
				}


				//Checks to make sure the value entered is positive
				else if (tempCholesterolReading > 0)
				{
					newPatient.addCholesterolReading(tempCholesterolReading);
				}

				//If the value is not positive, Outputs a message explaining that the value must be positive
				else if (tempCholesterolReading < 0)
				{
					cout << "Cholesterol Readings must be positive numbers.\n\n";
				}

			}

			//The patient object with it's name and cholesterol readings are added to the vector list
			doctorsPatients.push_back(newPatient);
		
	

	}


	//This function returns the patient at the indexed value in the vector
	patient doctor::getPatient(int patientNumber) const
	{
		return doctorsPatients[patientNumber];
	}




	//Function to set the doctor's name
	void doctor::setDoctorName(string inputDoctorName)
	{
		doctorName = inputDoctorName;
	}



	//Function to return the doctor's name
	string doctor::getDoctorName() const
	{
		return doctorName;
	}



	//This function prints out the doctor's patients and calls the print function in the patients class to 
	//print out their cholesterol values as well
	void doctor::printDoctorsPatients() const
	{
		//Prints the doctor's name
		cout << "Doctor: " << getDoctorName() << endl << endl;

		//If there are no patients assigned to the doctor, prints message to explain there are no patients found
		if (getNumberOfCurrentPatients() == 0)
		{
			cout << "No patients to display.\n";
		}

		//Otherwise cycles through the patients in the vector list and calls the print funtion 
		//in the patient class for each
		else
		{
			//Cycles through each patient currently in the vector
			for (int i = 0; i < getNumberOfCurrentPatients(); i++)
			{
				//Creates temporary patient object to store the patient object currently being itterated
				//over
				patient currentPatient = doctorsPatients.at(i);

				//Prints the patient and patient number
				cout << "Patient " << (i + 1) << ": ";

				//Calls the patient function to print this patients information
				currentPatient.printPatientData();
			}
		} 
		cout << endl << endl;
	}

	//Returns the current number of patients in the vector list
	int doctor::getNumberOfCurrentPatients() const
	{
		return doctorsPatients.size();
	}

	int doctor::getMaxNumberOfPatients() const
	{
		return maxNumberOfPatients;
	}


	//Constructors

	//Constructor that takes a string as input to initialize the doctor with a name value
	doctor::doctor(string inputDoctorName)
	{
		doctorName = inputDoctorName;
	}

	//default constructor
	doctor::doctor()
	{
		doctorName = "";
	}












//Extra Functions



	//This function when called prompts the user for which patient they would like to remove from the 
	//vector of patients and then removes that patient.
	void doctor::removePatient()
	{
		//Variable to store the patient number of which patient they would like to remove
		int choiceToRemove = 0;

		//Prompt for the user to choose a patient to remove
		cout << "Please enter the number of the patient you would like to remove or enter -1 to go back.\n\n";


		//Cycles through as many patients there are in the list and for each one prints a 
		//number beside the name for the user to see which patients there are and choose one to remove
		for (int patientCounter = 0; patientCounter < getNumberOfCurrentPatients(); patientCounter++)
		{
			//Creates a temporary patient object to store the current patient being cycled over's info
			patient currentPatient = getPatient(patientCounter);

			//Increments the patient counter by 1 so the numbering is not 0 indexed and displays the patient's 
			//name beside the number
			cout << patientCounter + 1 << ": " << currentPatient.getPatientName() << endl;


		}

		cout << endl << endl;

		//Prompts the user to enter the number that they would like to remove and stores that number in
		//the choiceToRemove variable
		cout << "Patient Number: ";
		cin >> choiceToRemove;
		cout << endl << endl;

		//Error checking to make sure the choice entered is a valid option
		while (cin.fail() || (choiceToRemove < -1) || choiceToRemove == 0 || choiceToRemove > getNumberOfCurrentPatients())
		{
			cout << "Entry Invalid. You must enter the number of the patient you would like to remove.\n";
			cout << "Please try again.\n\n";
			cout << "Patient Number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> choiceToRemove;
			cout << endl << endl;
		}


		//If the patient the user wishes to remove is the last in the vector, remove the last item in the vector
		if (choiceToRemove == getNumberOfCurrentPatients())
		{
			doctorsPatients.pop_back();
		}

		//If it's anywhere else in the vector, remove it where it is
		else if (choiceToRemove > 0 && choiceToRemove < getNumberOfCurrentPatients())
		{
			doctorsPatients.erase(doctorsPatients.begin() + (choiceToRemove - 1));
		}

	}


	//This function removes a cholesterol reading from an existing patient
	void doctor::removeCholesterolreading()
	{
		//Variable to store the patient number of which patient they would like to access
		int choiceToAccessPatient = 0;
		int choiceToAccessCholesterol = 0;


		//Prompt for the user to choose a patient to access
		cout << "Please enter the number of the patient you would like to add to ";
		cout << "or enter -1 to go back.\n\n";


		//Cycles through as many patients there are in the list and for each one prints a 
		//number beside the name for the user to see which patients there are and choose one to access
		for (int patientCounter = 0; patientCounter < getNumberOfCurrentPatients(); patientCounter++)
		{
			//Creates a temporary patient object to store the current patient being cycled over's info
			patient currentPatient = getPatient(patientCounter);

			//Increments the patient counter by 1 so the numbering is not 0 indexed and displays the patient's 
			//name beside the number
			cout << patientCounter + 1 << ": " << currentPatient.getPatientName() << endl;


		}

		cout << endl << endl;

		//Prompts the user to enter the number of the patient they would like
		//to access and stores that number in the choiceToAccess variable
		cout << "Patient Number: ";
		cin >> choiceToAccessPatient;
		cout << endl << endl;

		//Error checking to make sure the choice entered is a valid option
		while (cin.fail() || (choiceToAccessPatient < -1) || choiceToAccessPatient == 0 || choiceToAccessPatient > getNumberOfCurrentPatients())
		{
			cout << "Entry Invalid. You must enter the number of the patient you would like to access.\n";
			cout << "Please try again.\n\n";
			cout << "Patient Number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> choiceToAccessPatient;
			cout << endl << endl;
		}

		//Creates a temporary copy of the patient we would like to access so that we can print the cholesterol
		//values assigned to that patient
		patient patientChoice = getPatient(choiceToAccessPatient - 1);

		//For loop to cycle through the cholesterol readings
		for (int i = 0; i < patientChoice.numberOfCholesterolReadings(); i++)
		{
			//Creates a temporary float variable to store the current cholesterol level being cycled over
			double currentReading = patientChoice.getCholesterolReading(i);

			//Increments the patient counter by 1 so the numbering is not 0 indexed and displays the patient's 
			//name beside the number
			cout << i + 1 << ": " << currentReading << endl;
		}

		cout << endl << endl;
		cout << "Enter the cholesterol reading you would like to remove or enter -1 to exit.\n\n";

		//Prompts the user to enter the number of the cholesterol reading they would like
		//to access and stores that number in the choiceToAccess variable
		cout << "Cholesterol Reading: ";
		cin >> choiceToAccessCholesterol;
		cout << endl << endl;

		//Error checking to make sure the choice entered is a valid option
		while (cin.fail() || (choiceToAccessCholesterol < -1) || choiceToAccessCholesterol == 0 || choiceToAccessCholesterol > patientChoice.numberOfCholesterolReadings())
		{
			cout << "Entry Invalid. You must enter the number of the cholesterol reading you would like to access or -1 to return to the menu.\n";
			cout << "Please try again.\n\n";
			cout << "Cholesterol Reading: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> choiceToAccessCholesterol;
			cout << endl << endl;
		}



		if (choiceToAccessCholesterol != -1)
		{
			//Pass the choice to access subtracting one so that with the zero indexing the correct reading is removed
			doctorsPatients[choiceToAccessPatient - 1].removeCholesterol((choiceToAccessCholesterol - 1));
		}

	}

	//This function adds a cholesterol reading to an existing patient
	void doctor::addCholesterolReadingToExisting()
	{

		//Variable to store the patient number of which patient they would like to access
		int choiceToAccess = 0;

		double tempCholesterolReading;

		//Prompt for the user to choose a patient to access
		cout << "Please enter the number of the patient you would like to add to ";
		cout << "or enter -1 to go back.\n\n";


		//Cycles through as many patients there are in the list and for each one prints a 
		//number beside the name for the user to see which patients there are and choose one to access
		for (int patientCounter = 0; patientCounter < getNumberOfCurrentPatients(); patientCounter++)
		{
			//Creates a temporary patient object to store the current patient being cycled over's info
			patient currentPatient = getPatient(patientCounter);

			//Increments the patient counter by 1 so the numbering is not 0 indexed and displays the patient's 
			//name beside the number
			cout << patientCounter + 1 << ": " << currentPatient.getPatientName() << endl;


		}

		cout << endl << endl;

		//Prompts the user to enter the number of the patient they would like
		//to access and stores that number in the choiceToAccess variable
		cout << "Patient Number: ";
		cin >> choiceToAccess;
		cout << endl << endl;

		//Error checking to make sure the choice entered is a valid option
		while (cin.fail() || (choiceToAccess < -1) || choiceToAccess == 0 || choiceToAccess > getNumberOfCurrentPatients())
		{
			cout << "Entry Invalid. You must enter the number of the patient you would like to access.\n";
			cout << "Please try again.\n\n";
			cout << "Patient Number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> choiceToAccess;
			cout << endl << endl;
		}

		//Creates a temporary patient object to cycle over the cholesterol readigns assigned to that patient
		patient tempPatient = getPatient(choiceToAccess - 1);

		//If there are less than teh maximum number of cholesterol readings for this current patient,
		//add one to the list
		if (tempPatient.numberOfCholesterolReadings() < tempPatient.getMaxNumberOfCholesterolReadings())
		{
			//Prompts the user for a new cholesterol reading
			cout << "Please enter cholesterol reading you would like to add to the list.\n\n";
			cout << "Cholesterol Reading: ";
			cin >> tempCholesterolReading;
			cout << endl << endl;

			doctorsPatients[choiceToAccess - 1].addCholesterolReading(tempCholesterolReading);
		}

		//Otherwise inform the user they can not add more cholesterol readings
		else
		{
			cout << "Maximum number of Cholesterol readings allowed is " << tempPatient.getMaxNumberOfCholesterolReadings();
			cout << "." << endl;
			cout << "Please remove cholesterol readings from this patient before adding more.\n\n";
		}

	}