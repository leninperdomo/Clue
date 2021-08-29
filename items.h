#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Item {
        char* name;
        char* description;
	int itemNumber;
        struct Item *next;
};

struct Item *item(char* name, char* description, int itemNumber, struct Item *next);

char* item_name(struct Item* node);

char* item_description(struct Item* node);

int item_number(struct Item* node);

struct Item* item_next(struct Item* node);

struct Item* search_item(struct Item *head_ref, char* name);

struct Item* add_item(struct Item **head_ref, struct Item* item);

struct Item* drop_item(struct Item **head_ref, char* name);
