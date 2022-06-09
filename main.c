// SPDX-License-Identifier: GPL-2.0

/*
 *  main.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "ctg.h"
#include "debug_fn.h"

int main(int argc, char *argv[]) 
{
        DEBUGP("argc total is %d\n", argc);
        if (argc < 2 && getenv("CTG_BOT_TOKEN") == NULL) {
                fprintf(stderr, "%s", "error, CTG_BOT_TOKEN not found. or pass the bot token into 2nd argc");
                return EAGAIN;
        } 
        
        ctg_utils_t *ctgu;
        ctgu->bot_token = (getenv("CTG_BOT_TOKEN") == NULL) ? argv[2] : getenv("CTG_BOT_TOKEN");
        
        

        printf("%s", init());
        
}