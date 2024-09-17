#include<iostream>
#include<fstream>
#include<iomanip>
#include"PartTimeEmployee.h"
using namespace std;
void PartTimeEmployee::calculateSalary()
{
    salary = workingHours * hourlyRate;
    DA = 1.20 * salary;
    tax = 0.04 * salary;
    PF = 0.12 * salary;
    HRA = salary * 0.27;
    mealAllowance = 300;
    medicalAllowance = 300;
    transportAllowance = 300;
    loanDebit = salary * 0.09;

    if (anyLoan == 'Y' || anyLoan == 'y')
    {
        loanBalance = salary * 2;
        if (loanDebit > loanBalance)
        {
            loanBalance = 0;
            loanDebit = loanBalance;
        }
    }
    else
    {
        loanBalance = 0;
        loanDebit = 0;
    }

    grossPay = (salary + mealAllowance + medicalAllowance +
                transportAllowance + HRA + DA) -
               (PF + tax + loanDebit);
}
void PartTimeEmployee::displayEmployee()
{
    cout << "-----------------------------------------------------" << endl;
    cout << "|                  Employee Payslip                 |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| Name:             " << setw(30) << left << name << "  |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| Working Hours:    " << setw(27) << right << workingHours << " Hrs |" << endl;
    cout << "| Hourly Wage:      " << setw(28) << right << hourlyRate << ".RS |"<<endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| Earnings:                                         |" << endl;
    cout << "|   Basic Pay:            " << setw(25) << right << salary << " |" << endl;
    cout << "|   HRA(27% of Basic):    " << setw(25) << right << HRA << " |" << endl;
    cout << "|   DA (120% of Basic):   " << setw(25) << right << DA << " |" << endl;
    cout << "|   Meal Allowance:       " << setw(25) << right << mealAllowance << " |" << endl;
    cout << "|   Medical Allowance:    " << setw(25) << right << medicalAllowance << " |" << endl;
    cout << "|   Transport Allowance:  " << setw(25) << right << transportAllowance << " |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| Deductions:                                       |" << endl;
    cout << "|   PF:                  " << setw(26) << right << PF << " |" << endl;
    cout << "|   Tax:                 " << setw(26) << right << tax << " |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| Loan Status:           " << setw(26) << right << (char)toupper(anyLoan) << " |" << endl;
    cout << "| Loan Debit This Month: " << setw(26) << right << loanDebit << " |" << endl;
    cout << "| Loan Balance:          " << setw(26) << right << loanBalance << " |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| Total Gross Pay:       " << setw(26) << right << grossPay << " |" << endl;
    cout << "-----------------------------------------------------" << endl;
}
void PartTimeEmployee::displayPaySlip()
{
    cout << setw(15) << name << setw(8) << code << setw(25) << designation << setw(12) << exp << setw(5) << age << setw(14) << hourlyRate<< setw(8) << fixed << setprecision(2) << grossPay << endl;
}
void PartTimeEmployee::save(ofstream &file)
{
    file.write((char *)(this), sizeof(PartTimeEmployee));
}

void PartTimeEmployee::load(ifstream &file)
{
    file.read((char *)(this), sizeof(PartTimeEmployee));
}
