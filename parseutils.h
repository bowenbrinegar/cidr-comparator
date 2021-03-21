//
// Created by Bowen Brinegar on 3/21/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

#ifndef CIDR_COMPARISON_PARSEUTILS_H
#define CIDR_COMPARISON_PARSEUTILS_H

#endif //CIDR_COMPARISON_PARSEUTILS_H

int concatints(int a, int b)
{
    char s1[20];
    char s2[20];

    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    strcat(s1, s2);
    char *ptr;
    return (int) strtol(s1, &ptr, 10);;
}

int first_digit(int digit) {
    int first = digit;

    while(first >= 10) {
        first = first / 10;
    }

    return first;
}