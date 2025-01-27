#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Swap these two functions as well as the print/return statement to use arm64 vs m1
__attribute__((visibality("default"))) int levenshtein(int argc, char *argv[]) {
//int main(int argc, char* argv[]) {

  
    char *a = argv[1];
    char *b = argv[2];
    int strlen_a = strlen(a);
    int strlen_b = strlen(b);

    int** d = (int**)malloc((strlen_a)* sizeof(int*));
    if(d == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i=0; i <= strlen_a; i++) {
        d[i] = (int*)malloc((strlen_b+1) * sizeof(int));
        if(d[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }
    
    int max_distance = strlen_a + strlen_b;


    for(int i = 0; i <= strlen_a; i++) // sets the first row to be one (insert) operation per letter in the a string
    {
        d[i][0] = i;
    }
  
    for(int j = 0; j <= strlen_b; j++) // sets the first column to be one (insert) per letter in the b string
    {
        d[0][j] = j;
        
    }

    int cost;
    int minimum[3];
    for(int i = 1; i <= strlen_a; i++)
    {
        for(int j = 1; j <= strlen_b; j++)
        {
            if (a[i-1] == b[j-1])
            {
                cost = 0;
            }
            else 
            {
                cost = 1;
            }
            minimum[0] = d[i-1][j-1] + cost;
            minimum[1] = d[i][j-1] + 1;
            minimum[2] = d[i-1][j] + 1;

            int min = strlen_a+strlen_b;
            for(int k = 0; k < 3; k++) 
            {
                if(minimum[k] < min && minimum[k] >= 0) 
                {
                    min = minimum[k];
                }
            }
            d[i][j] = min;     
        }
    }
    float output = 1-((float)d[strlen_a][strlen_b]/(float)max_distance);
    
    for (int i=0; i <= strlen_a; i++) {
        free(d[i]);
    }
    free(d);

    //return(output);
    printf("%f", output);
}