// SPDX-License-Identifier: GPL-2.0

/*  
 *  test file: http_build_query.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include "fcntl.h"
#include "limits.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include <string.h>

typedef struct key_val {
        char *key;
        char *value;
} key_value_t;
int countinsert;

void insert_key_value(key_value_t *keyval, char *key, char *value)
{
        keyval[countinsert].key = key;
        keyval[countinsert].value = value;

        countinsert += 1;
}
/*
 * sumber : https://github.com/php/php-src/blob/23961ef382e1005db6f8c08f3ecc0002839388a7/ext/standard/url.c#L459-L555
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
        char *buffresd = (char*) malloc(sizeof(char) * (4096 + 50 + strlen("=&") + 200));
	char *urlencodedata_key = (char*) malloc(sizeof(char) * 50); // key just use < 50. no telegram method use > 50 char
	char *urlencodedata_value = (char*) malloc(sizeof(char) * 4096); // max of telegram text 
	char temp[4096 + 50 + strlen("=&") + 200]; // add 200 for handle space result from encoded url
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

int main()
{
        key_value_t data[2];
	char *res = int_to_string_alloc(9);
        insert_key_value(data, "tes faddhils", res); // segvault
	insert_key_value(data, "tes 2", "set2");
	char *pp = http_build_query(data, sizeof(data) / sizeof(data[0]));
        fprintf(stdout, "%s", pp);
	free(pp);
	free(res);
}