// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int create();
int login(int pass, int acc);
int menu(int acc, int deposit);
int depositFun(int acc, int deposit);
int withdraw(int acc, int deposit);
int check(int acc, int deposit);

int main() {
    // Write C code here
    int acc = 0, yon;
    printf("Welcome to ARBOB");
    printf("\nEnter account number: ");
    scanf("%d", &acc);
    if(acc != 0){
        printf("Such account doesn't exist!");
        printf("\nDo you wish to create account? (0/1): ");
        scanf("%d", &yon);
        printf("------------------------\n");
        if(yon==1){
            create();
        }else{
            printf("Thank you! Come back again!");
        }
    }
}

int create(){
    char name[100];
    printf("Enter your first name: ");
    scanf("%s", &name);
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    char prof[100];
    printf("Enter your profession: ");
    scanf("%s", &prof);
    int acc = 5555353;
    int pass;
    printf("Your account number is: %d", 5555353);
    printf("\nSet a pin for it: ");
    scanf("%d", &pass);
    int accCheck;
    printf("Your account has been created successfully!");
    printf("\n\nLogin to your account now!\n");
    printf("Enter account number: ");
    scanf("%d", &accCheck);
    if(accCheck == acc){
        login(pass,acc);
    }else{
        printf("No such account! Create first!\n");
        create();
    }
}

int login(int pass, int acc){
    int pincheck;
    printf("Enter pin: ");
    scanf("%d", &pincheck);
    if(pincheck == pass){
        printf("Logged in successfully!");
        int deposit;
        printf("\nNow enter some cash to get going: ");
        scanf("%d", &deposit);
        int ot;
        printf("Do you wish to continue banking? (0/1): ");
        scanf("%d", &ot);
        if(ot == 0){
            printf("Thank you and visit again!");
        }else if(ot == 1){
            menu(acc, deposit);    
        }else{
            printf("Wrong value!Moved out of program!");
        }
        
    }
    else{
        printf("Wrong pin!\n");
        login(pass,acc);
    }
}

int menu(int acc, int deposit){
    int opt;
    printf("Menu: \n");
    printf("1.To check balance\n2.To deposit more amount\n3.To withdraw money\n4.Exit!\n ::");
    scanf("%d", &opt);
    if(opt == 1){
        check(acc,deposit);
    }else if(opt == 2){
        depositFun(acc, deposit);
    }else if(opt == 3){
        withdraw(acc,deposit);
    }else if(opt == 4){
        printf("Thank you for banking!");
    }else{
        printf("Wrong value!");
        menu(acc,deposit);
    }
}

int depositFun(int acc, int deposit){
    int amt, ot;
    printf("------------------------\n");
    printf("Enter amount to be deposited: ");
    scanf("%d", &amt);
    deposit = deposit+amt;
    printf("Your new balance is: %d", deposit);
    printf("\nBack to menu or exit: (0/1): ");
    scanf("%d", &ot);
    if(ot == 0){
        printf("Thank you for banking!");
    }else if(ot == 1){
        menu(acc,deposit);
    }else{
        printf("Wrong input.");
        menu(acc,deposit);
    }
}

int withdraw(int acc, int deposit){
    int wd;
    printf("------------------------\n");
    printf("Enter amount to be withdrawn: ");
    scanf("%d", &wd);
    if(wd > deposit){
        printf("You don't have enough balance!");
        withdraw(acc, deposit);
    }else if(wd <= deposit){
        printf("Value withdrawn, %d", wd);
        deposit = deposit - wd;
        printf("\nYour current balance is %d\n", deposit);
        int opt;
        printf("Continue Banking? (0/1) ");
        scanf("%d", &opt);
        if(opt == 0){
            printf("Thank you!");
        }else if(opt == 1){
            menu(acc,deposit);
        }
    }else{
        printf("Wrong input!");
        menu(acc,deposit);
    }
}

int check(int acc, int deposit){
    int opt;
    printf("------------------------\n");
    printf("Your account number is: %d\n", acc);
    printf("Your balance is: %d\n", deposit);
    printf("Continue Banking? (0/1) ");
    scanf("%d", &opt);
    if(opt == 0){
        printf("Thank you!");
    }else if(opt == 1){
        menu(acc,deposit);
    }
}
