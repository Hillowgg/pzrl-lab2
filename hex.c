#include <string.h>
#include <stdlib.h>
#include "reverse.h"
#include "hex.h"

int hex_to_dec(char *hex) {
    int dec = 0;
    int i = 2;
    int sign;

    if (hex[0] == '-') {
        sign = -1;
        i = 3;
    } else {
        sign = 1;
    }

    while (hex[i] != '\0') {
        if (hex[i] == '\n') {
            break;
        }
        dec = dec * 16;
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec = dec + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec = dec + (hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec = dec + (hex[i] - 'a' + 10);
        }
        i++;
    }
    return dec * sign;
}

char *dec_to_hex(int dec) {
    char* hex = malloc(128);
    memset(hex, 0, 128);
    int sign = dec >= 0 ? 1 : -1;
    dec = dec < 0 ? -dec : dec;
    int i;

    if (sign == -1) {
        hex[0] = '-';
        i = 1;
    } else {
        i = 0;
    }



    while (dec != 0) {
        int tmp = dec % 16;

        if (tmp < 10) {
            hex[i] = tmp + '0';
            i++;
        } else {
            hex[i] = tmp + 'a' - 10;
            i++;
        }
        dec = dec / 16;
    }
    hex[i] = 'x';
    hex[i + 1] = '0';
    hex[i + 2] = '\0';
    return strreverse(hex);
}

char* bnot_hex(char *hex) {
    int dec = hex_to_dec(hex);
    int bnot = ~dec;
    char* res = dec_to_hex(bnot);
    return res;
}