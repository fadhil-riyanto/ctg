// SPDX-License-Identifier: GPL-2.0

/*
 *  main.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */
#include <asm-generic/errno-base.h>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include "ctg.h"
#include "debug_fn.h"

int main(int argc, char *argv[]) 
{
        DEBUGP("argc total is %d\n", argc);
        if (argc < 3) {
                fprintf(stderr, "%s\n", "please use ./%s your:telegram_token thread_total");
                fprintf(stderr, "%s\n", "your:telegram_token from @botfather.");
                fprintf(stderr, "%s\n", "thread_total is number for allocated thread");
                return EINVAL;
        } 
        // printf("%s", argv[1]);
        // return 0;
        
        ctg_utils_t ctgu;
        ctgu.bot_token = argv[1];        
        ctgu.thread = atoi(argv[2]);
        DEBUGI("bot token is %s\n", ctgu.bot_token);
        DEBUGI("total thread will alocated:  %d\n", ctgu.thread);

        printf("%s", init(&ctgu));
        
}