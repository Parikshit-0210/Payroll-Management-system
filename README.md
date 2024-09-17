# Payroll Management System

## Overview

The Payroll Management System is a C++ application designed to handle the payroll tasks of a small to medium-sized business. It allows for the management of both full-time and part-time employees, including functionalities for adding, listing, deleting, updating employees, and generating pay slips. This project serves as an educational example for file handling, user authentication, and basic employee management.

## Features

- **User Authentication**: Simple username and password authentication to access the system.
- **Employee Management**:
  - Add Full-Time and Part-Time Employees.
  - List Full-Time and Part-Time Employees.
  - Delete and Update Employee Records.
  - Search for Employees by Code.
  - Generate and Print Employee Pay Slips.
- **File Handling**:
  - Save and Load employee records to and from binary files.


## Usage

1. **Login**

   - The application starts with a login prompt.
   - Default credentials:
     - Username: `admin`
     - Password: `payroll`

2. **Menu Options**

   After logging in, you will be presented with the following options:

   - **Add Employee**: Add a new full-time or part-time employee.
   - **List Employees**: List all employees by type.
   - **Delete Employee**: Remove an employee record by code.
   - **Update Employee**: Modify an employee’s details by code.
   - **Save Records**: Save current employee records to files.
   - **Load Records**: Load employee records from files.
   - **Search Employee**: Search for an employee by code.
   - **Print Employee PaySlip**: Generate and print a pay slip for an employee.
   - **Exit**: Close the application.

## File Structure

- `main.cpp`: Contains the main program logic and menu handling.
- `FullTimeEmployee.h` / `FullTimeEmployee.cpp`: Defines and implements the full-time employee class.
- `PartTimeEmployee.h` / `PartTimeEmployee.cpp`: Defines and implements the part-time employee class.
- `PayrollSystem.h` / `PayrollSystem.cpp`: Manages employee records and related operations.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or feedback, please reach out to [parikshitvel0210@gmail.com](mailto:parikshitvel0210@gmail.com).

---
