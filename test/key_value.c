#include "fcntl.h"
#include <stdio.h>
typedef struct key_val {
        char *key;
        char *value;
} key_val_t;

int countinsert = 0;

void insert_key_val(key_val_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}

int main()
{
        key_val_t data[100];
        insert_key_val(data, "tes", "tes2");
        insert_key_val(data, "tes index 1", "tes ok");
        fprintf(stdout, data[0].value);
        fprintf(stdout, data[1].value);

        
}