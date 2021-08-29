#include <stdio.h>
#include <stdlib.h>
struct Character {
        char* name;
        char* description;
	int characterNumber;
        struct Character *next;
};

struct Character *character(char* name, char* description, int characterNumber, struct Character *next);

char* character_name(struct Character* node);

char* character_description(struct Character* node);

int character_number(struct Character* node);

struct Character* character_next(struct Character* node);

//NOTE: move_character implemented in "adventure.c"
