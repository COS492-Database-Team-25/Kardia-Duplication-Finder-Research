#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int ele_pre(const char* S, char chr)
{
    for (int i = 0; S[i] != '\0'; i++)
        if (S[i] == chr)
            return 1; // Character was found
    return 0; // Character was not found
}

char* set_union(const char* S1, const char* S2)
{
    // Allocate memory where necessary
    size_t max_size = strlen(S1) + strlen(S2) + 1;
    char* str_union = (char*)malloc(max_size * sizeof(char));
    if (!str_union) {
        perror("Failed to allocate memory, set_union\n");
        exit(1);
    }

    size_t pos = 0;

    // Copy first string into union string (only alphanumerical)
    for (int i = 0; S1[i] != '\0'; i++)
        if (isalnum(S1[i]))
            str_union[pos++] = S1[i];

    // Add characters from second string (only alphanumerical)
    for (int i = 0; S2[i] != '\0'; i++)
        if (isalnum(S2[i]) && !ele_pre(str_union, S2[i]))
            str_union[pos++] = S2[i];

    str_union[pos] = '\0'; // End string with null

    printf("In Union: %s\n", str_union);

    return str_union;
}

// Works best without duplicate letters
char* intersection(char* S1, char* S2)
{
    size_t max_size = strlen(S1)+strlen(S2);
    // Allocate memory necessary
    char* str_intersect = (char*)malloc(max_size * sizeof(char));
    if (!str_intersect) {
        perror("Failed to allocate memory, str_intersection\n");
        exit(1);
    }

    size_t pos = 0;
    for (int i = 0; S1[i] != '\0'; i++)
        /* if S1[i] is found in S2 and is NOT in str_intersect */
        if (ele_pre(S2, S1[i])) {
            // Make max_size larger if necessary
            if (pos + 1 >= max_size) {
                max_size *= 2;
                char* new_intersect = (char*)realloc(str_intersect, max_size); // Allocate memory for the intersection
                if (!new_intersect) {
                    perror("Failed to reallocate memory, str_intersection\n");
                    free(str_intersect);
                    exit(1);
                }
                str_intersect = new_intersect;
            }
            str_intersect[pos++] = S1[i];
        }

    str_intersect[pos] = '\0'; //End string with null
    printf("In Intersect: %s\n", str_intersect);
    return str_intersect;
}

// Takes more time, but handles duplicate letters better
char* intersection_multiset(char* S1, char* S2)
{
    // Allocate memory for str_int_mult
    size_t max_size = strlen(S1) + strlen(S2);
    char* str_int_mult = (char*)malloc(max_size * sizeof(char));
    if (!str_int_mult) {
        perror("Failed to allocate memory, str_int_mult\n");
        exit(1);
    }

    size_t pos = 0;
    int char_count_S2[256] = {0};

    for (int i = 0; S2[i] != '\0'; i++) {
        if (isalnum(S2[i])) { // Only count alphanumeric characters
            char_count_S2[(unsigned char)S2[i]]++;
        }
    }

    // Add characters from S1 that are in S2 (up to their count in S2)
    for (int i = 0; S1[i] != '\0'; i++) {
        if (isalnum(S1[i]) && char_count_S2[(unsigned char)S1[i]] > 0) {
            if (pos + 1 >= max_size) {
                max_size *= 2;
                char* new_intersect = (char*)realloc(str_int_mult, max_size);
                if (!new_intersect) {
                    perror("Failed to reallocate memory, str_int_mult\n");
                    free(str_int_mult);
                    exit(1);
                }
                str_int_mult = new_intersect;
            }
            str_int_mult[pos++] = S1[i];
            char_count_S2[(unsigned char)S1[i]]--; // Decrement count for character
        }
    }

    str_int_mult[pos] = '\0'; //End string with null
    printf("In Normalized Intersect: %s\n", str_int_mult);
    return str_int_mult;
}

double jaccard_sim(char* S1, char* S2) 
{
    char* str_union = set_union(S1, S2);
    char* str_intersect = intersection_multiset(S1, S2);

    double jaccard_val = (double)strlen(str_intersect) / strlen(str_union);

    // Clean variables from memory after use
    free(str_intersect);
    free(str_union);

    return jaccard_val;
}

int main() 
{
    char str1[] = "Jack and Jill";
    char str2[] = "Jill & Jack";

    printf("Fuzziness (Jaccard Similarity): %f\n", jaccard_sim(str1, str2));
    return 0;
}