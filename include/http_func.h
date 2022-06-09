#include "stdbool.h"
#include "key_value.h"

char *http_build_query(key_value_t *data_arr_keyval, size_t len_arr);
char *urlencode(char *alloc, const char *s, size_t len, bool raw);