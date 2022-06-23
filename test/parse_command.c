#include <stdio.h>
#include <string.h>

void callback(char *data)
{
        printf("%s", data);
}

int split(char *string, char del, void (*cb)(char *data)) 
{
        int last_offset = 0;
        for (int i = 0; i < strlen(string); i++) {
                if (string[i] == del) {
                        //printf("offset %d ditemukan\n", i);
                        // get the last offset
                        for (int a = last_offset; a < i; a++) {
                                // check if found delimiter again, or \0
                                printf("data : %c\n", string[a]);
                                // if (string[a] == del) {
                                //         // collect affected char
                                //         for(int ab = a; ab < i; ab++) {
                                //                 printf("data : %c\n", string[ab]);
                                //         }
                                //         printf("end\n");
                                // }
                        }
                        printf("end\n");
                        last_offset = i;
                }
        }
}
int main() 
{
        char *data = "hai kehp mai ka";
        split(data, ' ', callback);
        // for(int a = 5; a > 0; a--) {
        //         printf("%d", a);
        // }
}

