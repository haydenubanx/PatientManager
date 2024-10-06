//Patients

//Include statements 
#include <iostream> 
#include <iomanip>
#include <string> 
#include <vector>
#include "Doctor.h"
using namespace std;


//Function prototypes
void displayInstructions();
void runAddInstruction(doctor& newDoc);
void addCholesterolInstruction(doctor& newDoc);
void runListInstruction(doctor& newDoc);
void runRemoveInstruction(doctor& newDoc);
void removeCholesterolInstruction(doctor& newDoc);


int main()
{

	//string to temporarily store the doctors name to be passed into the doctors class
	string tempDoctorName;

	//string to store the instruction entered by the user for which menu function to perform
	char enteredInstruction;


	//Gets the doctors name to pass through to the constructor
	cout << "Please Enter Name of Doctor\n\n";
	cout << "Doctor: ";
	cin >> tempDoctorName;
	cout << endl << endl;

	//Creates new instance of a doctor with name entered by the user
	doctor newDoctor(tempDoctorName);

	//Welcome statement
	cout << "This program tracks doctor " << newDoctor.getDoctorName() << "'s patients and the ";
	cout << "cholesterol levels of those patients.\n\n";


	//Function to print instructions for use
	displayInstructions();

	//stores the users menu instruction input in the variable enteredInstruction
	cin >> enteredInstruction;

	cout << endl << endl;

	//While loop to continue displaying the instructions and running the input until Q is entered
	while (enteredInstruction == 'A' || enteredInstruction == 'L' || enteredInstruction == 'C' || enteredInstruction == 'X')
	{


		//Switch statement for the different possible menu instructions
		//In the case of all instructions in the list, I have added a functions in main to call the functions 
		//in the classes for modularity.
		switch (enteredInstruction)
		{
			//If the user enters A and would like to add a new patient
		case 'A':
		{
			//Checks if there are already three or more patients assigned to this doctor
			if (newDoctor.getNumberOfCurrentPatients() >= newDoctor.getMaxNumberOfPatients())
			{
				//if so, prompts the user to choose another option
				cout << "\n\n\nMax Number Of Patients has been reached. Please choose another option.\n\n\n";
			}

			//Otherwise, calls the function to add a patient
			else
			{
				runAddInstruction(newDoctor);
			}

			break;
		}

		//Instruction to add a cholesterol reading to an existing patient
		case 'C':
		{
			//Calls the function to add a cholesterol reading to an existing patient
			addCholesterolInstruction(newDoctor);
			break;
	
		}


		//Instruction to list the doctor's patients and their cholesterol readings
		case 'L':
		{
			//This line is for formatting to help distinguish where the list of patients starts
			cout << right << setw(20) << setfill('_') << endl;

			//Calls the function to print patient data
			runListInstruction(newDoctor);


			break;
		}

		//Instruction to remove a patient from the list
		case 'R':
		{
			//calls the function to call the function to remove a patient
			runRemoveInstruction(newDoctor);

			break;
		}

		//Instruction if the user would like to remove a cholesterol reading from an existing patient
		case 'X':
		{
			//Calls the function to remove a cholesterol reading from an existing patient.
			removeCholesterolInstruction(newDoctor);
			break;
		}

		//Instruciton to quit the program
		case 'Q':
		{
			cout << "Quitting Program\n\n";

			//Statements to exit the program
			system("pause");
			return 1;
		}




		}

		//Function to print instructions for use
		displayInstructions();

		//stores the users menu instruction input in the variable enteredInstruction
		cin >> enteredInstruction;

		cout << endl << endl;
	}


	//Closing program statements 
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
	return 0;
}


//Function to print instructions for use
void displayInstructions()
{
	cout << "Enter one of the letters listed below to perform the corresponding action.\n\n";
	cout << "A -- Add a patient\n";
	cout << "C -- Add cholesterol reading to existing patient\n";
	cout << "L -- List doctor's current patients and their cholesterol levels\n";
	cout << "R -- Remove a Patient From the List\n";
	cout << "X -- Remove cholesterol reading from existing patient\n";
	cout << "Q -- Quit program\n\n";
	cout << "Instruction: ";
}


//Function to run the code for adding a new patient to the list
void runAddInstruction(doctor& newDoc)
{
	//String to temporarily store the patients Name to be passed into the patient classs
	string tempPatientName;

	cout << "Please enter Patients last name.\n\n";
	cout << "Patient: ";

	//Sets user input as temporary patient object to be passed into the addPatient function, 
	//adding it to the vector list of doctrosPatients
	cin >> tempPatientName;
	newDoc.addPatient(tempPatientName);

	cout << endl << endl;
}

//Function called when the instruction to add a cholesterol reading to an existing patient is entered
void addCholesterolInstruction(doctor& newDoc)
{
	//Calls the doctor function to add a cholesterol reading to an existing patient
	newDoc.addCholesterolReadingToExisting();
}

//function called when the instruction to list patient data is entered
void runListInstruction(doctor& newDoc)
{
	//Calls the doctor function to print patient data 
	newDoc.printDoctorsPatients();
}

//Function called when the instruction to remove a patient is entered
void runRemoveInstruction(doctor& newDoc)
{
	//calls the doctor function to remove a patient form teh vector list doctorsPatients for this doctor
	newDoc.removePatient();
}

//Function called when the instruction to remove a cholesterol reading is entered
void removeCholesterolInstruction(doctor& newDoc)
{
	//Calls the doctor function to remove a cholesterol reading from an existing patient
	newDoc.removeCholesterolreading();
}