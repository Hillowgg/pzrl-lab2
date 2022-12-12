#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bin.h"
#include "oct.h"
#include "hex.h"

typedef enum {
    BIN = 2,
    OCT = 8,
    HEX = 16
} Ebase;

Ebase get_type(char *str) {
    if (str[0] == '0' && str[1] == 'x') {
        return HEX;
    } else if (str[0] == '0') {
        return OCT;
    } else {
        return BIN;
    }
}

void print_res(int res, Ebase type) {
    char* str;
    switch (type) {
        case BIN:
            str = dec_to_bin(res);
            printf("%s (%d)\n", str, res);

            break;
        case OCT:
            str = dec_to_oct(res);
            printf("%s (%d)\n", str, res);
            break;
        case HEX:
            str = dec_to_hex(res);
            printf("%s (%d)\n", str, res);
            break;
    }
    free(str);
}

int main() {
    int num1, num2;
    Ebase type1;
    Ebase type2;

    char *str = NULL;
    size_t len = 0;

    printf("Введите числа: \n");
    getline(&str, &len, stdin);

    char **split_str = (char **) malloc(100 * sizeof(char *));
    split_str[0] = strtok(str, " ");
    int counter = 0;
    size_t t;
    while (split_str[counter] != NULL) {
        counter++;
        split_str[counter] = strtok(NULL, " ");
//        if (split_str[counter][strlen(split_str[counter]) - 1] == '\n') {
//            split_str[counter][strlen(split_str[counter]) - 1] = '\0';
//        }
    }

    int res;

    if (counter == 1) {
        type1 = get_type(&split_str[0][1]);

        switch (type1) {
            case BIN:
                res = bin_to_dec(bnot_bin(&split_str[0][1]));
                break;
            case OCT:
                res = oct_to_dec(bnot_oct(&split_str[0][1]));
                break;
            case HEX:
                res = hex_to_dec(bnot_hex(&split_str[0][1]));
                break;
        }

        print_res(res, type1);
        return 0;
    }

    type1 = get_type(split_str[0]);
    type2 = get_type(split_str[2]);

    if (type1 != type2) {
        printf("Ошибка: системы счисления не совпадают");
        return 1;
    }

    if (type1 == BIN) {
        num1 = bin_to_dec(split_str[0]);
        num2 = bin_to_dec(split_str[2]);
    } else if (type1 == OCT) {
        num1 = oct_to_dec(split_str[0]);
        num2 = oct_to_dec(split_str[2]);
    } else {
        num1 = hex_to_dec(split_str[0]);
        num2 = hex_to_dec(split_str[2]);
    }


    switch (split_str[1][0]) {
        case '+':
            res = num1 + num2;
            break;
        case '-':
            res = num1 - num2;
            break;
        case '*':
            res = num1 * num2;
            break;
        case '%':
            res = num1 % num2;
            break;
        case '&':
            res = num1 & num2;
            break;
        case '|':
            res = num1 | num2;
            break;
        case '^':
            res = num1 ^ num2;
            break;
    }

    print_res(res, type1);

    return 0;
}