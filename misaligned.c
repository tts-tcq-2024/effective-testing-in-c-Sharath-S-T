#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;

    // Loop to print the color combinations
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }

    return i * j;  // Return the total number of entries
}

int main() {
    int result = printColorMap();
    
    // Check that 25 entries are printed
    assert(result == 25);
    printf("All is well (maybe!)\n");

    return 0;
}
