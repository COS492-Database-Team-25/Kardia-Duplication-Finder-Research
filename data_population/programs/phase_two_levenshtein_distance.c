#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int da[26];
    char *a = argv[1];
    char *b = argv[2];
    for (int i=0; i < 26; i++)
    {
        da[i] = 0;
    }

    int d[strlen(argv[1])+2][strlen(argv[2])+2];

    int max_distance = strlen(a) + strlen(b);
    d[-1][-1] = max_distance;
    printf("%lu", strlen(b));
    for(int i = 0; i < strlen(a); i++)
    {
        d[i][-1] = max_distance;
        d[i][0] = i;
    }

    for(int j = 0; j < strlen(b); j++)
    {
        d[-1][j] = max_distance;
        d[0][j] = j;
    }
    int cost;
    for(int i = 0; i < strlen(a); i++)
    {
        int db = 0;
        for(int j = 0; j < strlen(b); j++)
        {
            int k = da[((int)b[j])-48];
            int l = db;
            if (a[i] == b[j])
            {
                cost = 0;
                db = j;
            }
            else 
            {
                cost = 1;
            }
            int minimum[4];
            minimum[0] = d[i-1][j-1] + cost;
            minimum[1] = d[i][j-1] + 1;
            minimum[2] = d[i-1][j] + 1;
            minimum[3] = d[k-1][l-1]+(i-k-1) + 1 + (j-l-1);
            int min = minimum[0];
            for(int k = 1; k < 4; k++) 
            {
                if(minimum[k] < min) 
                {
                    min = minimum[k];
                }
            }
            d[i][j] = min;
        }
    da[((int)a[i]-48)] = i;
    }
    //Need to be printed (d[[strlen(a)][strlen(b)]])
    printf("%d", (d[strlen(a)][strlen(b)]));
}
