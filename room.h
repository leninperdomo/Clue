#include <stdio.h>
#include <stdlib.h>
#include "items.c"
#include "characters.c"

struct Room {
        char* description;
        struct Item* items;
	struct Character* characters;
	int roomNumber;
        struct Room *north;
        struct Room *south;
        struct Room *east;
        struct Room *west;
};

struct Room *room(char* description, struct Item* items, struct Character* characters, int roomNumber, struct Room *north, struct Room *south,
			struct Room *east, struct Room *west);

void room_exit_north(struct Room* current, struct Room* other);

void room_exit_south(struct Room* current, struct Room* other);

void room_exit_east(struct Room* current, struct Room* other);

void room_exit_west(struct Room* current, struct Room* other);
