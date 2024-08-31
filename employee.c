// employee.c
#include "erp.h"

void addEmployee() {
    addEmployeeFun();
}

void viewEmployees() {
    FILE *file = fopen("employees.csv", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    printf("Employee Records:\n");
    printf("ID, Name, Email, Salary\n");

    Employee emp;
    while (fscanf(file, "%d,%49[^,],%49[^,],%f", &emp.id, emp.name, emp.email, &emp.salary) == 4) {
        printf("%d, %s, %s, %.2f\n", emp.id, emp.name, emp.email, emp.salary);
    }

    fclose(file);
}

void calculatePayroll() {
    printf("Calculate Payroll Functionality\n");
}

void generateSalaryReport() {
    printf("Generate and Send Salary Report Functionality\n");
}

int getNextEmployeeID() {
    int id, maxID = 0;
    FILE *file = fopen("employees.csv", "r");

    if (file) {
        while (fscanf(file, "%d,%*[^,],%*[^,],%*f", &id) == 1) {
            if (id > maxID) {
                maxID = id;
            }
        }
        fclose(file);
    }

    return maxID + 1;
}

void addEmployeeFun() {
    FILE *file = fopen("employees.csv", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    Employee emp;
    emp.id = getNextEmployeeID(); // Generate a unique ID
    printf("Generated Employee ID: %d\n", emp.id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", emp.name); // To read string with spaces
    printf("Enter Employee Email: ");
    scanf("%s", emp.email);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    fprintf(file, "%d,%s,%s,%.2f\n", emp.id, emp.name, emp.email, emp.salary);
    fclose(file);

    printf("Employee added successfully!\n");
}
