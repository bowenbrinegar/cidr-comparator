#include <stdio.h>
#include "validators.h"
#include "parseutils.h"

#ifndef CIDR_COMPARISON_CIDR_H
#define CIDR_COMPARISON_CIDR_H

#endif //CIDR_COMPARISON_CIDR_H

void convert(char *var[], int n) {
    int rem, i = 1;
    char *str = malloc(100 * sizeof(char));

    while (n != 0) {
        rem = n % 2;
        n /= 2;
        i *= 10;
        char tmp[2];
        sprintf(tmp, "%d", rem);
        strcat(str, tmp);
    }

    *var = str;
}

int cidrcmp( char *ipa, char *ipb)  {
    if (validate_ip_wfilter(ipa) == 1) {
        printf("Invalid IP Address Entry (Regex Matching Error)\n");
        exit(1);
    } else {
        printf("Entry (A) Valid\n");
    }


    if (validate_ip(ipb) == 1) {
        printf("Invalid IP Address Entry (Regex Matching Error)\n");
        exit(1);
    } else {
        printf("Entry (B) Valid\n");
    }

    int w, x, y, z, bitCount, n_visits;
    int check_a = sscanf(ipa, "%d.%d.%d.%d/%d", &w, &x, &y, &z, &bitCount);
    if (check_a != 5) {
        printf("Invalid IP Address Entry (Parsing Error => IP A)\n");
        exit(1);
    }

    int e, f, g, h;
    int check_b = sscanf(ipb, "%d.%d.%d.%d", &e, &f, &g, &h);
    if (check_b != 4) {
        printf("Invalid IP Address Entry (Parsing Error => IP B)\n");
        exit(1);
    }

    int pre_a, pre_b;

    if (bitCount == 1) {
        n_visits = 0;
        pre_a = first_digit(e);
        pre_b = first_digit(w);
    }
    else if (bitCount % 8 == 0) {
        n_visits = bitCount / 8;
        switch (n_visits) {
            case 1:
                pre_a = e;
                pre_b = w;
                break;
            case 2:
                pre_a = concatints(e, f);
                pre_b = concatints(w, x);
                break;
            case 3:
                pre_a = concatints(concatints(e, f), g);
                pre_b = concatints(concatints(w, x), y);
                break;
            default:
                pre_a = concatints(concatints(e, f), concatints(g, h));
                pre_b = concatints(concatints(w, x), concatints(y, z));
        }
    }
    else {
        printf("Invalid IP Address Entry (Bit Signature)\n");
        exit(1);
    }

    char *a, *b;
    convert(&a, pre_a);
    convert(&b, pre_b);
    return strcmp(a, b);
};