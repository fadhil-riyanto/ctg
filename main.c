// SPDX-License-Identifier: GPL-2.0

/*
 *  curl_obj.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "ctg.h"

int main() 
{
        if (getenv("CTG_BOT_TOKEN") == NULL) {
                fprintf(stderr, "%s", "error, CTG_BOT_TOKEN not found");
                return EAGAIN;
        }
        ctg_utils_t *ctgu;
        ctgu->bot_token = getenv("CTG_BOT_TOKEN");
        
        

        printf("%s", "hello world");
        somefn();
}