#ifndef FULLTIMEEMPLOYEE_H_INCLUDED
#define FULLTIMEEMPLOYEE_H_INCLUDED
#include"Employee.h"
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class FullTimeEmployee : public Employee
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

public:
    FullTimeEmployee() {}
    FullTimeEmployee(const char *name, int code, const char *designation, int exp, int age, int workingHours, char anyLoan = 'N')
        : Employee(name, code, designation, exp, age, workingHours, anyLoan)
    {
        calculateSalary();
    }
    void calculateSalary();
    void save(ofstream &file);
    void load(ifstream &file);
    void displayEmployee();
    void displayPaySlip();
};



#endif // FULLTIMEEMPLOYEE_H_INCLUDED
