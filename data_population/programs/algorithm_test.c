#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// Algorithm Code
#include "jaccard_algorithm.h"

FILE* read_csv(char* filename[]) {
    printf("Reading file...\n");
    FILE* file = fopen(*filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    return file;
}

void parse_csv(FILE* file, char* data[60000][10]) {
    printf("Parsing file...\n");
    char buffer[1028];
    int row = 0;
    int col = 0;
    while(fgets(buffer, sizeof(buffer), file)) {
        col = 0;
        row++;
        // Parsing
        char* value = strtok(buffer, ",");
        while(value != NULL) {
            data[row][col++] = strdup(value);
            value = strtok(NULL,";");
        }
    }
}

int main() {
    // Read File
    char* filename = "test_data_with_couples_and_typos_and_misclicks.csv";
    FILE* file = read_csv(&filename);

    // Allocate memory for the data array
    char* data[60000][10] = {0};
    parse_csv(file, data);
    fclose(file);

    // call jaccard for test, save as duplicate_entries

    // make new csv file for duplicate_entries

    // Initial Test: Print first row
    for (int col = 0; col < 10 && data[0][col] != NULL; col++) {
        printf("%s ", data[0][col]);
    }
    printf("\n");
    printf("Test completed! Freeing memory...\n");

    // Free allocated memory
    for (int row = 0; row < 60000; row++) {
        for (int col = 0; col < 10; col++) {
            free(data[row][col]);
        }
    }

    return 0;
}

