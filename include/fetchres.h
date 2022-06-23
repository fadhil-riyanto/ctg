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

#include <cstdint>
#include <stdbool.h>
#include <stdint.h>
/* not accesed by other */
/* can use as global types */

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
                int64_t                 id;
                const char              *first_name;
                const char              *last_name;
                const char              *username;
                const char              *type;
        } chat_t ;
#endif

/* get message->sticker->thumb */
#if !defined(thumb) || !defined(thumb_t)
        typedef struct thumb {
                const char              *file_id;
                const char              *file_unique_id;
                int                     file_size;
                int                     width;
                int                     height;
        } thumb_t;
#endif

/* get message->sticker */
#if !defined(sticker) || !defined(sticker_t)
        typedef struct sticker {
                int                     width;
                int                     height;
                const char              *emoji;
                const char              *set_name;
                bool                    is_animated;
                bool                    is_video;
                thumb_t                 thumb;
                const char              *file_id;
                const char              *file_unique_id;
                int                     file_size;
        } sticker_t;
#endif


/* get message->entities */
#if !defined(entities) || !defined(entities_t)
        typedef struct entities {
                int                     offset;
                int                     length;
                const char              *type;
        } entities_t;

#endif

/* get message */
#if !defined(message) || !defined(message_t)
        typedef struct message {
                int                     message_id;
                from_t                  from;
                chat_t                  chat;
                uint64_t                date;
                sticker_t               sticker;
                const char              *text;
                entities_t              entities[100]; // max 100 in telegram

        } message_t ;
#endif

/* end */

#if !defined(tg_json_getupdates_t) || !defined(tg_json_getupdates)
        typedef struct tg_json_getupdates {
                message_t               message;
                int                     update_id;
        } tg_json_getupdates_t ;
#endif


/*
 * for json response
 * only can accesed from main struct
 */

struct from_res {
        int64_t                 id;
        bool                    is_bot;
        const char              *first_name;
        const char              *username;
};
struct chat_res {
        int64_t                 id;
        const char              *first_name;
        const char              *username;
        const char              *type;
};

typedef struct tg_json_res {
        struct from_res         message;
        struct chat_res         chat;
        int64_t                 date;
        int                     update_id;
} tg_json_res_t ;



#endif