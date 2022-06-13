#include "fetchres.h"
#include <stdint.h>
#include <stdbool.h>

tg_json_getupdates_t* get_updates(ctg_utils_t *maindt, tg_json_getupdates_t *getupdates_res, int offset, int limit);
void* send_message(ctg_utils_t *maindt, \
        uint64_t        chat_id,   \
        char            *text,     \
        char            *parse_mode,     \
        bool            disable_web_page_preview
);