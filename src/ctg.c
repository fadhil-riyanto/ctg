// SPDX-License-Identifier: GPL-2.0

/*
 *  ctg.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stdio.h>
#include <stdlib.h>
#include "curl_fn.h"
#include "ctg.h"
#include "curl_obj.h"
#include "tg_method.h"
#include "debug_fn.h"

char *init(ctg_utils_t *maindt)
{
        tg_json_getupdates_t *data = get_updates(maindt, 730076240,1);
        DEBUGW("data->update_id is %d\n", data->update_id);
        DEBUGW("data->message.message_id is %d\n", data->message.message_id);
        DEBUGW("data->message->from.id is %lu\n", data->message.from.id);
        DEBUGW("data->message->from.is_bot is %s\n", (data->message.from.is_bot) ? "true" : "false");
        DEBUGW("data->message->from.first_name is %s\n", data->message.from.first_name);
        DEBUGW("data->message->from.last_name is %s\n", data->message.from.last_name);
        DEBUGW("data->message->from.username is %s\n", data->message.from.username);
        DEBUGW("data->message->from.language_code is %s\n", data->message.from.language_code);

        free(data);
        return "";

}