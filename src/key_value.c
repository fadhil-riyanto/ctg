#include "key_value.h"

int countinsert;

void insert_key_value(key_value_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}