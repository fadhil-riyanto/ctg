// SPDX-License-Identifier: GPL-2.0

/*
 *  key_value.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "fcntl.h"
#include "limits.h"
#include <stdint.h>
#include <stdio.h>
typedef struct key_val {
        char *key;
        char *value;
} key_val_t;

int countinsert;
void insert_key_val(key_val_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}

int main()
{
        key_val_t data[100];
        char *buffer0;
        char *buffer1;
        int i;
        
        
        // insert_key_val(data, "data 0", "key 0");
        // insert_key_val(data, "data 1", "key 1");
        fprintf(stdout, "%s %s\n", (char *)data[0].key, (char *)data[0].value);
        // insert_key_val(data, "tes", "tes");
        // insert_key_val(data, "tes1", "tes1");
        // insert_key_val(data, "tes2", "tes2");

        // fprintf(stdout, "%s", (char *)data[2].key);
        fprintf(stdout, "%s", (char *)data[0].key);
}