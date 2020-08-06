#ifndef BIGINT_H
#define BIGINT_H

#include "list.h"

typedef List Bigint;

void bigint_new(Bigint *bigint);

void bigint_copy(Bigint source, Bigint *destination);

void bigint_parse_hexstring(Bigint *bigint, char *hexstring);

void bigint_print(Bigint bigint);

void bigint_add(Bigint a, Bigint *b);

#endif
