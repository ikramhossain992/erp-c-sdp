// admin.c
#include "erp.h"

int adminLogin() {
    char userEmail[50], password[50];
    char line[MAX_LINE_LENGTH];
    char storedName[50], storedUserEmail[50], storedPassword[50];
    int storedId;

    printf("Enter Admin Email: ");
    scanf("%s", userEmail);
    printf("Enter Admin Password: ");
    scanf("%s", password);

    FILE *file = fopen("user_admin.csv", "r");
    if (file == NULL) {
        printf("Unable to open users file.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "id:%d, name:%49[^,], email:%49[^,], password:%49s", &storedId, storedName, storedUserEmail, storedPassword) == 4) {
            if (strcmp(userEmail, storedUserEmail) == 0 && strcmp(password, storedPassword) == 0) {
                fclose(file);
                return 1; // Login successful
            }
        }
    }

    fclose(file);
    return 0; // Login failed
}

void adminPanel() {
    int choice;
    do {
        printf("\n______________ERP Management System  - Admin Panel______________\n\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Calculate Payroll\n");
        printf("4. Generate and Send Salary Report\n");
        printf("5. Add Admin\n");
        printf("6. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            viewEmployees();
            break;
        case 3:
            calculatePayroll();
            break;
        case 4:
            generateSalaryReport();
            break;
        case 5:
            addAdminFun();
            break;
        case 6:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

int getNextAdminID() {
    int id, maxID = 0;
    FILE *file = fopen("user_admin.csv", "r");

    if (file) {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
            if (sscanf(line, "id:%d,", &id) == 1) {
                if (id > maxID) {
                    maxID = id;
                }
            }
        }
        fclose(file);
    }

    return maxID + 1;
}

void addAdminFun() {
    FILE *file = fopen("user_admin.csv", "a"); // Open file in append mode
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    Admin adm;
    adm.id = getNextAdminID(); // Generate a unique ID
    printf("Generated Admin ID: %d\n", adm.id);
    printf("Enter Admin Name: ");
    scanf(" %[^\n]s", adm.name); // To read string with spaces
    printf("Enter Admin Email: ");
    scanf("%s", adm.email);
    printf("Enter Admin Password: ");
    scanf("%s", adm.password); // Password as a string

    fprintf(file, "id:%d, name:%s, email:%s, password:%s\n", adm.id, adm.name, adm.email, adm.password);
    fclose(file);

    printf("Admin added successfully!\n");
}
