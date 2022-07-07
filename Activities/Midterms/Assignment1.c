#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1) Design a function-oriented program that emphasize the use of call by value.
//This is called a function. This contains other operations that can be used by the main program
//This will be elaborated once you have reached Object-Oriented Programming
void SwapNumbers(int numberFirst, int numberSecond, int numberTemp) {
    //This is called swapping the two values within two variables
    //numberTemp gets the first number then making the value of numberFirst be the second one
    //Then, the numberSecond will have the value of the numberTemp, which contains the first number
    numberTemp = numberFirst;
    numberFirst = numberSecond;
    numberSecond = numberTemp;

    //Printing the values after the swap happened
    printf("\nAfter swap:\n");
    printf("%d, %d", numberFirst, numberSecond);
}

void CallingValuesFromAFunction() {
    int numberFirst, numberSecond, numberTemp;

    printf("Call by Value // Swapping two numbers using a function\n");
    printf("Enter any two numbers:\n");
    scanf("%d %d", &numberFirst, &numberSecond);

    printf("\nBefore swap:\n");
    printf("%d, %d\n", numberFirst, numberSecond);

    //Passing the values to the user-made function
    SwapNumbers(numberFirst, numberSecond, numberTemp);
}

//2) Write a program in C to check a given number is even or odd using a function.
//Again, since the requirement is having a function in checking even or odd, there will be user-made function
void EvenOddCheck(int number) {
    //We will use modulo in getting the remainder of the said number by using 2s
    //If it equals to 0, it will be even
    //If it will be equals to other value, it will be odd
    printf("\nResults:");
    if (number % 2 == 0) {
        printf("\n%d = even", number);
    }
    else {
        printf("\n%d = odd", number);
    }
}

void EvenOrOdd() {
    int number;

    printf("Even or Odd Digit Check\n");
    printf("Enter any number:\n");
    scanf("%d", &number);

    //Passing the number to the said function
    EvenOddCheck(number);
}

//3) Write a program in C to find the sum of the series 1!/1+2!/2+3!/3+4!/4+5!/5 using the function.
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

//4) Write a program in C to convert decimal number to binary number using the function.
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
           "2 - Check the digit if it is an even or odd\n"
           "3 - Factorial Equation (1!/1)\n"
           "4 - Decimal to Binary Conversion\n");
    printf("Answer:");
    scanf("%s", answer);

    if (answer == "1") {
        printf("\n");
        CallingValuesFromAFunction();
        return 0;
    }
    else if (answer == "2") {
        printf("\n");
        EvenOrOdd();
        return 0;
    }
    else if (answer == "3") {
        printf("\n");
        FactorialEquation();
        return 0;
    }
    else if (answer == "4") {
        printf("\n");
        BinaryFinalForm();
        return 0;
    }
    else {
        printf("\nAre you blind or something?");
        return 0;
    }
}