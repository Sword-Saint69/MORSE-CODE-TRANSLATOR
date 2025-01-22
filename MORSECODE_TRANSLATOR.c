#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct morse_code {
    char character;
    const char *code;
};

struct morse_code morse_table[] = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
    {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
    {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
    {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
    {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},  {'0', "-----"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {' ', "/"}
};


void text_to_morse(const char *text);
void morse_to_text(const char *morse);

int main() {
    int choice;
    char input[256];

    printf("Morse Code Converter\n");
    printf("1. Text to Morse\n");
    printf("2. Morse to Text\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (choice == 1) {
        text_to_morse(input);
    } else if (choice == 2) {
        morse_to_text(input);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

void text_to_morse(const char *text) {
    for (int i = 0; text[i]; i++) {
        char c = toupper(text[i]);
        int found = 0;
        
        for (size_t j = 0; j < sizeof(morse_table)/sizeof(morse_table[0]); j++) {
            if (morse_table[j].character == c) {
                printf("%s ", morse_table[j].code);
                found = 1;
                break;
            }
        }
        
        if (!found) printf("? ");
    }
    printf("\n");
}

void morse_to_text(const char *morse) {
    char *token;
    char copy[256];
    strcpy(copy, morse);

    token = strtok(copy, " ");
    while (token != NULL) {
        int found = 0;
        
        for (size_t j = 0; j < sizeof(morse_table)/sizeof(morse_table[0]); j++) {
            if (strcmp(token, morse_table[j].code) == 0) {
                putchar(morse_table[j].character);
                found = 1;
                break;
            }
        }
        
        if (!found) putchar('?');
        token = strtok(NULL, " ");
    }
    printf("\n");
}
