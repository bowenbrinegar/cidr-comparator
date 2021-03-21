//
// Created by Bowen Brinegar on 3/21/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>

#ifndef CIDR_COMPARISON_LINKEDLIST_H
#define CIDR_COMPARISON_LINKEDLIST_H

#endif //CIDR_COMPARISON_LINKEDLIST_H

struct list_node {
    struct list_node *next;
    int type;
};

struct list_node* head;
struct list_node* tail;

void list_init() {
    head=tail=NULL;
}

void list_add_node(struct list_node* node) {
    if (NULL==tail) {
        head=tail=node;
        node->next=NULL;
    } else {
        tail->next=node;
        node->next=NULL;
        tail=node;
    }
}

struct list_node* list_get_next(struct list_node* node) {
    if (NULL==node)
        return head;
    else
        return node->next;
};


