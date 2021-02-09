#ifndef TODO_H
#define TODO_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    const char* name;
    const char* description;
}Element;

typedef struct List {
    Element data;
    struct List *prev; struct List *next;
}List;

const char *list_name;

extern void display_list(List *head);
extern void create_list(const char *name, List *list);
extern List *add_list(Element item, List *list);
extern List *delete_list(Element item, List* list);
#endif /* TODO_H */