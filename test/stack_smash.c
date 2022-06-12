#include <stdio.h>
#include <stdlib.h>

typedef struct aaa {
        int aaa;
} aaa_t;

aaa_t *ngueeng(){
        aaa_t *aa = malloc(1000);
        aa->aaa = 9;
        return aa;
}

int main() 
{
        aaa_t *aa;
        aa = ngueeng();
        aa = ngueeng();

        printf("%d", aa->aaa);
        free(aa);
}