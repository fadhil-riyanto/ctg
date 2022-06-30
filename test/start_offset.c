#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char *croptext(char *target, int first, int end)
{
        /* convert to char[] */
        char data[strlen(target)];
        char realstr[strlen(target)];
        int cint_count = 0;
        for(; *target; *target++) {
                data[cint_count] = *target;
                realstr[cint_count] = *target;
                cint_count += 1;
        }

        /* lets calculate */
        /* calculate for first char */
        
        for(int i = 0; i <= strlen(data); i++) {
                data[i] = data[i+first];
        }
        // last char
        // for(int s = end; s <= strlen(realstr); s++) {
        //         realstr[s] = realstr[s-first];
        // }
        // //data[0] = 0;

        // printf("%s\n", data);
        printf("%s", data);
}

int main() 
{
        char *test = "abcdefg";
        char *data = croptext(test, 6, 6);
}