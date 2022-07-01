#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
                        temp[len] = '\0';
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
        temp[len] = '\0';

        len = 0;
        *len_all = looplen;
        looplen += 1;
        
        return temp;
}

int main()

{       
        char *raw = "/test@fadhil_riyanto_bot";
        // char rawchar[strlen(raw)];
        // char *rawc = raw;
        // bool bot_own;

        // int cint_count = 0;
        // for(; *raw; *raw++) {
        //         rawchar[cint_count] = *raw;
        //         cint_count += 1;
        // }
        // rawchar[cint_count] = '\0';
        // if(rawchar[0] == '/') {
        printf("%s\n", "is command");
        int total;
        printf("data 1 > \"%s\"\n", raw);
        char *datasplit = split(raw, ' ', 0, &total, false);
        printf("data > %s\n", datasplit);
        //}

}