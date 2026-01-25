#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3

struct Account {
    int accNo;
    char name[50];
    int pin;
    float balance;
};

void createAccount();
void deposit();
void withdraw();
void balanceEnquiry();
void displayAccount();

int main() {
    int choice;

    do {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Create New Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Enquiry\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: balanceEnquiry(); break;
            case 5: displayAccount(); break;
            case 6: printf("Thank you for using the banking system.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

void createAccount() {
    FILE *fp;
    struct Account acc, temp;
    int exists = 0;

    fp = fopen("bank.dat", "ab+");
    if (fp == NULL) {
        printf("File error.\n");
        return;
    }

    printf("Enter New Account Number: ");
    scanf("%d", &acc.accNo);

    rewind(fp);
    while (fread(&temp, sizeof(temp), 1, fp)) {
        if (temp.accNo == acc.accNo) {
            exists = 1;
            break;
        }
    }

    if (exists) {
        printf("Account already exists.\n");
        fclose(fp);
        return;
    }

    printf("Enter Account Holder Name: ");
    scanf(" %49[^\n]", acc.name);

    printf("Set 4-digit PIN: ");
    scanf("%d", &acc.pin);

    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(acc), 1, fp);
    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

void deposit() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid amount.\n");
                fclose(fp);
                return;
            }

            acc.balance += amount;
            fseek(fp, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, fp);
            printf("Amount deposited successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found.\n");

    fclose(fp);
}

void withdraw() {
    FILE *fp;
    struct Account acc;
    int accNo, pin;
    float amount;

    fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Enter PIN: ");
            scanf("%d", &pin);

            if (pin != acc.pin) {
                printf("Incorrect PIN.\n");
                fclose(fp);
                return;
            }

            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);

            if (amount <= 0 || amount > acc.balance) {
                printf("Invalid or insufficient balance.\n");
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, fp);
                printf("Withdrawal successful.\n");
            }
            fclose(fp);
            return;
        }
    }

    printf("Account not found.\n");
    fclose(fp);
}

void balanceEnquiry() {
    FILE *fp;
    struct Account acc;
    int accNo, pin;

    fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo && acc.pin == pin) {
            printf("\nBalance: %.2f\n", acc.balance);
            fclose(fp);
            return;
        }
    }

    printf("Invalid account number or PIN.\n");
    fclose(fp);
}

void displayAccount() {
    FILE *fp;
    struct Account acc;
    int accNo, pin;

    fp = fopen("bank.dat", "rb");
    if (fp == NULL) {
        printf("No accounts found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    printf("Enter PIN: ");
    scanf("%d", &pin);

    while (fread(&acc, sizeof(acc), 1, fp)) {
        if (acc.accNo == accNo && acc.pin == pin) {
            printf("\n----- ACCOUNT DETAILS -----\n");
            printf("Account Number : %d\n", acc.accNo);
            printf("Name           : %s\n", acc.name);
            printf("Balance        : %.2f\n", acc.balance);
            fclose(fp);
            return;
        }
    }

    printf("Invalid account number or PIN.\n");
    fclose(fp);
}
