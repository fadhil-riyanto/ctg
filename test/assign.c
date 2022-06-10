// SPDX-License-Identifier: GPL-2.0

#include <stdio.h>
#include <stdbool.h>
/*
 *  fetchres.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

/* get updates */

#include "stdbool.h"
/* not accesed by other */

/* get message->from */
typedef struct from {
        int                     id;
        bool                    is_bot;
        char                    *first_name;
        char                    *last_name;
        char                    *username;
        char                    *language_code;
}from_t ;

/* get message->chat */
typedef struct chat {
        int                     id;
        char                    *first_name;
        char                    *last_name;
        char                    *username;
        char                    *type;
} chat_t ;


/* get message */
typedef struct message {
        int                     message_id;
        from_t                  from;
        chat_t                  chat;
        int                     date;
        char                    *text;
} message_t ;


/* end */

#if !defined(tg_json_getupdates_t)
        typedef struct tg_json_getupdates {
                //message_t               *message;
                int                     update_id;
        } tg_json_getupdates_t ;
#endif

int main() 
{
        tg_json_getupdates_t *getupdates_res;
        getupdates_res->update_id = 9;

        printf("%d", getupdates_res->update_id);
}