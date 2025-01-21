#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_GRAMS 100

// Function to generate character n-grams from a word
void generate_ngrams(char *word, int n, char ngrams[MAX_GRAMS][MAX_GRAMS], int *ngram_count) {
    int len = strlen(word);
    *ngram_count = 0;

    // Generate n-grams
    for (int i = 0; i <= len - n; i++) {
        // Copy the n-gram into the array
        strncpy(ngrams[*ngram_count], &word[i], n);
        ngrams[*ngram_count][n] = '\0';  // Null-terminate the n-gram
        (*ngram_count)++;
    }
}

// Function to compute the dot product of two n-gram frequency vectors
int dot_product(int *vec1, int *vec2, int length) {
    int result = 0;
    for (int i = 0; i < length; i++) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

// Function to compute the magnitude (Euclidean norm) of a vector
double magnitude(int *vec, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

// Function to compute the cosine similarity between two words
double cosine_similarity_words(char *word1, char *word2, int n) {
    char ngrams1[MAX_GRAMS][MAX_GRAMS], ngrams2[MAX_GRAMS][MAX_GRAMS];
    int ngram_count1, ngram_count2;
    
    // Generate n-grams for both words
    generate_ngrams(word1, n, ngrams1, &ngram_count1);
    generate_ngrams(word2, n, ngrams2, &ngram_count2);

    // Create a list of unique n-grams from both words
    char all_ngrams[MAX_GRAMS * 2][MAX_GRAMS];
    int all_ngram_count = 0;

    // Add n-grams from the first word
    for (int i = 0; i < ngram_count1; i++) {
        int found = 0;
        for (int j = 0; j < all_ngram_count; j++) {
            if (strcmp(ngrams1[i], all_ngrams[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(all_ngrams[all_ngram_count], ngrams1[i]);
            all_ngram_count++;
        }
    }

    // Add n-grams from the second word
    for (int i = 0; i < ngram_count2; i++) {
        int found = 0;
        for (int j = 0; j < all_ngram_count; j++) {
            if (strcmp(ngrams2[i], all_ngrams[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(all_ngrams[all_ngram_count], ngrams2[i]);
            all_ngram_count++;
        }
    }

    // Create frequency vectors for both words
    int vec1[MAX_GRAMS * 2] = {0}, vec2[MAX_GRAMS * 2] = {0};

    // Fill the frequency vector for word1
    for (int i = 0; i < ngram_count1; i++) {
        for (int j = 0; j < all_ngram_count; j++) {
            if (strcmp(ngrams1[i], all_ngrams[j]) == 0) {
                vec1[j]++;
                break;
            }
        }
    }

    // Fill the frequency vector for word2
    for (int i = 0; i < ngram_count2; i++) {
        for (int j = 0; j < all_ngram_count; j++) {
            if (strcmp(ngrams2[i], all_ngrams[j]) == 0) {
                vec2[j]++;
                break;
            }
        }
    }

    // Calculate the dot product and magnitudes
    int dot_prod = dot_product(vec1, vec2, all_ngram_count);
    double mag1 = magnitude(vec1, all_ngram_count);
    double mag2 = magnitude(vec2, all_ngram_count);

    // Calculate and return cosine similarity
    if (mag1 == 0 || mag2 == 0) {
        return 0.0;  // If either vector is zero, similarity is 0
    }
    return dot_prod / (mag1 * mag2);
}

int main(int argc, char* argv[]) {
    char* word1 = argv[1];
    char* word2 = argv[2];
    double similarity = 0;
    double avg_similarity = 0;
    double n_count = 3;
    for(int n = 1; n <= n_count; n++){

    similarity = cosine_similarity_words(word1, word2, n);
    avg_similarity += similarity;

    printf("Cosine Similarity between \"%s\" and \"%s\": %lf\n", word1, word2, similarity);
    }
    avg_similarity = avg_similarity/n_count;
    printf("Average Cosine Similarity between \"%s\" and \"%s\": %lf\n", word1, word2, avg_similarity);

    return 0;
}
