#include <stdio.h>
#include <stdlib.h>

typedef struct aaa {
        int aaa;
} aaa_t;

aaa_t *ngueeng(aaa_t *aa)
{
        aa->aaa = 9;
        return aa;
}

int main() 
{
        aaa_t *aa = malloc(sizeof(aaa_t));
        for(int i = 0;i < 3; i++) {
                aa = ngueeng(aa);
                printf("%d", aa->aaa);
        }
        
        

        printf("%d", aa->aaa);
        free(aa);
}