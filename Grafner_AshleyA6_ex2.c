//Ashley Grafner
//10/1/2024
//CS 2060

/* Question 2:
Initialize a string with following sentence: “Let us begin with a quick introduction in C. Our aim is
to show the essential elements of the language in real programs, but without getting bogged
down in the details, rules, and exceptions.”

Display count of:
a. vowels,
b. consonants
c. spaces, commas and periods
d. uppercase letters
e. lowercase letters
f. words and sentences

Display following using string functions:
g. Length of the string
h. Find the word with greatest length and display it
i. Find the most repeated word
j. Display all the words in reverse order
k. Display all the words in ascending order of the ASCII code of first character, if first
    character is same then 2nd character and so on
*/
#include <stdio.h>
#include <ctype.h>  // For character type functions
#include <string.h> // For string manipulation

#include <stdio.h>      // Standard input-output header
#include <string.h>     // String manipulation header
#include <ctype.h>      // Character type handling header

// Define constants for maximum word lengths
#define MAX_WORDS 100         // Maximum number of words to store
#define MAX_WORD_LENGTH 100    // Maximum length of each word

// Macros for character checks
#define IS_VOWEL(ch) (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || \
                      ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
// Checks if the character is a vowel (both uppercase and lowercase)

#define IS_CONSONANT(ch) (isalpha(ch) && !IS_VOWEL(ch))
// Checks if the character is an alphabetic consonant

#define IS_SPACE(ch) (ch == ' ')
// Checks if the character is a space

#define IS_COMMA(ch) (ch == ',')
// Checks if the character is a comma

#define IS_PERIOD(ch) (ch == '.')
// Checks if the character is a period

#define IS_END_OF_SENTENCE(ch) (ch == '.' || ch == '!' || ch == '?')
// Checks if the character is an end-of-sentence punctuation mark

// Macro to calculate the length of the string (excluding the null terminator)
#define STRING_LENGTH(s) (strlen(s))

// Macro to find the longest word in an array of words
#define FIND_LONGEST_WORD(words, count, longest) { \
    strcpy(longest, words[0]); /* Start by assuming the first word is the longest */ \
    for (int i = 1; i < count; i++) { \
        if (strlen(words[i]) > strlen(longest)) { \
            strcpy(longest, words[i]); /* Update longest if a longer word is found */ \
        } \
    } \
}

// Macro to count occurrences of words in an array of words
#define COUNT_WORD_OCCURRENCES(words, count, most_repeated, max_count) { \
    max_count = 0; /* Initialize maximum count to zero */ \
    for (int i = 0; i < count; i++) { \
        int count_current = 1; /* Count occurrences of the current word */ \
        for (int j = 0; j < count; j++) { \
            if (i != j && strcmp(words[i], words[j]) == 0) { \
                count_current++; /* Increment count if a match is found */ \
            } \
        } \
        if (count_current > max_count) { \
            max_count = count_current; /* Update max count */ \
            strcpy(most_repeated, words[i]); /* Update most repeated word */ \
        } \
    } \
}

// Macro to print words in reverse order
#define REVERSE_WORDS(words, count) { \
    printf("Words in reverse order:\n"); \
    for (int i = count - 1; i >= 0; i--) { \
        printf("%s ", words[i]); /* Print each word starting from the last */ \
    } \
    printf("\n"); \
}

// Macro to sort words in ascending order based on ASCII values
#define SORT_WORDS(words, count) { \
    for (int i = 0; i < count - 1; i++) { \
        for (int j = i + 1; j < count; j++) { \
            if (strcmp(words[i], words[j]) > 0) { \
                char temp[MAX_WORD_LENGTH]; /* Temporary variable for swapping */ \
                strcpy(temp, words[i]); /* Store the first word in temp */ \
                strcpy(words[i], words[j]); /* Swap the two words */ \
                strcpy(words[j], temp); \
            } \
        } \
    } \
}

