#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
        char *init = "";
        int len = strlen(init);
        char *temp = malloc(sizeof(char) * 5);

        strcpy(temp, init);
        temp[len] = 'b';
        temp[len + 1] = 'b';
        printf("%s\n", temp);
        // reset
        strcpy(temp, "");

        temp[len] = 'a';
        temp[len + 1] = 'a';
        temp[len + 2] = 'a';
        temp[len + 3] = 'a';
        temp[len + 4] = 'a';
        temp[len + 5] = 'a';

        printf("%s\n", temp);
        free(temp);
}