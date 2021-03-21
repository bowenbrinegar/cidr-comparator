//
// Created by Bowen Brinegar on 3/21/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

#ifndef CIDR_COMPARISON_VALIDATORS_H
#define CIDR_COMPARISON_VALIDATORS_H

#endif //CIDR_COMPARISON_VALIDATORS_H


int validate_ip(char *c) {
    regex_t re;
    int value = regcomp(&re, "^(([0-9]{3}|[0-9]{1,3}|[0-9]{1,3})\\.){3}([0-9]){1,3}(\\/[0-9]{1,2})$", REG_EXTENDED);
    int status = regexec(&re, c, (size_t) 0, NULL, 0);

    if (value == 0) {
        printf("\nRegEx compiled successfully.\n");
    }
    else {
        printf("\nCompilation error.\n");
    }

    return status;
}