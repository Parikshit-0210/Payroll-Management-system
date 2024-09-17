#include<iostream>
#include<iomanip>
#include<fstream>
#include"FullTimeEmployee.h"
#include"PartTimeEmployee.h"
#include"PayrollSystem.h"
void PayrollSystem::addFullTimeEmployee(const FullTimeEmployee &employee)
{
    if (numFullTimeEmployees < MAX_EMPLOYEES)
    {
        fullTimeEmployees[numFullTimeEmployees++] = employee;
    }
    else
    {
        cout << "Maximum number of full-time employees reached!" << endl;
    }
}
void PayrollSystem::addPartTimeEmployee(const PartTimeEmployee &employee)
{
    if (numPartTimeEmployees < MAX_EMPLOYEES)
    {
        partTimeEmployees[numPartTimeEmployees++] = employee;
    }
    else
    {
        cout << "Maximum number of part-time employees reached!" << endl;
    }
}
void PayrollSystem::listFullTimeEmployees()
{
    cout << left << setw(15) << "Name" << setw(8) << "Code" << setw(25) << "Designation" << setw(12) << "Years(EXP)" << setw(5) << "Age" << setw(8) << "Salary" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i < numFullTimeEmployees; ++i)
    {
        fullTimeEmployees[i].displayPaySlip();
    }
}

void PayrollSystem::listPartTimeEmployees()
    {
        cout << left << setw(15) << "Name" << setw(8) << "Code" << setw(25) << "Designation" << setw(12) << "Years(EXP)" << setw(5) << "Age" << setw(14) << "Hourly rate" << setw(8) << "Salary" << endl;
        cout << "--------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < numPartTimeEmployees; ++i)
        {
            partTimeEmployees[i].displayPaySlip();
        }
    }

