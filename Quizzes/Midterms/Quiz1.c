#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 1) Consonant or Vowel?
void VowelOrConsonant() {
    char alphabet[128];

    printf("\nChecking if each letter is a vowel or consonant\n");
    printf("Enter the letters: ");
    fgets(alphabet, sizeof(alphabet), stdin); // Read the input as a string

    // Replace spaces and tabs with newlines
    for (int i = 0; i < strlen(alphabet); i++) {
        if (alphabet[i] == ' ' || alphabet[i] == '\t') {
            alphabet[i] = '\n';
        }
    }

    //Checking if the input is a letter or not
    printf("\nResult:\n");
    for (int i = 0; i < strlen(alphabet); i++) {
        if (alphabet[i] == '\n') {
            printf("\n");
            continue;
        }
        if ((alphabet[i] >= 'a' && alphabet[i] <= 'z') || (alphabet[i] >= 'A' && alphabet[i] <= 'Z')) {
            if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u' ||
                alphabet[i] == 'A' || alphabet[i] == 'E' || alphabet[i] == 'I' || alphabet[i] == 'O' || alphabet[i] == 'U') {
                printf("'%c' is a vowel.\n", alphabet[i]);
            }
            else {
                printf("'%c' is a consonant.\n", alphabet[i]);
            }
        }
        else if (alphabet[i] >= '0' && alphabet[i] <= '9') {
            printf("'%c' is a number.\n", alphabet[i]);
        }
        else {
            printf("'%c' is a symbol.\n", alphabet[i]);
        }
    }
}


// 2) Basic Calculations
// This is a function that will process the calculations
void calculateNumbers(int option, int num1, int num2) {
    float result = 0;

    switch (option) {
        case 1:
            // Addition
            result = num1 + num2;
            printf("\nThe sum of %d and %d is %0.2f.\n", num1, num2, result);
            break;
        case 2:
            // Subtraction
            result = num1 - num2;
            printf("\nThe difference of %d and %d is %0.2f.\n", num1, num2, result);
            break;
        case 3:
            // Multiplication
            result = num1 * num2;
            printf("\nThe product of %d and %d is %0.2f.\n", num1, num2, result);
            break;
        case 4:
            // Division
            result = (float)num1 / num2;
            if (num2 != 0) {
                printf("\nThe quotient of %d and %d is %0.2f.\n", num1, num2, result);
            }
            else {
                printf("\nYou cannot divide a number by zero (%d / %d = undefined).\n", num1, num2);
            }
            break;
        default:
            printf("\nYou entered wrong number (%d). Please try again.", option);
    }
}

// This is a function that will validate the inputs
int getValidNumber(const char *prompt) {
    int number;
    char input[100];

    while (1) {
        printf("%s", prompt);
        fgets(input, sizeof(input), stdin);

        // Check if input is valid number
        char *end;
        number = strtol(input, &end, 10);
        if (end != input && *end == '\n') {
            break; // valid number
        } else {
            printf("Invalid input. Please enter a valid number.\n");
        }
    }

    return number;
}

// This is a function that will show the options and the results for the calculations
void displayCalculations() {
    int option, num1, num2;

    printf("\nBasic Calculations\n");

    // Check if the entered number is a number and not a letter or symbol
    num1 = getValidNumber("1st number: ");
    num2 = getValidNumber("2nd number: ");

    printf("\nChoose an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    calculateNumbers(option, num1, num2);
}

// 3) Right Triangle Pattern with a number increased by 1
void rightTriangleNumbersIncreasedByOne() {
    int i, j, rows;
    int printedNumbers = 1;

    printf("\nRight Triangle Pattern with a number increased by 1\n");
    rows = getValidNumber("Enter the number of rows: ");

    // This looping statement will print the numbers in triangular form
    // The first loop will be printing the nextline
    // The second loop will be printing the numbers
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d\t", printedNumbers++);
        }
        printf("\n");
    }
}


// 4) Sum of the series 1 +11 + 111 + 1111 + .. n terms
void sumSeriesOneTerms() {
    int i, number;
    long sum = 0;
    long int series = 1;

    printf("\nSum of the series 1 +11 + 111 + 1111 + .. n terms\n");
    number = getValidNumber("Enter the limit for the 1 series: ");

    if (number > 0) {
        // Loop to generate and sum the series
        for(i = 1; i <= number; i++) {
            // This will print the numbers
            printf("%ld  ", series);

            // This will print the + symbol between the numbers
            if (i < number) {
                printf("+ ");
            }

            sum = sum + series;
            series = (series * 10) + 1;
        }

        // Printing of the sum
        printf("= %ld", sum);
        printf("\nThe sum for this series is %ld.\n", sum);
    }
    else {
        printf("\nYou cannot print an empty number. Please try again.\n");
    }
}

// Main Program that will run the
int main() {
    int choice;

    while (1) {
        printf("Menu:\n");
        printf("1. Check Vowels or Consonants\n");
        printf("2. Basic Calculations\n");
        printf("3. Right Triangle Pattern with a number increased by 1\n");
        printf("4. Sum of the series 1 +11 + 111 + 1111 + .. n terms\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                VowelOrConsonant();
                break;
            case 2:
                displayCalculations();
                break;
            case 3:
                rightTriangleNumbersIncreasedByOne();
                break;
            case 4:
                sumSeriesOneTerms();
                break;
            case 5:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}