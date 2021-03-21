#include <stdio.h>
#include "validators.h"
#include "parseutils.h"
#include "linkedlist.h"

#ifndef CIDR_COMPARISON_CIDR_H
#define CIDR_COMPARISON_CIDR_H

#endif //CIDR_COMPARISON_CIDR_H

struct ip {
    struct list_node node;
    int bit;
};

struct ip* new_ip(int bit, int type) {
    struct ip* a = (struct ip*)malloc(sizeof(struct ip));
    a->bit = bit;
    a->node.type = type;
    return a;
};

/******

void printList(int type) {
    struct list_node *ptr = head;

    printf("\n[head] =>");
    while (ptr != NULL) {
        if (ptr->type == type) {
            struct ip *n = (struct ip *) ptr;
            printf(" %d => ", n->bit);
        }
        ptr = ptr->next;
    }
    printf(" [null]\n");
};

******/

void toString(char *var[], int type) {
    struct list_node *ptr = head;
    char *str = malloc(100 * sizeof(char));

    while (ptr != NULL) {
        if (ptr->type == type) {
            struct ip *n = (struct ip *) ptr;
            char tmp[2];
            sprintf(tmp, "%d", n->bit);
            strcat(str, tmp);
        }
        ptr = ptr->next;
    }

    *var = str;
};

int *convert(int n, int type) {
    int *result;
    int rem, i = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        i *= 10;
        struct ip* entry = new_ip(rem, type);
        list_add_node((struct list_node*)entry);
    }
    return result;
};

int cidrcmp( char *ipa, char *ipb)  {
    list_init();

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
    convert(pre_a, 1);
    convert(pre_b, 2);

    toString(&a, 1);
    toString(&b, 2);

    return strcmp(a, b);
};