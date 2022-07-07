#include <stdio.h>

void VowelOrConsonant() {
    char alphabet;

    printf("Checking the letter is vowel or consonant\n");
    printf("Enter the letter: ");
    scanf("%c", &alphabet);

    //Checking if the input is a letter or not
    printf("\nResult:\n");
    if ((alphabet >= 'a' && alphabet <= 'z') || (alphabet >= 'A' && alphabet <= 'Z')) {
        if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u' ||
        alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U') {
            printf("%c is a vowel.", alphabet);
        }
        else {
            printf("%c is a consonant.", alphabet);
        }
    }
    else {
        printf("Not valid. Try again with a letter, not with a number or symbols.");
    }
}

int main() {
    VowelOrConsonant();
    return 0;
}