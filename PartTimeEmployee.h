#ifndef PARTTIMEEMPLOYEE_H_INCLUDED
#define PARTTIMEEMPLOYEE_H_INCLUDED
#include<iostream>
#include<string.h>
#include<fstream>
#include"Employee.h"
using namespace std;

class PartTimeEmployee : public Employee
{
private:
    int salary = 0;
    int HRA = 0;
    int PF = 0;
    int tax = 0;
    int mealAllowance = 0;
    int transportAllowance = 0;
    int medicalAllowance = 0;
    int loanBalance = 0;
    int loanDebit = 0;
    int grossPay = 0;
    int DA = 0;
    int hourlyRate=0;
public:
    PartTimeEmployee() {}
    PartTimeEmployee(const char *name, int code, const char *designation, int exp, int age, int workingHours, int hourlyRate, char anyLoan = 'N')
        : Employee(name, code, designation, exp, age, workingHours, anyLoan), hourlyRate(hourlyRate)
    {
        calculateSalary();
    }
    void calculateSalary();
    void save(ofstream &file);
    void load(ifstream &file);
    void displayEmployee();
    void displayPaySlip();
};

#endif // PARTTIMEEMPLOYEE_H_INCLUDED
