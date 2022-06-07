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
char *http_build_query(key_value_t *data_arr_keyval, size_t len_arr)
{
        char *buffresd = (char*) malloc(sizeof(char) * 4094);
	char *urlencodedata_key = (char*) malloc(sizeof(char) * 4094);
	char *urlencodedata_value = (char*) malloc(sizeof(char) * 4094);
	char temp[300];
	char *data;
	data = temp;
        for(int a = 0; a < len_arr; a++) {
		urlencode(urlencodedata_key, data_arr_keyval[a].key, strlen(data_arr_keyval[a].key), false);
		urlencode(urlencodedata_value, data_arr_keyval[a].value, strlen(data_arr_keyval[a].value), false);
		if (a == (len_arr - 1)) {
			sprintf(data, "%s=%s", urlencodedata_key, urlencodedata_value);
			strcat(buffresd , data);
		} else {
			sprintf(data, "%s=%s&", urlencodedata_key, urlencodedata_value);
			strcat(buffresd , data);
	 	}
        }
	free(urlencodedata_key);
	free(urlencodedata_value);
        return buffresd;
}