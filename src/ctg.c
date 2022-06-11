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

char *init(ctg_utils_t maindt)
{
        tg_json_getupdates_t *data = get_updates(maindt, 0,1);
        DEBUGW("data->update_id is %d\n", data->update_id);
        DEBUGW("data->message.message_id is %d\n", data->message.message_id);
        free(data);
        //DEBUGW("data->message->from.id is %d", data->message.from.id);
        return "";

}