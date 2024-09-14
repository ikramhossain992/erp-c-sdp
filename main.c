
#include "erp.h"

int main()
{
    int choice;

    printf("_______________ Welcome to ERP Management System _______________\n\n");
    printf("1. LOGIN AS ADMIN \n");
    printf("2. LOGIN AS Employee\n");
    printf("3. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n\n");

    switch (choice)
    {
    case 1:
        if (adminLogin())
        {
            adminPanel();
        }
        else
        {
            printf("Email or password is wrong. Exiting...\n");
        }
        break;
    case 2:

        if (employeeLogin())
        {
            employeePanel();
        }
        else
        {
            printf("Email or password is wrong. Exiting...\n");
        }

        break;
    case 3:
        printf("Exiting...\n");
        break;
    default:
        printf("Invalid choice. Please try again.\n");
    }

    return 0;
}
