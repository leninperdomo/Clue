#include "items.h"

struct Item *item(char* name, char* description, int itemNumber, struct Item *next) {
        struct Item* newItem = (struct Item*) malloc(sizeof(struct Item));
        newItem->name = name;
        newItem->description = description;
	newItem->itemNumber = itemNumber;
        newItem->next = next;
        return newItem;
}

char* item_name(struct Item* node) {
         return node->name;
}

char* item_description(struct Item* node) {
        return node->description;
}

int item_number(struct Item* node) {
	return node->itemNumber;
}

struct Item* item_next(struct Item* node) {
        return node->next;
}

struct Item* search_item(struct Item *head, char* name) {
	/*
	struct Item* temp = *head_ref;
	while (temp != NULL) {
		if (strcmp(temp->name, name) == 0) {
			struct Item *itemCopy = item(temp->name, temp->description, temp->itemNumber, NULL);
			free(temp);
			return itemCopy;
		}
		temp = temp->next;
	}
	free(temp);
	return NULL;
	*/
	struct Item* current = head;  // Initialize current
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			return current;
		}
		current = current->next;
    }

	return NULL;
}

struct Item* add_item(struct Item **head_ref, struct Item* item) {

	struct Item *last = *head_ref;

	item->next = NULL;

	if (*head_ref == NULL) {
		*head_ref = item;
		return item;
	}

	while (last->next != NULL) {
		last = last->next;
	}

    	last->next = item;
	return item;
}

struct Item* drop_item(struct Item **head_ref, char* name) {

	struct Item* temp = *head_ref, *prev;

	if (temp != NULL && (strcmp(temp->name, name) == 0)) {
        	*head_ref = temp->next;
        	free(temp);
        	return *head_ref;
	}

	while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        	prev = temp;
        	temp = temp->next;
	}

	if (temp == NULL) return NULL;

	prev->next = temp->next;

	free(temp);
}
