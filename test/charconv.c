#include <stdio.h>
#include <string.h>

int main()
{
        char data[] = {
                'a', 'i', 'u', '\0'
        };
        char *data2;;
        strcpy(data2, data);
        printf("%s", data2);
}