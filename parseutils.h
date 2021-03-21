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


int atoiloc(const char* str){
    int num = 0;
    int i = 0;
    bool isNegetive = false;
    if(str[i] == '-'){
        isNegetive = true;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')){
        num = num * 10 + (str[i] - '0');
        i++;
    }
    if(isNegetive) num = -1 * num;
    return num;
}

int concatints(int a, int b)
{

    char s1[20];
    char s2[20];

    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    strcat(s1, s2);

    int c = atoiloc(s1);
    return c;
}

/******

int parse_ip(const char *ip) {
    char parsed[15] = "";
    int count = 0;
    for (int i = 0; ip[i] != '\0'; i++) {
        if (ip[i] != '.') {
            parsed[count] = ip[i];
            count++;
        }
    }
    char *ptr;

    return (int) strtol(parsed, &ptr, 10);
}

******/

int first_digit(int digit) {
    int first = digit;

    while(first >= 10) {
        first = first / 10;
    }

    return first;
}