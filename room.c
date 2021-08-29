#include "room.h"

struct Room *room(char* description, struct Item* items, struct Character* characters, int roomNumber, struct Room *north, struct Room *south,
                        struct Room *east, struct Room *west) {
        struct Room* newRoom = (struct Room*) malloc(sizeof(struct Room));
        newRoom->description = description;
        newRoom->items = items;
        newRoom->characters = characters;
	newRoom->roomNumber = roomNumber;
	newRoom->north = north;
        newRoom->south = south;
        newRoom->east = east;
        newRoom->west = west;
        return newRoom;
}

void room_exit_north(struct Room* current, struct Room* other) {
	current->north = other;
}

void room_exit_south(struct Room* current, struct Room* other) {
	current->south = other;
}

void room_exit_east(struct Room* current, struct Room* other) {
	current->east = other;
}

void room_exit_west(struct Room* current, struct Room* other) {
	current->west = other;
}
