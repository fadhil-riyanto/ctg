// SPDX-License-Identifier: GPL-2.0

/*
 *  fetchres.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#ifndef INCLUDE__HTTP_FUNC_H_
#define INCLUDE__HTTP_FUNC_H_

#include "stdbool.h"
#include "key_value.h"

char *http_build_query(key_value_t *data_arr_keyval, size_t len_arr);

/*
 * source : https://github.com/php/php-src/blob/23961ef382e1005db6f8c08f3ecc0002839388a7/ext/standard/url.c#L459-L555
 * thanks!
 */
char *urlencode(char *alloc, const char *s, size_t len, bool raw);

#endif