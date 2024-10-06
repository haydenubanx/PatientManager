# Doctor-Patient Management System

## Overview

This project is a **Doctor-Patient Management System** designed to allow doctors to manage patient information and track cholesterol readings. The system allows for adding new patients, recording and managing cholesterol readings, and removing patients or cholesterol readings from the database.

## Features

- **Add Patients**: Doctors can add new patients by entering their name.
- **Manage Cholesterol Readings**: Doctors can add cholesterol readings for existing patients and remove specific readings.
- **List Patients**: Doctors can list all current patients along with their cholesterol data.
- **Remove Patients**: Doctors can remove patients from their list.
- **Error Handling**: The program includes input validation for handling incorrect inputs.

## Getting Started

### Prerequisites

To run this project, you'll need:

- A C++ compiler (e.g., g++, clang++).
- A terminal or command line environment to compile and run the program.

### Compiling the Project

To compile the project, run the following command:

```bash
g++ -o doctorPatientManager PatientDriver.cpp Doctor.cpp Patient.cpp -I
```

### Running the Program
```bash
./doctorPatientManager
```

## Usage

Upon running the program, you will be presented with the following options:

- `A`: Add a new patient.
- `C`: Add a cholesterol reading for an existing patient.
- `L`: List all patients and their cholesterol readings.
- `R`: Remove a patient from the list.
- `X`: Remove a cholesterol reading from an existing patient.
- `Q`: Quit the program.

### Example Workflow

1. **Adding a Patient**: Choose option `A` and enter the patient's last name.
2. **Adding a Cholesterol Reading**: Choose option `C`, select the patient from the list, and input the cholesterol reading.
3. **Listing Patients**: Choose option `L` to view all patients and their cholesterol data.
4. **Removing a Patient**: Choose option `R`, and select the patient to be removed.
5. **Removing a Cholesterol Reading**: Choose option `X`, select the patient, and remove a specific reading.

## Code Structure

- **`Doctor.cpp` and `Doctor.h`**: Handles the management of patients, adding/removing cholesterol readings, and patient-related data.
- **`Patient.cpp` and `Patient.h`**: Manages individual patient information, including storing cholesterol levels.
- **`PatientDriver.cpp`**: The main driver of the program where user interaction occurs.

## Error Handling

The program performs input validation to ensure that:
- Numeric inputs, such as cholesterol readings, are valid.
- Patients are selected correctly based on the options provided.

If an invalid input is entered, the program will prompt the user to try again.

## Future Improvements

- **Additional Health Data**: Add functionality for managing other health metrics (e.g., blood pressure, heart rate).
- **Search Functionality**: Implement a search function to find patients more efficiently.
- **Export Data**: Enable exporting patient data to a file for future reference.

## License

This project is open source under the MIT License. See the [LICENSE](LICENSE) file for more details.