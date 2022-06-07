#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * rep(const char *src, size_t repeat)
{
    char *str = (char*)malloc(repeat * repeat);
    for(int i = 0; i < repeat; i++){
        strcat(str, src);   
    }
    return str;
}
void main(){
    char *p = rep("haii", 9);
    printf("%s\n", p);
    free(p);
}