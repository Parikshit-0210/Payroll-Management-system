#include <iostream>
#include <fstream>
#include<limits>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<stdexcept>
#include"FullTimeEmployee.h"
#include"PartTimeEmployee.h"
#include"PayrollSystem.h"
using namespace std;

void displayMenu();
void handleMenu();
void login();
int main()
{
    int enter;
    cout << "PAYROLL - MANAGEMENT - SYSTEM" << endl;
    cout << "Welcomes You...!" << endl;
    do {
        cout << "1.Login\n2.Exit\nEnter your choice: ";
        string input;
        cin >> input;
        cin.ignore();
        try {
            enter = stoi(input);  // Convert input to integer
        }
        catch (const invalid_argument& e) {
            cout << "Invalid input. Please enter an integer." << endl;
            enter = -1;  // Set choice to an invalid value
        }

        if (enter >= 1 && enter <= 2) {
            switch (enter) {
            case 1:
                login();
                break;
            case 2:
                cout << "Exiting program...\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (enter != 2);

    return 0;
}
void displayMenu() {
    cout << "\nPayroll System Menu\n";
    cout << "1. Add Employee\n";
    cout << "2. List Employees\n";
    cout << "3. Delete Employee\n";
    cout << "4. Update Employee\n";
    cout << "5. Save Records\n";
    cout << "6. Load Records\n";
    cout << "7. Search Employee\n";
    cout << "8. Print Employee PaySlip\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}
void login() {
    string username;
    char Password[20], ch;
    int i = 0;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    while (1)
    {
        ch = getch();
        if (ch == 13)
            break;
        if (ch == 32 || ch == 9)
            continue;
        else if (ch == 8) {
            if (i > 0) {
                i--;
                cout<<"\b \b";
            }
        }
        else
        {
            cout << "*";
            Password[i] = ch;
            i++;
        }
    }
    Password[i] = '\0';
    cout << endl;
    if (username == "admin" && strcmp(Password, "payroll") == 0) {
        cout<<"Login success...!\n";
        handleMenu();
    }
    else {
        cout << "Invalid username or password!\n";
        return;
    }
}

void handleMenu() {
    PayrollSystem payrollSystem;
    int choice;
    do {
        displayMenu();
        string input;
        cin >> input;
        cin.ignore();
        try {
            choice = stoi(input);  // Convert input to integer
        }
        catch (const invalid_argument& e) {
            cout << "Invalid input. Please enter an integer." << endl;
            choice = -1;  // Set choice to an invalid value
        }

        if (choice >= 1 && choice <= 9) {  // Check if choice is within valid range
            switch (choice) {
                case 1: {
                    char name[100];
                    char designation[100];
                    int code, exp, age, workingHours;
                    char anyLoan;
                    cout << "Enter name: ";
                    cin.getline(name, sizeof(name));
                    cout << "Enter code: ";
                    cin >> code;
                    cin.ignore();
                    cout << "Enter designation: ";
                    cin.getline(designation, sizeof(designation));
                    cout << "Enter experience: ";
                    cin >> exp;
                    cout << "Enter age: ";
                    cin >> age;
                    cout << "Enter working hours: ";
                    cin >> workingHours;
                    cout << "Any loan? (Y/N): ";
                    cin >> anyLoan;
                    cin.ignore();

                    cout << "Enter Employee Type (1 for Full-Time, 2 for Part-Time): ";
                    int type;
                    cin >> type;
                    cin.ignore();

                    if (type == 1) {
                        // Assuming the function to add a full-time employee is correctly implemented
                        payrollSystem.addFullTimeEmployee(FullTimeEmployee(name, code, designation, exp, age, workingHours, anyLoan));
                    } else if (type == 2) {
                        int hourlyRate;
                        cout << "Enter Employee Hourly Rate: ";
                        cin >> hourlyRate;
                        cin.ignore();
                        payrollSystem.addPartTimeEmployee(PartTimeEmployee(name, code, designation, exp, age, workingHours, hourlyRate, anyLoan));
                    } else {
                        cout << "Invalid Employee Type!";
                        continue;
                    }

                    cout << "Employee added successfully!" << endl;
                    break;
                }
                case 2: {
                    int option;
                    cout << "1. Full-Time Employee\n"
                         << "2. Part-Time Employee\n"
                         << "Enter your choice: ";
                    cin >> option;
                    cin.ignore();  // Clear buffer after reading an integer

                    if (option == 1) {
                        payrollSystem.listFullTimeEmployees();
                    } else if (option == 2) {
                        payrollSystem.listPartTimeEmployees();
                    } else {
                        cout << "Invalid option!" << endl;
                    }
                    break;
                }
                case 3: {
                    int codeToDelete;
                    cout << "Enter Employee Code to delete: ";
                    cin >> codeToDelete;
                    cin.ignore();
                    payrollSystem.deleteEmployee(codeToDelete);
                    break;
                }
                case 4: {
                    int codeToUpdate;
                    cout << "Enter Employee Code to update: ";
                    cin >> codeToUpdate;
                    cin.ignore();
                    payrollSystem.updateEmployee(codeToUpdate);
                    break;
                }
                case 5:
                    payrollSystem.saveEmployees("FullTimeEmployees.dat", "PartTimeEmployees.dat");
                    cout << "Records saved successfully!" << endl;
                    break;
                case 6:
                    payrollSystem.loadEmployees("FullTimeEmployees.dat", "PartTimeEmployees.dat");
                    cout << "Records loaded successfully!" << endl;
                    break;
                case 7:
                    int code;
                    cout<<"Enter the code to search the Employee: ";
                    cin>>code;
                    payrollSystem.searchEmployee(code);
                    break;
                case 8:
                    int codeToPrint;
                    cout<<"Enter the code to display the Pay Slip of Employee: ";
                    cin>>codeToPrint;
                    payrollSystem.displayPayslip(codeToPrint);
                    break;
                case 9:
                    cout << "Exiting program...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 9);
}

