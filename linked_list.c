#include "linked_list.h"

void init_list(llist **list) {
	*list = NULL;
}

void enter_element(llist **list) {
	llist *temp = (llist *)malloc(sizeof(llist));
	printf_s("name: ");
	scanf_s("%s", temp->field.name, STRING_SIZE);
	printf_s("lastname: ");
	scanf_s("%s", temp->field.lastname, STRING_SIZE);
	printf_s("phone: ");
	scanf_s("%d", &(temp->field.phone));
	printf_s("\n");
	temp->next = *list;
	*list = temp;
}

void add_element(llist **list, fields new_data) {
	llist *temp = (llist *)malloc(sizeof(llist));
	temp->field = new_data;
	temp->next = *list;
	*list = temp;
}

void insert_element(llist **list, fields new_data, int num) {
	llist *temp = (llist *)malloc(sizeof(llist));
	temp->field = (*list)->field;
	temp->next = *list;

	for (int i = 0; i < num; ++i) {
		(*list)->field = (*list)->next->field;
		(*list) = &((*list)->next);
	}

	(*list)->field = new_data;
}

void print_list(llist *list) {
	printf_s("list: \nname, lastname, phone:\n");
	while (list != NULL) {
		printf_s("%s %s %d\n", list->field.name, list->field.lastname, list->field.phone);
		list = list->next;
	};
}

void delete_list(llist *list) {
	llist *next = list;
	while ( next != NULL) {
		list = list->next;
		free(next);
		next = list;
	}
}