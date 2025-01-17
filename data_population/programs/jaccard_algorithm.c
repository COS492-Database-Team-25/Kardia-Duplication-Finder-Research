#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ele_pre(char* S[], char chr)
{
    int n, i;
    n = strlen(S[0]);
    for (i = 0; S[i] != '\0'; i++)
        if (S[i] == chr)
            return 1;
    return 0;
}

char* set_union(const char* S1[], const char* S2[])
{
    char* str_union = (char*)malloc(200 * sizeof(char)); // Allocate memory for the union
    if (!str_union) {
        perror("Failed to allocate memory");
        exit(1);
    }

    // Copy first string into union string
    strcpy(str_union, S1);
    printf('%s', str_union);

    int n = strlen(S1);
    for (int i = 0; i <= n; i++)
        str_union[i] = *S1[i];

    str_union[n] = '\0'; //Signifies the end of the string
    return str_union;
}

char* intersection(char* S1[], char* S2[])
{
    char* str_intersect = (char*)malloc(100 * sizeof(char)); // Allocate memory for the intersection
    if (!str_intersect) {
        perror("Failed to allocate memory");
        exit(1);
    }

    int j = 0;

    for (int i = 1; S1[i] != '\0'; i++)
        if (ele_pre(S2, *S1[i]))
            str_intersect[++j] = *S1[i];

    str_intersect[j] = '\0';
    return str_intersect;
}

double jaccard_sim(char* S1[], char* S2[])
{
    char* str_intersect = intersection(S1, S2);
    char* str_union = set_union(S1, S2);

    double jaccard_val = strlen(str_intersect) / strlen(str_union);

    //Clean variables from memory after use
    free(str_intersect);
    free(str_intersect);

    return jaccard_val;
}

int main() 
{
    char str1[] = "Hello World!";
    char str2[] = "Help Will!";

    printf("Fuzziness (Jaccard Similarity): %f\n", jaccard_sim(str1, str2));
    return 0;
}