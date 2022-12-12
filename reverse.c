#include <string.h>
#include <stdlib.h>

#include "reverse.h"


char *strreverse(const char *str1) {
    if (str1 == NULL) {
        return NULL;
    }
    int len = strlen(str1);
    char* new = malloc((len + 1) * sizeof(char));
    memset(new, '\0', len + 1);

    for (int i = 0; i < len; ++i) {
        new[len - i - 1] = str1[i];
    }
    return new;
}