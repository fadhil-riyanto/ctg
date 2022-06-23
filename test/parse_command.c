#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void callback(char *data)
{
        printf("%s\n", data);
}

int split(char *string, char del, void (*cb)(char *data)) 
{
        int last_offset = 0, looplen = 0, total_split_len = 0;
        
        char *init = "";
        int len = strlen(init);
        char *temp = malloc(sizeof(char) * strlen(string));
        strcpy(temp, init);
        
        char ress[strlen(string) + 1];
        for (int i = 0; i < strlen(string); i++) {
                if (string[i] == del) {
                        
                        //printf("offset %d ditemukan\n", i);
                        // get the last offset
                        for (int a = last_offset; a < i; a++) {

                                // check if found delimiter again, or \0
                                //printf("data : %c\n", string[a]);
                                // if (string[a] == del) {
                                //         // collect affected char
                                //         for(int ab = a; ab < i; ab++) {
                                //                 printf("data : %c\n", string[ab]);
                                //         }
                                //         printf("end\n");
                                // }
                                //ress[]
                                if (string[a] == del) {
                                        total_split_len += 1;
                                        
                                } else {
                                        temp[len] = string[a];
                                        len += 1;
                                        //printf("data : %c\n", string[a]);
                                }
                                
                                
                        }
                        cb(temp);
                        // temp[0] = 0;
                        // temp[1] = 0;
                        // temp[2] = 0;
                        // temp[3] = 0;
                        // reset
                        for(int rr = 0; rr < strlen(string); rr++) {
                                temp[rr] = 0;
                        }
                        len = 0;
                        
                        //printf("end\n");
                        looplen += 1;
                        last_offset = i;
                }
        }


        // get last offset
        // for (int i = last_offset; i < strlen(string); i++) {
        //         // literating incerement for detect \0
        //         if (string[i] != '\0') {
        //                 printf("data : %c\n", string[i]);
        //         }
        // }
        // total_split_len += 1;
        //printf("%d\n", total_split_len);
        
}
int main() 
{
        char *data = "hai ke ma kaww heh ao";
        split(data, ' ', &callback);
        // for(int a = 5; a > 0; a--) {
        //         printf("%d", a);
        // }
}

