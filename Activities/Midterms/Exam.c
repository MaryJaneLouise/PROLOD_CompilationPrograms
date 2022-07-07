#include <stdio.h>
#include <math.h>

//PROGGRAMMING (20 pts. each)
//1) Write a program in C to find the sum of the series 1!/1+2!/2+3!/3+4!/4+5!/5 using the function.
//This one is little tricky but once you got the formula, it will be easy
//We will be using arrays here since the digits needs to be repeatedly solved
void SumSeriesFormula(int limitEquation) {
    //The sum should be started in 0 so that the value will be reset
    //There is no factorial starting 0 so we will make the value of it as 1
    int temporaryNumber;
    float summationFactorial = 0;
    float factorial = 1;

    //Solving and printing the solution
    //We will be using for loop in order to solve the equation repeatedly
    printf("\n");
    for (temporaryNumber = 1; temporaryNumber <= limitEquation; temporaryNumber++) {
        printf("%d!/%d", temporaryNumber, temporaryNumber);

        //Writing the formula for the factorial and division at the same time then solving for the summation
        factorial = factorial * temporaryNumber;
        summationFactorial = summationFactorial + (factorial / temporaryNumber);

        //Comparing the temporaryNumber and limitEquation for the + and = signs
        if (temporaryNumber < limitEquation) {
            printf(" + ");
        }
        else {
            printf(" = %0.2f", summationFactorial);
        }
    }

    //Printing the sum
    printf("\n\nThe sum of the series is %0.2f.", summationFactorial);
}

void FactorialEquation() {
    int limitEquation;
    printf("Sum of the series n!/n\n");
    printf("Enter the limit for the equation:\n");
    scanf("%d", &limitEquation);

    if (limitEquation == 0) {
        printf("There will be no sum since 0!/0 is undefined.");
    }
    else if (limitEquation > 0 && limitEquation <= 19) {
        printf("\nThe series of %d, starting from 1!/1 to %d!/%d, is:", limitEquation, limitEquation, limitEquation);
        SumSeriesFormula(limitEquation);
    }
    else if (limitEquation >= 20) {
        printf("\nThe series of %d, starting from 1!/1 to %d!/%d, is:", limitEquation, limitEquation, limitEquation);
        SumSeriesFormula(limitEquation);

        //There is a bug wherein it will print less than the expected value
        printf("\nStarting from n = 20, you may get inaccurate results due to the double-floating-point precision error.");
    }
    else {
        printf("Negative numbers do not have factorials. Try again.");
    }
}

//2) Write a program in C that will convert decimal number enter by the user to its equivalent binary number using the function.
//Converting decimal number(e.g. 1) is very tricky whenever you do not know how to convert them in the first place
void BinarySummary(int numberConvert) {
    int temporaryNumber1, temporaryNumber2;

    //We will be using for loop in order to print 0 and 1
    //The limit for temporaryNumber1 is 31 since we are getting only the binary
    //">>" means Bitwise Right shift operator
    for (temporaryNumber1 = 31; temporaryNumber1 >= 0; temporaryNumber1--) {
        temporaryNumber2 = numberConvert >> temporaryNumber1;

        //Yes, you can do this as long as there will be only one command for the requirement for ifs
        if (temporaryNumber2 & 1)
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void BinarySolution(int numberConvert) {
    //This function has been researched and clean-up in order to see how the system solves the binary
    int temporaryNumber, remainderBinary, resultBinary;

    printf("\n");
    if (numberConvert > 0) {
        for (;numberConvert > 0;) {
            remainderBinary = numberConvert % 2;
            printf("%d/2 ---> the remainder is '%d' & the quotient is '%d'\n", numberConvert, remainderBinary, (numberConvert  / 2));

            //Formula for the solution
            numberConvert = numberConvert / 2;
            resultBinary = resultBinary + (remainderBinary * temporaryNumber);
            temporaryNumber = temporaryNumber * 10;
        }
    }
    else if (numberConvert == 0) {
        printf("%d/2 ---> the remainder is '%d' & the quotient is '%d'\n", numberConvert, numberConvert, (numberConvert  / 2));
    }
}

void BinaryFinalForm() {
    int numberConvert;
    printf("Conversion from decimal to binary\n");
    printf("Enter the number to convert:\n");
    scanf("%d", &numberConvert);
    printf("\n");

    //Writing the results
    if (numberConvert >= 0) {
        printf("%d in binary number system is:\n", numberConvert);

        //Calling the function for the summarized form of binary
        BinarySummary(numberConvert);

        //Calling the function for the result for binary
        printf("\nSolution:");
        BinarySolution(numberConvert);
    }
    else {
        printf("Unfortunately, this program cannot solve for negative numbers. Please try again and use positive integers.");
    }
}

int main() {
    char answer;

    printf("Hello! What do you want to do here?\n");
    printf("Select an option:\n"
           "1 - Swapping Values\n"
           "2 - Check the digit if it is an even or odd\n");
    printf("Answer:");
    scanf("%s", answer);

    if (answer == "1") {
        printf("\n");
        FactorialEquation();
        return 0;
    }
    else if (answer == "2") {
        printf("\n");
        BinaryFinalForm();
        return 0;
    }
    else {
        printf("\nHuh, okay. I guess you need to restart the program in order to load again the programs.");
        return 0;
    }
}