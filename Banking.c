#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account *acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    getchar(); // to consume the newline character left by previous scanf
    fgets(acc->name, 50, stdin);
    acc->name[strcspn(acc->name, "\n")] = '\0'; // Remove newline character from input
    acc->balance = 0.0;
    printf("Account created successfully!\n");
}

void deposit(struct Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Amount deposited successfully! Current balance: %.2f\n", acc->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(struct Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Amount withdrawn successfully! Current balance: %.2f\n", acc->balance);
    } else if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

void checkBalance(struct Account *acc) {
    printf("Account Holder: %s\n", acc->name);
    printf("Account Number: %d\n", acc->accountNumber);
    printf("Current Balance: %.2f\n", acc->balance);
}

int main() {
    struct Account myAccount;
    int choice;

    while (1) {
        // Menu display
        printf("\n--- Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&myAccount);
                break;
            case 2:
                deposit(&myAccount);
                break;
            case 3:
                withdraw(&myAccount);
                break;
            case 4:
                checkBalance(&myAccount);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
