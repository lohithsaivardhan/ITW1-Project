#include <stdio.h>
#include <stdlib.h>

struct Booking {
    int seatNumber;
    char *personName;
    int personAge;
    char *gender;
    char *phoneNo;
    int ticketPrice;
    int showTiming;
    struct Booking* next;
    struct Booking* prev;
};

struct Stack {
    struct Booking* top;
};

struct Node {
    int seatNumber;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Booking* createBooking(int seatNumber, char *personName, int personAge, char *gender, char *phoneNo, int ticketPrice, int showTiming);
struct Stack* createStack();
struct Node* createNode(int seatNumber);
struct Queue* createQueue();
void push(struct Stack* stack, int seatNumber, char *personName, int personAge, char *gender, char *phoneNo, int ticketPrice, int showTiming);
int pop(struct Stack* stack);
void enqueue(struct Queue* queue, int seatNumber);
int dequeue(struct Queue* queue);
void displayBookedSeats(struct Stack* stack);
void displayAvailableSeats(struct Queue* queue);
void displayMovieDetails();
void displayShowTimings();
int selectShowTiming();
void displaySeatCategories();
int calculateTicketPrice(int seatCategory);

struct Booking* createBooking(int seatNumber, char *personName, int personAge, char *gender, char *phoneNo, int ticketPrice, int showTiming) {
    struct Booking* newBooking = (struct Booking*)malloc(sizeof(struct Booking));
    newBooking->seatNumber = seatNumber;
    newBooking->personName = personName;
    newBooking->personAge = personAge;
    newBooking->gender = gender;
    newBooking->phoneNo = phoneNo;
    newBooking->ticketPrice = ticketPrice;
    newBooking->showTiming = showTiming;
    newBooking->next = NULL;
    newBooking->prev = NULL;
    return newBooking;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

struct Node* createNode(int seatNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->seatNumber = seatNumber;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void push(struct Stack* stack, int seatNumber, char *personName, int personAge, char *gender, char *phoneNo, int ticketPrice, int showTiming) {
    struct Booking* newBooking = createBooking(seatNumber, personName, personAge, gender, phoneNo, ticketPrice, showTiming);
    if (stack->top == NULL) {
        stack->top = newBooking;
    } else {
        newBooking->next = stack->top;
        stack->top->prev = newBooking;
        stack->top = newBooking;
    }
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        int seatNumber = stack->top->seatNumber;
        struct Booking* temp = stack->top;
        stack->top = stack->top->next;
        if (stack->top != NULL)
            stack->top->prev = NULL;
        free(temp);
        return seatNumber;
    }
}

void enqueue(struct Queue* queue, int seatNumber) {
    struct Node* newNode = createNode(seatNumber);
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int seatNumber = queue->front->seatNumber;
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL)
            queue->rear = NULL;
        free(temp);
        return seatNumber;
    }
}

void displayBookedSeats(struct Stack* stack) {
    struct Booking* temp = stack->top;
    printf("Booked seats: \n");
    while (temp != NULL) {
        printf("Seat Number: %d, Person Name: %s, Person Age: %d, Gender: %s, Phone No: %s, Ticket Price: %d, Show Timing: %d\n", 
               temp->seatNumber, temp->personName, temp->personAge, temp->gender, temp->phoneNo, temp->ticketPrice, temp->showTiming);
        temp = temp->next;
    }
    printf("\n");
}

void displayAvailableSeats(struct Queue* queue) {
    struct Node* temp = queue->front;
    printf("Available seats: ");
    while (temp != NULL) {
        printf("%d ", temp->seatNumber);
        temp = temp->next;
    }
    printf("\n");
}

void displayMovieDetails() {
    printf("Movie: Avengers: Endgame\n");
    printf("Director: Anthony Russo, Joe Russo\n");
    printf("Genre: Action, Adventure, Sci-Fi\n");
}

void displayShowTimings() {
    printf("Show Timings:\n");
    printf("1. 09:00 AM\n");
    printf("2. 12:00 PM\n");
    printf("3. 03:00 PM\n");
    printf("4. 06:00 PM\n");
}

int selectShowTiming() {
    int choice;
    printf("Select show timing (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void displaySeatCategories() {
    printf("Seat Categories:\n");
    printf("1. Gold (Rs. 300)\n");
    printf("2. Silver (Rs. 200)\n");
    printf("3. Bronze (Rs. 100)\n");
}

int calculateTicketPrice(int seatCategory) {
    switch (seatCategory) {
        case 1:
            return 300;
        case 2:
            return 200;
        case 3:
            return 100;
        default:
            return 0;
    }
}

int main() {
    struct Stack* bookedSeats = createStack();
    struct Queue* availableSeats = createQueue();

    for (int i = 1; i <= 10; i++) {
        enqueue(availableSeats, i);
    }

    int choice;
    int running = 1;
    while (running) {
        printf("\nMenu:\n");
        printf("1. Book a seat\n");
        printf("2. Cancel last booking\n");
        printf("3. View booked seats\n");
        printf("4. View available seats\n");
        printf("5. View movie details\n");
        printf("6. View show timings\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (availableSeats->front == NULL) {
                    printf("No available seats.\n");
                } else {
                    char personName[50], gender[10], phoneNo[15];
                    int personAge;
                    displaySeatCategories();
                    int seatCategory;
                    printf("Select seat category (1-3): ");
                    scanf("%d", &seatCategory);
                    int ticketPrice = calculateTicketPrice(seatCategory);
                    printf("Enter your name: ");
                    scanf("%s", personName);
                    printf("Enter your age: ");
                    scanf("%d", &personAge);
                    printf("Enter your gender (Male/Female/Others): ");
                    scanf("%s", gender);
                    printf("Enter your phone number: ");
                    scanf("%s", phoneNo);
                    displayShowTimings();
                    int showTiming = selectShowTiming();
                    int seatNumber = dequeue(availableSeats);
                    push(bookedSeats, seatNumber, personName, personAge, gender, phoneNo, ticketPrice, showTiming);
                    printf("Seat %d booked successfully by %s (Age: %d, Gender: %s, Phone No: %s). Ticket Price: Rs. %d, Show Timing: %d\n", 
                           seatNumber, personName, personAge, gender, phoneNo, ticketPrice, showTiming);
                }
                break;
            case 2:
                if (bookedSeats->top == NULL) {
                    printf("No bookings to cancel.\n");
                } else {
                    int seatNumber = pop(bookedSeats);
                    enqueue(availableSeats, seatNumber);
                    printf("Booking for seat %d canceled.\n", seatNumber);
                }
                break;
            case 3:
                displayBookedSeats(bookedSeats);
                break;
            case 4:
                displayAvailableSeats(availableSeats);
                break;
            case 5:
                displayMovieDetails();
                break;
            case 6:
                displayShowTimings();
                break;
            case 7:
                running = 0;
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    while (bookedSeats->top != NULL) {
        pop(bookedSeats);
    }
    free(bookedSeats);
    while (availableSeats->front != NULL) {
        dequeue(availableSeats);
    }
    free(availableSeats);

    return 0;
}
