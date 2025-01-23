#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// Algorithm Code
#include "jaccard_algorithm.h"

FILE* read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    return file;
}

void parse_csv(FILE* file, char* data[60000][10]) {
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

// COMMENT OUT WHEN BUG FIXING FILE READING
void find_dupes(char* data[60000][10], const char* function_call) {
    int row = 0;
    for (int i=0; data[i]!= NULL; i++) {
        for (int j=0; data[j]!= NULL; j++) {
            if (data[i][0]!=data[j][0]) { // if ids are different
                if (strcmp(function_call, "j") == 0) { // jaccard label
                    data[0][9] = strdup("jaccard_pred"); //creates label on new column

                    // runs jaccard, returns a boolean, 0.25 is the current max fuzziness allowed
                    int jaccard_results = jaccard_sim(data[i], data[j], 0.25);

                    if (jaccard_results == 0) { // 0 = no dupe found
                        data[i][9] = data[j][0];
                        data[j][9] = data[i][0];
                    } else {                    // 1 = dupe found
                        data[i][9] = "none";
                        data[j][9] = "none";
                    }
                }
            }
        }
    }
}

void create_csv(char* data[60000][10], const char* filename) {
    int rows = 60000; // Find way to automate these later
    int cols = 10;

    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            fprintf(file, "%s", data[i][j]);
            if (j < cols - 1) {
                fprintf(file, ",");
            }
            fprintf(file, "\n");
        }
    }
    printf("CSV file created! Can be found at: %s\n", filename);
    
    fclose(file);
}
//YOU CAN STOP COMMENTING OUT CODE HERE

int main() {
    // Read File (currently uses relative path)
    const char* filename = "test_data_with_couples_and_typos_and_misclicks.csv";
    printf("Reading file: %s\n", filename);
    FILE* file = read_csv(filename);

    // Allocate memory for the data array
    char* data[60000][10] = {0};

    // Parse entries in file to 2D array data
    printf("Parsing file...\n");
    parse_csv(file, data);
    fclose(file);

    // call jaccard for test, save as duplicate_entries
    printf("Using algorithms to find duplicates...\n");
    find_dupes(data,"j");

    // make new csv file for duplicate_entries
    printf("Creating new CSV to store data...\n");
    create_csv(data, "jaccard_test_output.csv");

    // Free allocated memory
    printf("Freeing memory...\n");
    for (int row = 0; row < 60000; row++) {
        for (int col = 0; col < 10; col++) {
            free(data[row][col]);
        }
    }

    return 0;
}

