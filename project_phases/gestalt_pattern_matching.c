/*
function GestaltPatternMatching(sequence1, sequence2):
    n1 = length(sequence1)
    n2 = length(sequence2)
    
    # Step 1: Create a 2D matrix for storing LCS lengths
    LCS = createMatrix(n1 + 1, n2 + 1, 0)
    
    # Step 2: Compute the LCS using dynamic programming
    for i from 1 to n1:
        for j from 1 to n2:
            if sequence1[i - 1] == sequence2[j - 1]:
                LCS[i][j] = LCS[i - 1][j - 1] + 1
            else:
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1])
    
    # Step 3: Calculate the similarity score
    longest_common_subsequence_length = LCS[n1][n2]
    max_possible_length = max(n1, n2)
    
    similarity_score = longest_common_subsequence_length / max_possible_length
    
    return similarity_score
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a dynamic 2D matrix and initialize it with a fill value
int** create_matrix(int rows, int cols, int fill) {
    int** matrix = (int**)malloc(rows * sizeof(int*)); // Allocate memory for row pointers
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int)); // Allocate memory for each row
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = fill; // Initialize with the fill value
        }
    }
    return matrix;
}

// Function to free the dynamically allocated 2D matrix
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Free each row
    }
    free(matrix); // Free the row pointers
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    char* n1 = argv[1];
    char* n2 = argv[2];

    int len1 = strlen(n1);
    int len2 = strlen(n2);

    // Create the LCS matrix
    int** lcs = create_matrix(len1 + 1, len2 + 1, 0);

    // Compute the LCS using dynamic programming
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (n1[i - 1] == n2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? lcs[i - 1][j] : lcs[i][j - 1];
            }
        }
    }

    // The LCS length
    int lcs_length = lcs[len1][len2];
    printf("LCS Length: %d\n", lcs_length);

    // Calculate the similarity score
    int max_length = (len1 > len2) ? len1 : len2;
    double similarity_score = (double)lcs_length / max_length;
    printf("Similarity Score: %.2f\n", similarity_score);

    // Free the matrix
    free_matrix(lcs, len1 + 1);

    return 0;
}

