#include "sodium.h"
#include <stdio.h>
#define SHORT_DATA ((const unsigned char *) "Sparkling water")
#define SHORT_DATA_LEN 15

unsigned char hash[crypto_shorthash_BYTES];
unsigned char key[crypto_shorthash_KEYBYTES];

crypto_shorthash_keygen(key);
crypto_shorthash(hash, SHORT_DATA, SHORT_DATA_LEN, key);