
#include "erp.h"

int main() {
    int choice;

    printf("_______________Welcome to ERP Management System _______________\n\n");
    printf("1. LOGIN AS ADMIN \n");
    printf("2. LOGIN AS Employee\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        if (adminLogin()) {
            adminPanel();
        } else {
            printf("Login failed. Exiting...\n");
        }
        break;
    case 2:
        printf("Employee login is not yet implemented.\n");
        break;
    case 3:
        printf("Exiting...\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
