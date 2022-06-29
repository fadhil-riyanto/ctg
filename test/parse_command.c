#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void callback(char *data)
{
        printf("%s\n", data);
}

char* split(char *string, char del, int offset, int *len_all, bool get_len) {
        int last_offset = 0, looplen = 0, total_split_len = 0;
        char *init = "";
        int len = strlen(init);
        char *temp = malloc(sizeof(char) * strlen(string));
        strcpy(temp, init);
        char ress[strlen(string) + 1];
        for (int i = 0; i < strlen(string); i++) {
                if (string[i] == del) {
                        for (int a = last_offset; a < i; a++) {
                                if (string[a] == del) {
                                        total_split_len += 1;
                                } else {
                                        temp[len] = string[a];
                                        len += 1;
                                }
                        }
                        if (get_len != true) {
                                if (looplen == offset) {
                                        *len_all = looplen;
                                        return temp;
                                } 
                        }
                        for(int rr = 0; rr < strlen(string); rr++) {
                                temp[rr] = 0;
                        }
                        len = 0;
                        looplen += 1;
                        last_offset = i;
                }
        }
        for (int i = last_offset; i < strlen(string); i++) {
                if (string[i] != '\0' && string[i] != del) {
                        temp[len] = string[i];
                        len += 1;
                }
        }

        len = 0;
        looplen += 1;
        *len_all = looplen;
        return temp;
}
int main() 
{
        char *data2 = "hai,haie,owww,yeff,pad,hil,s";
        int total = 0;

        /* params
        * 1. string source
        * 2. delimiter
        * 3. target index
        * 4. temp variable for saving total of length
        * 5. bool for skip checking length, set true for get actual length
        */
        char *data = split(data2, ',', 5, &total, false);
        printf("%d\n", total);
        printf("%s", data);
        free(data);
}

