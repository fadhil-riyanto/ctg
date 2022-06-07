// SPDX-License-Identifier: GPL-2.0

/*  
 *  test file: http_build_query.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "fcntl.h"
#include "limits.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include <string.h>

typedef struct key_val {
        char *key;
        char *value;
} key_value_t;
