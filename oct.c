#include <string.h>
#include <stdlib.h>
#include "oct.h"
#include "reverse.h"

int oct_to_dec(char *oct) {
    int dec = 0;
    int i = 0;
    int sign;

    if (oct[0] == '-') {
        sign = -1;
        i = 1;
    } else {
        sign = 1;
    }

    while (oct[i] != '\0') {
        if (oct[i] == '\n') {
            break;
        }
        dec = dec * 8;
        dec = dec + (oct[i] - '0');
        i++;
    }
    return dec * sign;
}

char *dec_to_oct(int dec) {
    char* oct = malloc(128);
    memset(oct, 0, 128);

    int sign = dec >= 0 ? 1 : -1;
    dec = dec < 0 ? -dec : dec;

    int i;
    if (sign == -1) {
        oct[0] = '-';
        i = 1;
    } else {
        i = 0;
    }

    while (dec != 0) {
        oct[i] = dec % 8 + '0';
        i++;
        dec = dec / 8;
    }

    oct[i] = '\0';
    return strreverse(oct);
}

char* bnot_oct(char *oct) {
    int dec = oct_to_dec(oct);
    int bnot = ~dec;
    char* res = dec_to_oct(bnot);
    return res;
}
