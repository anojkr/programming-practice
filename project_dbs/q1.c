#include <stdio.h>
#include <string.h>



void readline_parse(char insert_query[1000], char *token[100]) 
{
    char *pch;

    for (int k = 0; k < 100; k++) {
        token[k] = NULL;
    }

    pch = strtok(insert_query, " ");

    int i = 0;
    while (pch != NULL) {
        token[i] = pch;
        pch = strtok (NULL, " ");
        i++;
    }
    token[i+1] = NULL;
    
    int z = 0;

    // while (token[z] != NULL) {
    //  printf("%s\n",token[z]);
    //  z++;
    // }
}

int main()
{
    FILE* file = fopen("q2.txt", "r"); /* should check the result */
    char line[256];
    char *token[100];


    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        //printf("%s", line);
        parse(line, token); 
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);

    return 0;
}