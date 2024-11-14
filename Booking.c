#include <stdio.h>

#define MAX_SEATS 10  // Maximum number of available seats

// Function to display the seating chart
void displaySeats(int seats[]) {
    printf("\nAvailable Seats: \n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == 0)
            printf("Seat %d: Available\n", i + 1);
        else
            printf("Seat %d: Booked\n", i + 1);
    }
    printf("\n");
}

// Function to book tickets
int bookTickets(int seats[], int numTickets) {
    int booked = 0;
    for (int i = 0; i < MAX_SEATS && booked < numTickets; i++) {
        if (seats[i] == 0) {
            seats[i] = 1;  // Mark seat as booked
            booked++;
        }
    }
    return booked;
}

// Function to cancel tickets
int cancelTickets(int seats[], int numTickets) {
    int canceled = 0;
    for (int i = 0; i < MAX_SEATS && canceled < numTickets; i++) {
        if (seats[i] == 1) {
            seats[i] = 0;  // Mark seat as available
            canceled++;
        }
    }
    return canceled;
}

int main() {
    int seats[MAX_SEATS] = {0};  // 0 means seat is available, 1 means seat is booked
    int choice, numTickets, bookedTickets, canceledTickets;

    while (1) {
        printf("\n*** Ticket Booking System ***\n");
        printf("1. Display available seats\n");
        printf("2. Book tickets\n");
        printf("3. Cancel tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                printf("Enter the number of tickets to book: ");
                scanf("%d", &numTickets);
                if (numTickets > MAX_SEATS) {
                    printf("Sorry, we only have %d seats available.\n", MAX_SEATS);
                } else {
                    bookedTickets = bookTickets(seats, numTickets);
                    if (bookedTickets == numTickets) {
                        printf("%d ticket(s) successfully booked.\n", bookedTickets);
                    } else {
                        printf("Not enough available seats. Only %d ticket(s) booked.\n", bookedTickets);
                    }
                }
                break;
            case 3:
                printf("Enter the number of tickets to cancel: ");
                scanf("%d", &numTickets);
                canceledTickets = cancelTickets(seats, numTickets);
                if (canceledTickets == numTickets) {
                    printf("%d ticket(s) successfully canceled.\n", canceledTickets);
                } else {
                    printf("No enough booked tickets to cancel. Only %d ticket(s) canceled.\n", canceledTickets);
                }
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
