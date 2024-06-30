#include <stdio.h>

void Activity1() {
    float num1, num2, num3, num4, num5;
    float resultAddition, resultSubtraction, resultMultiplication, resultDivision;

    printf("Showcase of basic computations (add, subtract, multiply, divide)\n");
    printf("Enter 5 numbers:\n");
    scanf("%f, %f, %f, %f, %f", &num1, &num2, &num3, &num4, &num5);

    //Computation for the results
    resultAddition = num1 + num2;
    resultSubtraction = resultAddition - num3;
    resultMultiplication = resultSubtraction * num4;
    resultDivision = resultMultiplication / num5;

    //Printing the results
    printf("\nResults:\n");
    printf("%0.2f is the sum when first digit (%0.2f) and second digit (%0.2f) added.\n", resultAddition, num1, num2);
    printf("%0.2f is the difference when the sum of the first equation (%0.2f) and 3rd digit (%0.2f) subtracted.\n", resultSubtraction, resultAddition, num3);
    printf("%0.2f is the product when the difference of the second equation (%0.2f) and 4th digit (%0.2f) multiplied.\n", resultMultiplication, resultSubtraction, num4);

    //Checking if the 5th number entered by the user is negative or 0
    if (num5 == 0) {
        printf("Since the 5th number is %0.2f, the program cannot do division because it will return null.", num5);
    }
    else {
        printf("%0.2f is the quotient when the product of the third equation (%0.2f) and 5th digit (%0.2f) divided.", resultDivision, resultMultiplication, num5);
    }
}

int main() {
    Activity1();
    return 0;
}
