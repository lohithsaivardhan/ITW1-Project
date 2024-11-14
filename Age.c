#include <stdio.h>

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear = 2024, currentMonth = 11, currentDay = 14; // Set today's date

    // Get user's birth date
    printf("Enter your birth year (e.g., 2000): ");
    scanf("%d", &birthYear);

    printf("Enter your birth month (1-12): ");
    scanf("%d", &birthMonth);

    printf("Enter your birth day (1-31): ");
    scanf("%d", &birthDay);

    // Calculate age
    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDay;

    // Adjust for negative month or day differences
    if (ageDays < 0) {
        ageMonths--;
        ageDays += 30; // Assuming average 30 days per month
    }

    if (ageMonths < 0) {
        ageYears--;
        ageMonths += 12;
    }

    // Output the result
    printf("Your age is: %d years, %d months, and %d days.\n", ageYears, ageMonths, ageDays);

    return 0;
}
