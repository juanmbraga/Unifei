#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int number; 
    char letter;

    system("cls");
    printf("Type in a letter: ");
    scanf(" %c", &letter);
    number = (int) letter;
    printf("\nThe ASCII number of the letter is %d", number);

    return 0;
}