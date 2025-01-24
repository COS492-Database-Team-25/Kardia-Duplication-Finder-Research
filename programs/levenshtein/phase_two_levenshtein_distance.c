#include <stdio.h>
#include <string.h>
#include <stdlib.h>
__attribute__((visibility("default"))) int levenshtein(int argc, char *argv[]) {
    int da[26];
  
    char *a = argv[1];
    char *b = argv[2];
    int strlen_a = strlen(a);
    int strlen_b = strlen(b);
  
    for (int i=0; i < 26; i++)
    {
        da[i] = 0;
    }
    // To use malloc the rest of the data will need to be changed to allow for it
    //int* d[strlen_a+2];
    //for(int i = 0; i < strlen_a+2; i++) {
    //    d[i] = (int*)malloc((strlen_b+2) * sizeof(int));
    //}

    //int d = (int*)malloc((strlen_a+2)*(strlen_b+2)*sizeof(int));
    int d[strlen_a+4][strlen_b+4]; // 2d array that stores how many operations it took to get the a and b string of length i and j respectively


    int max_distance = strlen_a + strlen_b;
    d[-1][-1] = max_distance;


    for(int i = 0; i <= strlen_a; i++) // sets the first row to be one (insert) operation per letter in the a string
    {
        d[i][-1] = max_distance;
        d[i][0] = i;
    }
  
    for(int j = 0; j <= strlen_b; j++) // sets the first column to be one (insert) per letter in the b string
    {
        d[-1][j] = max_distance;
        d[0][j] = j;
        
    }
    for(int i = 0; i <= strlen_a; i++)
    {
        printf("\n");
        for(int j = 0; j <= strlen_b; j++)
        {
            printf("%d",d[i][j]);

        }
    }

    int cost;
    int minimum[4];
    for(int i = 1; i <= strlen_a; i++)
    {
        int db = 0;
        for(int j = 1; j <= strlen_b; j++)
        {
            int k = da[((int)b[j])-48];
            int l = db;
            printf("%c, %c\n", a[i-1], b[j-1]);
            if (a[i-1] == b[j-1])
            {
                cost = 0;
                db = j;
            }
            else 
            {
                cost = 1;
            }
            minimum[0] = d[i-1][j-1] + cost;
            minimum[1] = d[i][j-1] + 1;
            minimum[2] = d[i-1][j] + 1;
            minimum[3] = d[k-1][l-1]+(i-k-1) + 1 + (j-l-1);

            int min = strlen_a+strlen_b;
            for(int k = 0; k < 4; k++) 
            {

                
                printf("%d,", minimum[k]);
                if(minimum[k] < min && minimum[k] >= 0) 
                {
                    min = minimum[k];
                }
            }
            printf("\n");
            d[i][j] = min;
            
        }
    da[((int)a[i]-48)] = i;
    }
     printf("\n");
    for(int i = 0; i <= strlen_a; i++)
    {
        printf("\n");
        for(int j = 0; j <= strlen_b; j++)
        {
            printf("%d",d[i][j]);

        }
    }
     printf("\n");
    //Need to be printed (d[[strlen_a][strlen_b]])
    printf("%d\n", (d[strlen_a][strlen_b]));
    return d[strlen_a][strlen_b];
}
/*
for(int i = 0; i < strlen_a; i++)
    {
        printf("\n");
        for(int j = 0; j < strlen_b; j++)
        {
            printf("%d",d[i][j]);

        }
    }
*/