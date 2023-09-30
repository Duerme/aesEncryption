#include <stdio.h>
#include <string.h>

int main() {
    char inputText[100]; // Assuming a maximum input string length of 100 characters

    printf("Enter plain text: ");
    fgets(inputText, sizeof(inputText), stdin);

    // Remove the trailing newline character, if present
    size_t inputLength = strlen(inputText);
    if (inputLength > 0 && inputText[inputLength - 1] == '\n') {
        inputText[inputLength - 1] = '\0';
    }

    // Convert the plain text to a hex string
    size_t i = 0;
    printf("unsigned char Data[] = {\n\t");
    for (i = 0; i < inputLength; i++) {
        unsigned char byte = inputText[i];
        printf("0x%02X", byte); // Convert each byte to a 2-digit hex value
        if (i < inputLength - 1) {
            printf(", ");
            if ((i + 1) % 12 == 0) {
                printf("\n    ");
            }
        }
    }
    printf("\n};\n");

    return 0;
}
