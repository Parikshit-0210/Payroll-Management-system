#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class Employee
{
protected:
    char name[100];
    int code;
    char designation[100];
    int exp;
    int age;
    int workingHours;
    char anyLoan;

public:
    Employee() {}
    Employee(const char *name, int code, const char *designation, int exp, int age, int workingHours, char anyLoan = 'N')
        : code(code), exp(exp), age(age), workingHours(workingHours), anyLoan(anyLoan)
    {
        strcpy(this->name, name);
        strcpy(this->designation, designation);
    }

    virtual void calculateSalary() = 0;
    virtual void save(ofstream &file) = 0;
    virtual void load(ifstream &file) = 0;

    int getCode() const { return code; }
    const char *getName() const { return name; }
};


#endif // EMPLOYEE_H_INCLUDED
