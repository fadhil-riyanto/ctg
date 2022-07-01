#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
        char *data;
        char *temp;
} split_t;

void split_init(split_t *dest, char *string) {
        char *temp = malloc(sizeof(char) * strlen(string));
        dest->temp = temp;
        dest->data = string;
}

void split_str(split_t *dest, char del, int offset)
{
        printf("aa \"%s\"\n", "jalan");
        printf("bb \"%s\"\n", dest->temp);
        bool stopfn = false;
        int last_offset = 0, looplen = 0, total_split_len = 0; 
        char *init = "";
        int len = strlen(init);
        char *temp = dest->temp;
        strcpy(temp, init);
        char ress[strlen(dest->data) + 1];
        for (int i = 0; i < strlen(dest->data); i++) {
                if (dest->data[i] == del) {
                        for (int a = last_offset; a < i; a++) {
                                if (dest->data[a] == del) {
                                        total_split_len += 1;
                                } else {
                                        temp[len] = dest->data[a];
                                        len += 1;
                                }
                        }
                        
                        
                        if (looplen == offset) {
                                // printf(">>%d\n", looplen);
                                dest->temp = temp;
                                // printf("%s", dest->temp);
                                
                                stopfn = true;
                                break;
                        } 
                        
                        for(int rr = 0; rr < strlen(dest->data); rr++) {
                                temp[rr] = 0;
                        }
                        temp[len] = '\0';
                        len = 0;
                        looplen += 1;
                        last_offset = i;
                }
        }
        if (!stopfn) {
                for (int i = last_offset; i < strlen(dest->data); i++) {
                        if (dest->data[i] != '\0' && dest->data[i] != del) {
                                temp[len] = dest->data[i];
                                len += 1;
                        }
                }
                temp[len] = '\0';

                dest->temp = temp;
        }
        

        // if (looplen == offset) {
        //         dest->temp = temp;
        // } else {
        //         dest->temp = NULL;
        // }
        //printf("%d\n", looplen);
        //dest->temp = temp;
}

char* split_get_str(split_t *dest) 
{
        char *strr = malloc(strlen(dest->temp) + 1);
        strcpy(strr, dest->temp);
        return strr;
}

int main()
{
        char *rawc = "1@23 456 789 012";
        int total;

        split_t init;
        split_init(&init, rawc);
        split_str(&init, ' ', 0);
        char *data = split_get_str(&init);
        printf("bool > %s\n", data);
        free(data);

        split_str(&init, '@', 0);
        char *data2 = split_get_str(&init);
        printf("at > %s\n", data2);
        free(data2);


        // char *datasplit = split(rawc, ' ', 0, &total, false);
        // char *bot_username_command = split(datasplit, '@', 1, &total, true);
        
        //}

}















































































// char* split(char *string, char del, int offset, int *len_all, bool get_len) {
//         int last_offset = 0, looplen = 0, total_split_len = 0; 
//         char *init = "";
//         int len = strlen(init);
//         char *temp = malloc(sizeof(char) * strlen(string));
//         strcpy(temp, init);
//         char ress[strlen(string) + 1];
//         for (int i = 0; i < strlen(string); i++) {
//                 if (string[i] == del) {
//                         for (int a = last_offset; a < i; a++) {
//                                 if (string[a] == del) {
//                                         total_split_len += 1;
//                                 } else {
//                                         temp[len] = string[a];
//                                         len += 1;
//                                 }
//                         }
                        
//                         if (get_len != true) {
//                                 if (looplen == offset) {
//                                         *len_all = looplen;
//                                         return temp;
//                                 } 
//                         }
//                         for(int rr = 0; rr < strlen(string); rr++) {
//                                 temp[rr] = 0;
//                         }
//                         temp[len] = '\0';
//                         len = 0;
//                         looplen += 1;
//                         last_offset = i;
//                 }
//         }
//         for (int i = last_offset; i < strlen(string); i++) {
//                 if (string[i] != '\0' && string[i] != del) {
//                         temp[len] = string[i];
//                         len += 1;
//                 }
//         }
//         temp[len] = '\0';

//         len = 0;
//         *len_all = looplen;
//         looplen += 1;
        
//         return temp;
// }