int main() {
    // Initialize a constant string (sentence) to analyze
    const char sentence[] = "Let us begin with a quick introduction in C. Our aim is to show the essential elements of the language in real programs, but without getting bogged down in the details, rules, and exceptions.";

    // Initialize counters for various character types and word statistics
    int vowels = 0, consonants = 0, spaces = 0, commas = 0, periods = 0;
    int uppercase = 0, lowercase = 0, words = 0, sentences = 0;
    char longest_word[MAX_WORD_LENGTH] = ""; // To store the longest word found
    char most_repeated[MAX_WORD_LENGTH] = ""; // To store the most repeated word found
    int max_count = 0; // To track the maximum count of repeated words

    // Word extraction
    char words_array[MAX_WORDS][MAX_WORD_LENGTH]; // Array to store individual words
    int word_count = 0; // Counter for the number of words extracted

    // Counters for character indices
    int i = 0, j = 0; // Index for the sentence and the word storage
    while (sentence[i] != '\0') { // Loop through each character of the sentence
        char ch = sentence[i]; // Current character

        // Count characters based on defined macros
        if (IS_VOWEL(ch)) {
            vowels++; // Increment vowel count
        } else if (IS_CONSONANT(ch)) {
            consonants++; // Increment consonant count
        } else if (IS_SPACE(ch)) {
            spaces++; // Increment space count
        } else if (IS_COMMA(ch)) {
            commas++; // Increment comma count
        } else if (IS_PERIOD(ch)) {
            periods++; // Increment period count
            sentences++; // Increment sentence count for a period
        }

        // Check for end-of-sentence characters
        if (IS_END_OF_SENTENCE(ch) && !IS_PERIOD(ch)) {
            sentences++; // Increment sentence count for any end-of-sentence character (except period)
        }

        // Count uppercase and lowercase letters
        if (isupper(ch)) {
            uppercase++; // Increment uppercase letter count
        } else if (islower(ch)) {
            lowercase++; // Increment lowercase letter count
        }

        // Extract words from the sentence
        if (IS_SPACE(ch) || IS_COMMA(ch) || IS_PERIOD(ch) || IS_END_OF_SENTENCE(ch)) {
            // End of a word detected
            if (j > 0) {
                words_array[word_count][j] = '\0'; // Null-terminate the current word
                word_count++; // Increment the word count
                j = 0; // Reset index for the next word
            }
        } else {
            // Add character to the current word if not full
            if (j < MAX_WORD_LENGTH - 1) { // Prevent overflow
                words_array[word_count][j++] = ch; // Store character and increment index
            }
        }
        i++; // Move to the next character in the sentence
    }

    // Check if the last word was counted
    if (j > 0) {
        words_array[word_count][j] = '\0'; // Null-terminate the last word
        word_count++; // Increment the word count
    }

    // Find the longest word in the extracted words
    FIND_LONGEST_WORD(words_array, word_count, longest_word);

    // Count occurrences of words to find the most repeated word
    COUNT_WORD_OCCURRENCES(words_array, word_count, most_repeated, max_count);

    // Display the results of the analysis
    printf("Count of vowels: %d\n", vowels);
    printf("Count of consonants: %d\n", consonants);
    printf("Count of spaces: %d\n", spaces);
    printf("Count of commas: %d\n", commas);
    printf("Count of periods: %d\n", periods);
    printf("Count of uppercase letters: %d\n", uppercase);
    printf("Count of lowercase letters: %d\n", lowercase);
    printf("Count of words: %d\n", word_count);
    printf("Count of sentences: %d\n", sentences);
    printf("Length of the string: %lu\n", STRING_LENGTH(sentence)); // Length of the original sentence
    printf("Longest word: %s\n", longest_word);
    printf("Most repeated word: %s (occurrences: %d)\n", most_repeated, max_count);

    // Reverse the order of the words and display
    REVERSE_WORDS(words_array, word_count);

    // Sort the words in ascending order and display
    SORT_WORDS(words_array, word_count);
    printf("Words in ascending order:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s ", words_array[i]); // Print each sorted word
    }
    printf("\n"); // Newline for clarity

    return 0; // Indicate successful completion of the program
}
