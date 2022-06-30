#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* delete_index1(char *string) {
        int last_offset = 0, looplen = 0, total_split_len = 0; 
        char *init = "";
        int len = strlen(init);
        char *alive_string = malloc(sizeof(char) * strlen(string));

        char ress[strlen(string) + 1];

        int literate = 0;
        int literatechar = 0;
        for (int i = 0; i < strlen(string); i++) {
                if (string[i] == ' ') {
                        if (literate == 0) {
                                char tempchar[strlen(string)];
                                char *rawcstring = string;
                                int cint_count_string = 0;
                                for(; *rawcstring; *rawcstring++) {
                                        tempchar[cint_count_string] = *rawcstring;
                                        cint_count_string += 1;
                                }
                                tempchar[cint_count_string] = '\0';
                                for(int a = 0; a <= strlen(string); a++) {
                                        tempchar[a] = tempchar[ ( a + 1) + i];
                                }
                                strcpy(alive_string, tempchar);
                                return alive_string;
                        }
                        literate += 1;
                } 
                literatechar += 1;
        }
        if (literatechar == strlen(string)) {
                if (literate == 0) {
                        return string;
                }
                
        }
}
int main() {
        // char *data = delete_index1("ppppp aaaaaaa a aa");
        char *res = delete_index1("🤣testcommand");
        printf("\"%s\"\n", res);
        // delete_index1("test command 2");
        // delete_index1("/test tes2t ok cstr");
        // delete_index1("/test"); // no space detected
        //delete_index1("asdf@akakak 1234soyuz5 )&(&(&");
        //printf("%s\n", data);
        //free(data);
}