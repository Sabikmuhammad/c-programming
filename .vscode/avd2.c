#include <stdio.h>
#include <string.h>

// Define the maximum number of expenses and users
#define MAX_EXPENSES 100
#define MAX_USERS 10

// Structure to store an expense
struct Expense {
    char description[50];
    float amount;
};

// Structure to store user information
struct User {
    char name[50];
    float budget;
    int expenseCount;
    struct Expense expenses[MAX_EXPENSES];  // Static array of expenses
};

// Function prototypes
void registerUser(struct User users[], int *userCount);
void setBudget(struct User *user);
void addExpense(struct User *user);
void viewReport(struct User *user);

int main() {
    struct User users[MAX_USERS];  // Array of users
    int userCount = 0;
    int choice;

    printf("Welcome to the Finance Management System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Register a new user\n");
        printf("2. Set Budget\n");
        printf("3. Add Expense\n");
        printf("4. View Financial Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 && userCount < MAX_USERS) {
            registerUser(users, &userCount);
        } else if (choice == 2 && userCount > 0) {
            setBudget(&users[userCount - 1]);
        } else if (choice == 3 && userCount > 0) {
            addExpense(&users[userCount - 1]);
        } else if (choice == 4 && userCount > 0) {
            viewReport(&users[userCount - 1]);
        } else if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice or no users available.\n");
        }
    }

    return 0;
}

// Function to register a new user
void registerUser(struct User users[], int *userCount) {
    printf("Enter your name: ");
    scanf("%s", users[*userCount].name);
    users[*userCount].budget = 0.0;
    users[*userCount].expenseCount = 0;
    (*userCount)++;
    printf("User registered successfully!\n");
}

// Function to set the budget for a user
void setBudget(struct User *user) {
    printf("Enter your monthly budget: ");
    scanf("%f", &user->budget);
    printf("Budget set to %.2f.\n", user->budget);
}

// Function to add an expense for a user
void addExpense(struct User *user) {
    if (user->expenseCount < MAX_EXPENSES) {
        printf("Enter expense description: ");
        scanf("%s", user->expenses[user->expenseCount].description);
        printf("Enter expense amount: ");
        scanf("%f", &user->expenses[user->expenseCount].amount);
        user->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}

// Function to view the financial report for a user
void viewReport(struct User *user) {
    printf("Financial Report for %s\n", user->name);
    printf("Budget: %.2f\n", user->budget);
    float totalSpent = 0.0;
    for (int i = 0; i < user->expenseCount; i++) {
        printf("Expense: %s | Amount: %.2f\n", user->expenses[i].description, user->expenses[i].amount);
        totalSpent += user->expenses[i].amount;
    }
    printf("Total Spent: %.2f\n", totalSpent);
    printf("Remaining Balance: %.2f\n", user->budget - totalSpent);
}
