#include <stdio.h>

void Activity2() {
    int number;
    int numThousands, numHundreds, numTens, numOnes;

    //Creating a dummy number for boolean expression to fix some errors
    int booleanNumber = 0;

    printf("Converting number into words\n");
    printf("Enter number from 0 to 9999: ");
    scanf("%d", &number);

    if (number > 9999 || number < 0) {
        printf("Can you not read the instructions? It says the maximum number is 9999 and minimum number is 0. Rerun the program.");
    }
    else {
        //Using formula in order to get individual values
        //This is the way in getting the module operator or rather the remainder after dividing things
        numThousands = number / 1000;
        numHundreds = (number % 1000) / 100;
        numTens = (number % 100) / 10;
        numOnes = number % 10;

        //Switch cases are used in different situations
        //Like this one, it will identify which word it will print
        printf("\nResult:\n%d = ", number);
        switch (numThousands) {
            case 1: printf("one thousand "); break;
            case 2: printf("two thousand "); break;
            case 3: printf("three thousand "); break;
            case 4: printf("four thousand "); break;
            case 5: printf("five thousand "); break;
            case 6: printf("six thousand "); break;
            case 7: printf("seven thousand "); break;
            case 8: printf("eight thousand "); break;
            case 9: printf("nine thousand "); break;
        }

        switch (numHundreds) {
            case 1: printf("one hundred "); break;
            case 2: printf("two hundred "); break;
            case 3: printf("three hundred "); break;
            case 4: printf("four hundred "); break;
            case 5: printf("five hundred "); break;
            case 6: printf("six hundred "); break;
            case 7: printf("seven hundred "); break;
            case 8: printf("eight hundred "); break;
            case 9: printf("nine hundred "); break;
        }

        switch (numTens) {
            case 1:
                //Activating the boolean number in order this switch case be true and be printed
                booleanNumber = 1;
                switch (numOnes) {
                    case 0: printf("ten"); break;
                    case 1: printf("eleven"); break;
                    case 2: printf("twelve"); break;
                    case 3: printf("thirteen"); break;
                    case 4: printf("fourteen"); break;
                    case 5: printf("fifteen"); break;
                    case 6: printf("sixteen"); break;
                    case 7: printf("seventeen"); break;
                    case 8: printf("eighteen"); break;
                    case 9: printf("nineteen"); break;
                } break;

            case 2: printf("twenty "); break;
            case 3: printf("thirty "); break;
            case 4: printf("forty "); break;
            case 5: printf("fifty "); break;
            case 6: printf("sixty "); break;
            case 7: printf("seventy "); break;
            case 8: printf("eighty "); break;
            case 9: printf("ninety "); break;
        }

        //If the value of dummy number has not been changed
        if (booleanNumber == 0) {
            switch (numOnes) {
                case 1:printf("one"); break;
                case 2:printf("two"); break;
                case 3:printf("three"); break;
                case 4:printf("four"); break;
                case 5:printf("five"); break;
                case 6:printf("six"); break;
                case 7:printf("seven"); break;
                case 8:printf("eight"); break;
                case 9:printf("nine"); break;
            }

            //Checking all the position of the numbers are 0
            if (numThousands == 0 && numHundreds == 0 && numTens == 0) {
                printf("zero");
            }
        }
    }
}

int main() {
    Activity2();
    return 0;
}