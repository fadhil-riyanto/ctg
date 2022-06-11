// SPDX-License-Identifier: GPL-2.0

/*
 *  fetchres.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

/* get updates */

#include "stdbool.h"
#include "stdint.h"
/* not accesed by other */

/* get message->from */
#if !defined(from)
        typedef struct from {
                uint64_t                id; 
                bool                    is_bot;
                char                    *first_name;
                char                    *last_name;
                char                    *username;
                char                    *language_code;
        }from_t ;
#endif

/* get message->chat */
#if !defined(chat) || !defined(chat_t)
        typedef struct chat {
                int                     id;
                char                    *first_name;
                char                    *last_name;
                char                    *username;
                char                    *type;
        } chat_t ;
#endif


/* get message */
#if !defined(message) || !defined(message_t)
        typedef struct message {
                int                     message_id;
                from_t                  from;
                chat_t                  chat;
                int                     date;
                char                    *text;
        } message_t ;
#endif


/* end */

#if !defined(tg_json_getupdates_t) || !defined(tg_json_getupdates)
        typedef struct tg_json_getupdates {
                message_t               message;
                int                     update_id;
        } tg_json_getupdates_t ;
#endif