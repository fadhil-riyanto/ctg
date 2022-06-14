#include "http_func.h"

/*
 * source : https://github.com/php/php-src/blob/23961ef382e1005db6f8c08f3ecc0002839388a7/ext/standard/url.c#L459-L555
 * thanks!
 */
char *urlencode(char *alloc, const char *s, size_t len, bool raw)
{
	static const unsigned char hexchars[] = "0123456789ABCDEF";
	register unsigned char c;
	unsigned char *to;
	unsigned char const *from, *end;
	char *start;

	from = (const unsigned char *)s;
	end = (const unsigned char *)s + len;

	if (alloc == NULL) {
		start = malloc((len * 3ul) + 1ul);
	} else {
		start = alloc;
	}

	to = (unsigned char *)start;

	while (from < end) {
		c = *from++;

		if (!raw && c == ' ') {
			*to++ = '+';
		} else if ((c < '0' && c != '-' && c != '.') ||
				(c < 'A' && c > '9') ||
				(c > 'Z' && c < 'a' && c != '_') ||
				(c > 'z' && (!raw || c != '~'))) {
			to[0] = '%';
			to[1] = hexchars[c >> 4];
			to[2] = hexchars[c & 15];
			to += 3;
		} else {
			*to++ = c;
		}
	}
	*to = '\0';

	return start;
}

/*
 * thanks for om alviro iskandar
 * https://t.me/tgdev_id/130512
 */
char *http_build_query(key_value_t *data, size_t len_arr)
{
        char *buffer, *tmp;
        size_t alloc = 4096;
        size_t total = 0;
        size_t need_len = 0;
        size_t i;

        buffer = malloc(alloc);
        if(!buffer) {
                return NULL; // maybe no memory
        }

        for(i = 0; i < len_arr; i++) {
                size_t key_len, val_len;

                key_len = strlen(data[i].key);
                val_len = strlen(data[i].value);

                need_len += (key_len * 3) + (val_len * 3) + 3;
                if(alloc <= need_len) {
                        alloc += (alloc * 2) + need_len;
                        tmp = realloc(buffer, alloc);
                        if(!tmp) {
                                free(buffer);
                                return NULL;
                        }
                        buffer = tmp; // paste new memory
                }

                urlencode(&buffer[total], data[i].key, key_len, false);
                // encode the key first
                total += strlen(&buffer[total]); 
                // get offset
                buffer[total++] = '='; // increment 1 of last offset
                urlencode(&buffer[total], data[i].value, val_len, false);

                total += strlen(&buffer[total]);
                // get the last offset
                // check if the literation now < of arr len, - 1 means make 
                // array len same as array alloc. started from 0
                if (i < len_arr - 1)
			buffer[total++] = '&';
                
        }
        buffer[total] = '\0'; // add termination string
        return buffer;
}