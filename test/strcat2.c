// SPDX-License-Identifier: GPL-2.0

/*
 *  strcat2.c
 *  Copyright (C) Fadhil Riyanto
 *
 *  https://github.com/fadhil-riyanto/ctg.git
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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

int main() 
{
        char *bufff[200];
        urlencode(bufff, "hai a", strlen("hai a"), false);
        printf(bufff);
}