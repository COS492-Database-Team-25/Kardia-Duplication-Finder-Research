#include <stdio.h>
#include <string.h>

// Define the maximum length for the strings
#define MAX_LEN 1000


double gestalt(char* word1, char* word2) {
    /*
    if (argc != 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    */

    char* n1 = word1;
    char* n2 = word2;

    int len1 = strlen(n1);
    int len2 = strlen(n2);

    // Ensure the lengths do not exceed the defined maximum
    if (len1 > MAX_LEN || len2 > MAX_LEN) {
        printf("Error: Strings exceed maximum allowed length of %d.\n", MAX_LEN);
        return 1;
    }

    // Create the LCS matrix with static allocation
    int lcs[MAX_LEN + 1][MAX_LEN + 1] = {0};

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

    // Calculate the similarity score
    int max_length = (len1 > len2) ? len1 : len2;
    double similarity_score = (double)lcs_length / max_length;

    return similarity_score;
}

__attribute__((visibility("default"))) double gestalt_interface(char* word1, char* word2) {
    return gestalt(word1, word2);
}
