// SPDX-License-Identifier: GPL-2.0

/*
 *  fetchres.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "stdbool.h"
/* not accesed by other */

/* get message->from */
struct from {
        int                     id;
        bool                    is_bot;
        char                    *first_name;
        char                    *last_name;
        char                    *username;
        char                    *language_code;
};

/* get message->chat */
struct chat {
        int                     id;
        char                    *first_name;
        char                    *last_name;
        char                    *username;
        char                    *type;
};


/* get message */
struct message {
        int                     message_id;
        struct from             from;
        struct chat             chat;
        int                     date;
        char                    *text;
};


/* end */

#if !defined(tg_json_fetch_res_t)
        typedef struct tg_json_fetch_res {
                struct message         message;
        } tg_json_fetch_res_t ;
#endif