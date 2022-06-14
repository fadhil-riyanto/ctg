// SPDX-License-Identifier: GPL-2.0

/*  
 *  http_build_query.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#ifndef INCLUDE__KEY_VALUE_H_
#define INCLUDE__KEY_VALUE_H_

#include "fcntl.h"
#include "limits.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include <string.h>

#if !defined(key_value_t) || !defined(key_val)
        typedef struct key_val {
                char *key;
                char *value;
        } key_value_t;
#endif

void insert_key_value(key_value_t *keyval, char *key, char *value);
void reset_count_key_value();

#endif