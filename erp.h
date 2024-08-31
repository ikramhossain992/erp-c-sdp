// erp.h
#ifndef ERP_H
#define ERP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Define Employee Structure
typedef struct {
    int id;
    char name[50];
    char email[50];
    float salary;
} Employee;

// Define Admin Structure
typedef struct {
    int id;
    char name[50];
    char email[50];
    char password[30];
} Admin;

// Function Declarations
int adminLogin();
void adminPanel();
void addEmployee();
void viewEmployees();
void calculatePayroll();
void generateSalaryReport();
void addEmployeeFun();
int getNextEmployeeID();
int getNextAdminID();
void addAdminFun();

#endif // ERP_H
