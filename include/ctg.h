// SPDX-License-Identifier: GPL-2.0

/*
 *  ctg.h
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#ifndef INCLUDE__CTG_H_
#define INCLUDE__CTG_H_
typedef struct ctg_utils  {
        char            *bot_token;
        int             thread;
} ctg_utils_t;

char *init(ctg_utils_t *maindt);
#endif