#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h> // We will use this for random numbers.
#include "prototypes.h"

int main(int argc, char *argv[]) {

    /* -----------------------------------------
    --------------------------------------------
    -Picking a random word from words_list.txt.-
    --------------------------------------------
    ------------------------------------------*/

    FILE* my_file = NULL;
    char parsing_string[100] = "";
    // We will use this string to count the number of words the words_list.txt file contains.
    int number_of_lines = 0;
    // This variable will contain the number of lines words_list.txt has.
    my_file = fopen("words_list.txt", "r");

    if (my_file != NULL) {
        while (fgets(parsing_string, 100, my_file) != NULL) {
        // We use fgets to read each line of the file.
                number_of_lines++;
        }
    }

    srand(time(NULL));

    int random_number = 0;
    random_number = (rand() % number_of_lines) + 1;
    // We pick a random number to choose a word randomly.

    rewind(my_file); // We start back at the beginning of the list of words.

    int i = 0;
    char secret_word[100] = "";

    while (i < random_number) {
        fgets(secret_word, 100, my_file);
        i++;
    }

    fclose(my_file);

    int word_length = 0;
    word_length = strlen(secret_word);
    secret_word[word_length - 1] = '\0'; // Deleting the /n at the end of the word.

    /*------------------------------------------
    --------------------------------------------
    ---Picking a random word is now finished.---
    --------------------------------------------
    ------------------------------------------*/

    char stared_word[100], user_char_choice; // secret_word is a debug secret word the user must find, and stared_word is a clone of secret_word of the same length, however only composed of stars (to hide the word to the player).

    f_starify_secret_word(secret_word, stared_word);

    int chances_left = 10; // Chances left before loosing the game.
    int letters_found = 0;
    int exit_code = 1;

    int test = 0;
    test = strlen(secret_word);

    printf("Welcome on the pendu game.\n");

    while (chances_left > -1) {
        printf("You have %d chances left.\n\n", chances_left);
        printf("The secret word : %s\n", stared_word);
        printf("Enter a letter : ");
        user_char_choice = f_read_char();

        if (f_is_letter_in_word(secret_word, stared_word, user_char_choice, &letters_found) == 1) {
            printf("Congratulations, the secret word contains this letter.\n");
        // display the letter
        }

        else {
            printf("The secret word doesn't contain this letter.\n");
            chances_left--;
        }

        // check if all are known
        if (letters_found == strlen(secret_word)) {
            printf("You win. The secret word was : %s.\n", secret_word);
            exit_code = 0;
            break;
        }

        if (chances_left == -1) {
            printf("You loose.");
            break;
        }
    }
    return exit_code;
}


/*--------------------------------
----------------------------------
------------Functions-------------
----------------------------------
--------------------------------*/

char f_read_char() { // A function similar to scanf without its buffer problem.
    char character = 0;

    character  = getchar(); // We read the first character the user enters.
    character  = toupper(character); // The letter is transformed in capital if it isn't already the case.

    while (getchar() != '\n'); // We clear the buffer.

    return character; // The first character the user entered is returned.
}

void f_starify_secret_word(char* word, char* starified_word) { // Function to create a clone of the secret word only composed of stars.
    int length_word = 0, i = 0; // length_word will be used to store the length of the secret word (the parameter of the function), and i will be used for the for loop.

    length_word = strlen(word); // The length of the parameter of the function.

    for (i = 0; i < length_word; i++) // A for loop that put a star on every turn in the starified_word parameter.
    {
        starified_word[i] = '*';
    }

    starified_word[i] = '\0'; // We must put this character after the chain of stars to indicate that the chain is finished.
}

int f_is_letter_in_word(char* word, char* word_to_unstarify, char letter, int* number_of_finds) {

/* This function checks if letter the user chose is in the word. It also
   modifies the stared word to show the found letters and it adds to the
   fourth parameter (number_of_finds) the number of letters found. */

    int length_word = 0, i = 0;
    length_word = strlen(word);

    for (i = 0; i < length_word; i++)
    {
        if (word[i] == letter)
        {
            word_to_unstarify[i] = letter;
            (*number_of_finds)++;
        }
    }

    if (*number_of_finds > 0) {
        return 1;
    }

    else {
        return 0;
    }
}
