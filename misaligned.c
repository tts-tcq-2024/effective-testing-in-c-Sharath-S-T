#include <stdio.h>
#include <assert.h>
#include <string.h>

// Mocking the expected output
const char* expectedOutput[25] = {
    "0 | White | Blue\n",
    "1 | White | Orange\n",
    "2 | White | Green\n",
    "3 | White | Brown\n",
    "4 | White | Slate\n",
    "5 | Red | Blue\n",
    "6 | Red | Orange\n",
    "7 | Red | Green\n",
    "8 | Red | Brown\n",
    "9 | Red | Slate\n",
    "10 | Black | Blue\n",
    "11 | Black | Orange\n",
    "12 | Black | Green\n",
    "13 | Black | Brown\n",
    "14 | Black | Slate\n",
    "15 | Yellow | Blue\n",
    "16 | Yellow | Orange\n",
    "17 | Yellow | Green\n",
    "18 | Yellow | Brown\n",
    "19 | Yellow | Slate\n",
    "20 | Violet | Blue\n",
    "21 | Violet | Orange\n",
    "22 | Violet | Green\n",
    "23 | Violet | Brown\n",
    "24 | Violet | Slate\n"
};

void checkOutput(const char* printedOutput) {
    int i = 0;
    char buffer[50];
    char* outputPtr = (char*)printedOutput;

    for (i = 0; i < 25; i++) {
        sscanf(outputPtr, "%[^\n]\n", buffer);
        outputPtr += strlen(buffer) + 1;

        // Compare the expected output
        assert(strcmp(buffer, expectedOutput[i]) == 0 && "Output does not match the expected combination");
    }
}

int printColorMap(char* printedOutput) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    char buffer[100] = {0};
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            sprintf(buffer, "%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            strcat(printedOutput, buffer);
        }
    }
    return i * j;
}

int main() {
    char printedOutput[2000] = {0};    
    int result = printColorMap(printedOutput);
    assert(result == 25);
    checkOutput(printedOutput);  // This will validate the correctness of the output
    printf("All is well (maybe!)\n");
    return 0;
}
