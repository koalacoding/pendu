#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prototypes.h"

int main(int argc, char *argv[])
{
    char secret_word[] = "BROWN", stared_word[100], user_char_choice; // secret_word is a debug secret word the user must find, and stared_word is a clone of secret_word of the same length, however only composed of stars (to hide the word to the player).

    f_starify_secret_word(secret_word, stared_word);

    int chances_left = 10; // Chances left before loosing the game.

    printf("Welcome on the pendu game.\n");

    printf("You have %d chances left.\n\n", chances_left);
    printf("The secret word : %s\n", stared_word);
    printf("Enter a letter : ");
    user_char_choice = f_read_char();
    printf("Your choice is : %c", user_char_choice);

    return 0;
}

char f_read_char() // A function similar to scanf without its buffer problem.
{
    char character = 0;

    character  = getchar(); // We read the first character the user enters.
    character  = toupper(character); // The letter is transformed in capital if it isn't already the case.

    while (getchar() != '\n'); // We clear the buffer.

    return character; // The first character the user entered is returned.
}

void f_starify_secret_word(char* word, char* starified_word) // Function to create a clone of the secret word only composed of stars.
{
    int length_word = 0, i = 0; // length_word will be used to store the length of the secret word (the parameter of the function), and i will be used for the for loop.

    length_word = strlen(word); // The length of the parameter of the function.

    for (i = 0; i < length_word; i++) // A for loop that put a star on every turn in the starified_word parameter.
    {
        starified_word[i] = '*';
    }

    starified_word[i] = '\0'; // We must put this character after the chain of stars to indicate that the chain is finished.
}

int f_is_letter_in_word(char* word, char letter)
{
    int length_word = 0, i = 0, var_return = 0;
    length_word = strlen(word);

    for (i = 0; i < length_word; i++)
    {
        if (word[i] == letter)
        {
            var_return = 1;
        }
    }

    return var_return;

}
