#include <stdio.h>
#include <string.h>
int main()
{
        char *raw = "hai kakakaka keeeeeeeeeeeeee";
        char rawchar[strlen(raw)];

        int cint_count = 0;
        for(; *raw; *raw++) {
                rawchar[cint_count] = *raw;
                cint_count += 1;
        }
        rawchar[cint_count] = '\0';

        printf("%s", rawchar);
}