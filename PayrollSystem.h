#ifndef PAYROLLSYSTEM_H_INCLUDED
#define PAYROLLSYSTEM_H_INCLUDED
#include<fstream>

class PayrollSystem
{
private:
    static const int MAX_EMPLOYEES = 100;
    FullTimeEmployee fullTimeEmployees[MAX_EMPLOYEES];
    PartTimeEmployee partTimeEmployees[MAX_EMPLOYEES];
    int numFullTimeEmployees;
    int numPartTimeEmployees;

public:
    PayrollSystem() : numFullTimeEmployees(0), numPartTimeEmployees(0) {}
    void addFullTimeEmployee(const FullTimeEmployee &employee);
    void addPartTimeEmployee(const PartTimeEmployee &employee);
    void listFullTimeEmployees();
    void listPartTimeEmployees();
    void deleteEmployee(int code);
    void saveEmployees(const char *fullTimeFileName, const char *partTimeFileName);
    void loadEmployees(const char *fullTimeFileName, const char *partTimeFileName);
    void updateEmployee(int code);
    void searchEmployee(int code);
    void displayPayslip(int code);

};
#endif // PAYROLLSYSTEM_H_INCLUDED
