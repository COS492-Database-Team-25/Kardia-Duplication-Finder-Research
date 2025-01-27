#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000  // Maximum string length

int main(int argc, char* argv[]) {
    // Ensure valid arguments
    if (argc < 3) {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    char *a = argv[1];
    char *b = argv[2];
    int len_a = strlen(a);
    int len_b = strlen(b);

    // Ensure strings fit within the fixed array size
    if (len_a > MAX_LEN || len_b > MAX_LEN) {
        printf("Error: Strings must not exceed %d characters.\n", MAX_LEN);
        return 1;
    }

    // Declare a 2D array with fixed size
    int d[MAX_LEN + 1][MAX_LEN + 1];

    // Initialize the first row and column
    for (int i = 0; i <= len_a; i++) d[i][0] = i;  // First column
    for (int j = 0; j <= len_b; j++) d[0][j] = j;  // First row

    // Fill the matrix
    int cost;
    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            int substitution = d[i - 1][j - 1] + cost;
            int insertion = d[i][j - 1] + 1;
            int deletion = d[i - 1][j] + 1;
            d[i][j] = (substitution < insertion ? substitution : insertion);
            d[i][j] = (d[i][j] < deletion ? d[i][j] : deletion);
        }
    }

    // Calculate similarity
    int levenshtein_distance = d[len_a][len_b];
    float similarity = 1.0f - ((float)levenshtein_distance / (len_a + len_b));
    printf("Similarity: %f\n", similarity);

    return 0;
}