void PayrollSystem::deleteEmployee(int code)
{
    bool found = false;
    for (int i = 0; i < numFullTimeEmployees; ++i)
    {
        if (fullTimeEmployees[i].getCode() == code)
        {
            for (int j = i; j < numFullTimeEmployees - 1; ++j)
            {
                fullTimeEmployees[j] = fullTimeEmployees[j + 1];
            }
            numFullTimeEmployees--;
            found = true;
            break;
        }
    }

    if (!found)
    {
        for (int i = 0; i < numPartTimeEmployees; ++i)
        {
            if (partTimeEmployees[i].getCode() == code)
            {
                for (int j = i; j < numPartTimeEmployees - 1; ++j)
                {
                    partTimeEmployees[j] = partTimeEmployees[j + 1];
                }
                numPartTimeEmployees--;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "Employee with code " << code << " not found!" << endl;
    }
    else
    {
        cout << "Employee with code " << code << " deleted successfully!" << endl;
    }
}

void PayrollSystem::saveEmployees(const char *fullTimeFileName, const char *partTimeFileName)
{
    ofstream fullTimeFile(fullTimeFileName, ios::binary);
    ofstream partTimeFile(partTimeFileName, ios::binary);

    if (!fullTimeFile.is_open() || !partTimeFile.is_open())
    {
        cout << "Error opening files for writing!" << endl;
        return;
    }

    for (int i = 0; i < numFullTimeEmployees; ++i)
    {
        fullTimeFile.write((char *)(&fullTimeEmployees[i]), sizeof(FullTimeEmployee));
    }

    for (int i = 0; i < numPartTimeEmployees; ++i)
    {
        partTimeFile.write((char *)(&partTimeEmployees[i]), sizeof(PartTimeEmployee));
    }

    fullTimeFile.close();
    partTimeFile.close();
}


void PayrollSystem::loadEmployees(const char *fullTimeFileName, const char *partTimeFileName)
{
    ifstream fullTimeFile(fullTimeFileName, ios::binary);
    ifstream partTimeFile(partTimeFileName, ios::binary);

    if (!fullTimeFile.is_open() || !partTimeFile.is_open())
    {
        cout << "Error opening files for reading!" << endl;
        return;
    }

    // Read FullTimeEmployees one by one
    int fullTimeIndex = 0;
    while (fullTimeIndex < MAX_EMPLOYEES && fullTimeFile.read((char *)(&fullTimeEmployees[fullTimeIndex]), sizeof(FullTimeEmployee))) {

        fullTimeIndex++;
    }

    // Read PartTimeEmployees one by one
    int partTimeIndex = 0;
    while (partTimeIndex < MAX_EMPLOYEES && partTimeFile.read((char *)(&partTimeEmployees[partTimeIndex]), sizeof(PartTimeEmployee))) {
        partTimeIndex++;
    }
    numFullTimeEmployees = fullTimeIndex;
    numPartTimeEmployees = partTimeIndex;
    fullTimeFile.close();
    partTimeFile.close();
}
void PayrollSystem::updateEmployee(int code)
{
    bool found = false;
    for (int i = 0; i < numFullTimeEmployees; ++i)
    {
        if (fullTimeEmployees[i].getCode() == code)
        {
            // Update employee details
            char name[100];
            char designation[100];
            int code, exp, age, workingHours;
            char anyLoan;
            cout << "Enter name: ";
            cin.getline(name, sizeof(name));
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

            fullTimeEmployees[i] = FullTimeEmployee(name, fullTimeEmployees[i].getCode(), designation, exp, age, workingHours, anyLoan);
            cout << "Employee with code " << fullTimeEmployees[i].getCode() << " updated successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        for (int i = 0; i < numPartTimeEmployees; ++i)
        {
            if (partTimeEmployees[i].getCode() == code)
            {
                // Update employee details
                char name[100];
                char designation[100];
                int code, exp, age, workingHours, hourlyRate;
                char anyLoan;
                cout << "Enter name: ";
                cin.getline(name, sizeof(name));
                cout << "Enter designation: ";
                cin.getline(designation, sizeof(designation));
                cout << "Enter experience: ";
                cin >> exp;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter working hours: ";
                cin >> workingHours;
                cout << "Enter hourly rate: ";
                cin >> hourlyRate;
                cout << "Any loan? (Y/N): ";
                cin >> anyLoan;

                partTimeEmployees[i] = PartTimeEmployee(name, partTimeEmployees[i].getCode(), designation, exp, age, workingHours,hourlyRate,anyLoan);
                cout << "Employee with code " << partTimeEmployees[i].getCode() << " updated successfully!" << endl;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "Employee with code " << code << " not found!" << endl;
    }
}
void PayrollSystem::searchEmployee(int code)
{
    bool found = false;
    for (int i = 0; i < numFullTimeEmployees; ++i)
    {
        if (fullTimeEmployees[i].getCode() == code)
        {
            cout << "Full-Time Employee Found:" << endl;
            cout << left << setw(15) << "Name" << setw(8) << "Code" << setw(25) << "Designation" << setw(12) << "Years(EXP)" << setw(5) << "Age" << setw(8) << "Salary" << endl;
            cout << "------------------------------------------------------------------------" << endl;
            fullTimeEmployees[i].displayPaySlip();
            found = true;
            break;
        }
    }

    if (!found)
    {
        for (int i = 0; i < numPartTimeEmployees; ++i)
        {
            if (partTimeEmployees[i].getCode() == code)
            {
                cout << "Part-Time Employee Found:" << endl;
                cout << left << setw(15) << "Name" << setw(8) << "Code" << setw(25) << "Designation" << setw(12) << "Years(EXP)" << setw(5) << "Age" << setw(14) << "Hourly rate" << setw(8) << "Salary" << endl;
                cout << "--------------------------------------------------------------------------------------" << endl;
                partTimeEmployees[i].displayPaySlip();
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "Employee with code " << code << " not found!" << endl;
    }
}
void PayrollSystem::displayPayslip(int code)
{
    bool found = false;
    for (int i = 0; i < numFullTimeEmployees; ++i)
    {
        if (fullTimeEmployees[i].getCode() == code)
        {
            fullTimeEmployees[i].displayEmployee();
            found = true;
            break;
        }
    }

    if (!found)
    {
        for (int i = 0; i < numPartTimeEmployees; ++i)
        {
            if (partTimeEmployees[i].getCode() == code)
            {
                partTimeEmployees[i].displayEmployee();
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "Employee with code " << code << " not found!" << endl;
    }
}
