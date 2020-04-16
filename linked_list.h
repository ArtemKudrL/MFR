#pragma once

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#define STRING_SIZE 0x20

typedef struct fields {
	char name[STRING_SIZE];
	char lastname[STRING_SIZE];
	int phone;
}fields;

typedef struct llist {
	fields field;
	llist *next;
}llist;

void init_list(llist **head);
void enter_element(llist **head);
void add_element(llist **head, fields field);
void insert_element(llist **head, fields field, int num);
void print_list(llist *head);
void delete_list(llist *head);