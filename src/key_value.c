// SPDX-License-Identifier: GPL-2.0

/*
 *  ctg.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */
 
#include "key_value.h"

int countinsert;

void insert_key_value(key_value_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}

void reset_count_key_value()
{
        countinsert = 0;
}