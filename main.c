// SPDX-License-Identifier: GPL-2.0

/*
 *  main.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "ctg.h"
#include "debug_fn.h"

int main(int argc, char *argv[]) 
{
        DEBUGP("argc total is %d\n", argc);
        if (argc < 2) {
                fprintf(stderr, "%s", "error, BOT TOKEN not found.");
                return EAGAIN;
        } 
        // printf("%s", argv[1]);
        // return 0;
        
        ctg_utils_t ctgu;
        ctgu.bot_token = argv[1];
        
        DEBUGP("bot token is %s\n", ctgu.bot_token);

        printf("%s", init(&ctgu));
        curl_global_cleanup();
}