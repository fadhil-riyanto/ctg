#include <string.h>
#include <stdio.h>

typedef struct aaaa {
        char *nama;
}  aaaa_t;
int main() 
{
        aaaa_t aaaa;
        aaaa.nama = "ngueeeng";
        char *bufff[200];
        snprintf(bufff, sizeof(bufff), "%s=%s&", "hai", aaaa.nama);
        printf(bufff);
}