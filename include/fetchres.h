// SPDX-License-Identifier: GPL-2.0

/*
 *  fetchres.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#ifndef INCLUDE__FETCHRES_H_
#define INCLUDE__FETCHRES_H_
/* get updates */

#include <stdbool.h>
#include <stdint.h>
/* not accesed by other */

/* get message->from */
#if !defined(from) || !defined(from_t)
        typedef struct from {
                int64_t                 id; 
                bool                    is_bot;
                const char              *first_name;
                const char              *last_name;
                const char              *username;
                const char              *language_code;
        }from_t ;
#endif

/* get message->chat */
#if !defined(chat) || !defined(chat_t)
        typedef struct chat {
                int64_t                id;
                const char              *first_name;
                const char              *last_name;
                const char              *username;
                const char              *type;
        } chat_t ;
#endif


/* get message */
#if !defined(message) || !defined(message_t)
        typedef struct message {
                int                     message_id;
                from_t                  from;
                chat_t                  chat;
                uint64_t                date;
                const char              *text;
        } message_t ;
#endif


/* end */

#if !defined(tg_json_getupdates_t) || !defined(tg_json_getupdates)
        typedef struct tg_json_getupdates {
                message_t               message;
                int                     update_id;
        } tg_json_getupdates_t ;
#endif
#endif