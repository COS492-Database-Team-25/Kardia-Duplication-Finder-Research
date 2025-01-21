#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    char buffer[1000];
    char buffer2[1000];
    char *name1;
    char *name2;
    double similarity = argv[2]
    // Call Cosine Algorithm for every value in database then return all matches over a certain threshold
    if(argc != 3) {
        printf("Eror: Not enough arguments 2 needed ./command file_name similarity_score\n")
        exit(-1)
    }
    FILE *csv = fopen(argv[1], 'r');
    if(csv == NULL) {
        printf("Error: could not open file\n");
    }

    while(fgets(buffer, sizeof(buffer), csv)) {        

        // Parsing
        name1 = strtok(buffer, ",");

        FILE *csv2 = fopen(argv[1]. 'r');
        if(csv2 == NULL) {
            printf("Error: could not open file\n");
        }

        while(fgets(buffer2, sizeof(buffer2), csv))
            name2 = strtok(buffer2, ",");
            // Run GPT Cosine Similarity
            if(similarity > similarity_score) {
                printf("%s is %f similar to %s.", name1, similarity, name2);
            }



    }

    return(0);
}