// SPDX-License-Identifier: GPL-2.0

/*
 *  tg_method.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <string.h>
#include <limits.h>
#define INT_DECIMAL_STRING_SIZE(int_type) ((CHAR_BIT*sizeof(int_type)-1)*10/33+3)

char *int_to_string_alloc(int x) {
        int i = x;
        char buf[INT_DECIMAL_STRING_SIZE(int)];
        char *p = &buf[sizeof buf] - 1;
        *p = '\0';
        if (i >= 0) {
                i = -i;
        }
        do {
                p--;
                *p = (char) ('0' - i % 10);
                i /= 10;
        } while (i);
        if (x < 0) {
                p--;
                *p = '-';
        }
        size_t len = (size_t) (&buf[sizeof buf] - p);
        char *s = malloc(len);
        if (s) {
                memcpy(s, p, len);
        }
        return s;
}