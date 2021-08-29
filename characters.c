#include "characters.h"

struct Character *character(char* name, char* description, int characterNumber, struct Character *next) {
        struct Character* newCharacter = (struct Character*) malloc(sizeof(struct Character));
        newCharacter->name = name;
        newCharacter->description = description;
	newCharacter->characterNumber = characterNumber;
        newCharacter->next = next;
        return newCharacter;
}

char* character_name(struct Character* node) {
	return node->name;
}

char* character_description(struct Character* node) {
	return node->description;
}

int character_number(struct Character* node) {
	return node->characterNumber;
}

struct Character* character_next(struct Character* node) {
	return node->next;
}

//NOTE: move_character implemented in "adventure.c"
