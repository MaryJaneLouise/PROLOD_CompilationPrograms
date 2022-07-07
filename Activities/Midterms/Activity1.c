#include <stdio.h>

void Activity1() {
    float num1, num2, num3, num4, num5;
    float resultAddition, resultSubtraction, resultMultiplication, resultDivision;

    printf("Hello! This is Activity 1 in C Programming.\n");
    printf("Enter 5 numbers:\n");
    scanf("%f, %f, %f, %f, %f", &num1, &num2, &num3, &num4, &num5);

    //Computation for the results
    resultAddition = num1 + num2;
    resultSubtraction = resultAddition - num3;
    resultMultiplication = resultSubtraction * num4;
    resultDivision = resultMultiplication / num5;

    //Printing the results
    printf("\nResults:\n");
    printf("%0.2f is the sum when the 1st digit and 2nd digit added.\n", resultAddition);
    printf("%0.2f is the difference when the sum of the first equation and 3rd digit subtracted.\n", resultSubtraction);
    printf("%0.2f is the product when the difference of the second equation and 4th digit multiplied.\n", resultMultiplication);

    //Checking if the 5th number entered by the user is negative or 0
    if (num5 == 0) {
        printf("Since the 5th number is %0.2f, we cannot do division because it will return null.", num5);
    }
    else {
        printf("%0.2f is the quotient when the product of the third equation and 5th digit divided.", resultDivision);
    }
}

int main() {
    Activity1();
    return 0;
}
