char f_read_char(); 

// Function like scanf without its buffer problem.

void f_starify_secret_word(char* word, char* starified_word); 

// Function to replace the secret word by a word of stars of the same length.

int f_is_letter_in_word(char* word, char* word_to_unstarify, char letter, int* number_of_finds); 

/* Function that checks if letter the user chose is in the word. It also
   modifies the stared word to show the found letters and it adds to the
   fourth parameter (number_of_finds) the number of letters found. */