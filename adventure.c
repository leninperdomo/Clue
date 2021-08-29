#include "room.c"
#include <time.h>
#include <string.h>
void help() {
	printf("\nCommand List:\n");
	printf("help: Displays list of commands\n");
	printf("list: Look up lists of items, rooms, and characters\n");
	printf("look: See characters, items, and exits in player's current room\n");
	printf("go DIRECTION: Move avatar to room in DIRECTION (North, South, East, or West)\n");
	printf("take ITEM: Pick up an ITEM in the room\n");
	printf("drop ITEM: Drop ITEM from inventory\n");
	printf("inventory: Check items in inventory\n");
	printf("clue CHARACTER: Make a guess about the CHARACTER\n");
	printf("quit: Exit game immediately\n");
}

//Used for the list command
void list(struct Room *randomRoomList[9], struct Item *randomItemList[6], struct Character *randomCharacterList[5]) {
	//Print rooms
	printf("Rooms:\n");
	for (int i = 0; i < 9; i++) {
		printf("%s\n", randomRoomList[i]->description);
	}

	//Print items
        printf("\nItems:\n");
        for (int i = 0; i < 6; i++) {
                printf("%s\n", randomItemList[i]->name);
        }

	//Print characters
        printf("\nCharaters:\n");
        for (int i = 0; i < 5; i++) {
                printf("%s\n", randomCharacterList[i]->name);
        }
}

//Used for the look command
void look(struct Room *randomRoomList[9], int avatarLocation) {
	printf("Room: %s\n", randomRoomList[avatarLocation]->description);
        if (randomRoomList[avatarLocation]->items != NULL) {
        	printf("\nItem: %s\n", randomRoomList[avatarLocation]->items->name);
        }
	else {
		printf("\nItem: \n");
	}
        if (randomRoomList[avatarLocation]->characters != NULL) {
        	printf("\nCharacter: %s\n", randomRoomList[avatarLocation]->characters->name);
        }
	else {
		printf("\nCharacter: \n");
	}
}

//Used for the goDIRECTION command
int goDIRECTION(int avatarLocation, char* direction) {
	int validLocation = 1;

	if (strcmp(direction, "NORTH") == 0) {
		if ((avatarLocation != 0) && (avatarLocation != 1) && (avatarLocation != 2)) {
			avatarLocation -= 3;
		} else {
			validLocation = -1;
		}
	} else if (strcmp(direction, "SOUTH") == 0) {
                if ((avatarLocation != 6) && (avatarLocation != 7) && (avatarLocation != 8)) {
                        avatarLocation += 3;
                } else {
                        validLocation = -1;
                }
        } else if (strcmp(direction, "EAST") == 0) {
                if ((avatarLocation != 2) && (avatarLocation != 5) && (avatarLocation != 8)) {
                        avatarLocation += 1;
                } else {
                        validLocation = -1;
                }
        } else if (strcmp(direction, "WEST") == 0) {
                if ((avatarLocation != 0) && (avatarLocation != 3) && (avatarLocation != 6)) {
                        avatarLocation -= 1;
                } else {
                        validLocation = -1;
                }
        } else {
		validLocation = -1;
		printf("\nINVALID LOCATION\n");
		printf("VALID LOCATIONS: NORTH, SOUTH, EAST, AND WEST\n");
		return validLocation;
	}

	if (validLocation == -1) {
		printf("\n\nThere are no rooms in that direction, please choose a different one.\n");
		return validLocation;
	}

	return avatarLocation;
}

//Used to move character to a different room
void move_character(struct Room *randomRoomList[9], int avatarLocation, int characterLocation) {
	struct Character *tempCharacter = randomRoomList[characterLocation]->characters;
	randomRoomList[characterLocation]->characters = randomRoomList[avatarLocation]->characters;
	randomRoomList[avatarLocation]->characters = tempCharacter;
}

//Used to search items in inventory for item with an itemNumber that matches the searchNumber
struct Item *searchInventoryNumber(struct Item *inventory, int searchNumber) {
        if (inventory != NULL) {
                if (inventory->itemNumber == searchNumber) {
                        struct Item *itemCopy = item(inventory->name, inventory->description, inventory->itemNumber, NULL);
                        return itemCopy;
                }

		else if (inventory->next != NULL) {
                	if (inventory->next->itemNumber == searchNumber) {
                        	struct Item *itemCopy = item(inventory->next->name, inventory->next->description, inventory->next->itemNumber, NULL);
                        	return itemCopy;
                	}

			else if (inventory->next->next != NULL) {
                		if (inventory->next->next->itemNumber == searchNumber) {
                        		struct Item *itemCopy = item(inventory->next->next->name, inventory->next->next->description,
                                        inventory->next->next->itemNumber, NULL);
                        		return itemCopy;
                		}

				else if (inventory->next->next->next != NULL) {
                			if (inventory->next->next->next->itemNumber == searchNumber) {
                        			struct Item *itemCopy = item(inventory->next->next->next->name,
						inventory->next->next->next->description,
                                                inventory->next->next->next->itemNumber, NULL);
                        			return itemCopy;
                			}

					else if (inventory->next->next->next->next != NULL) {
                				if (inventory->next->next->next->next->itemNumber == searchNumber) {
                        				struct Item *itemCopy = item(inventory->next->next->next->next->name,
							inventory->next->next->next->next->description,
                                                        inventory->next->next->next->next->itemNumber, NULL);
                        				return itemCopy;
                				}

						else if (inventory->next->next->next->next->next != NULL) {
                					if (inventory->next->next->next->next->next->itemNumber == searchNumber) {
                        					struct Item *itemCopy = item(inventory->next->next->next->next->next->name,
                                                        	inventory->next->next->next->next->next->description,
                                                        	inventory->next->next->next->next->next->itemNumber, NULL);
                        					return itemCopy;
                					}
        					}
        				}
        			}
        		}
        	}
        }
        return NULL;
}

//Used to search items in inventory for item with a name that matches the searchName
struct Item *searchInventory(struct Item *inventory, char* searchName) {
        if (inventory != NULL) {
                if (strcmp(inventory->name, searchName) == 0) {
                        struct Item *itemCopy = item(inventory->name, inventory->description, inventory->itemNumber, NULL);
                        return itemCopy;
                }

                else if (inventory->next != NULL) {
                        if (strcmp(inventory->next->name, searchName) == 0) {
                                struct Item *itemCopy = item(inventory->next->name, inventory->next->description, inventory->next->itemNumber, NULL);
                                return itemCopy;
                        }

                        else if (inventory->next->next != NULL) {
                                if (strcmp(inventory->next->next->name, searchName) == 0) {
                                        struct Item *itemCopy = item(inventory->next->next->name, inventory->next->next->description,
                                        inventory->next->next->itemNumber, NULL);
                                        return itemCopy;
                                }

                                else if (inventory->next->next->next != NULL) {
                                        if (strcmp(inventory->next->next->next->name, searchName) == 0) {
                                                struct Item *itemCopy = item(inventory->next->next->next->name,
                                                inventory->next->next->next->description,
                                                inventory->next->next->next->itemNumber, NULL);
                                                return itemCopy;
                                        }

					else if (inventory->next->next->next != NULL) {
                                        	if (strcmp(inventory->next->next->next->name, searchName) == 0) {
                                                	struct Item *itemCopy = item(inventory->next->next->next->name,
                                                	inventory->next->next->next->description,
                                                	inventory->next->next->next->itemNumber, NULL);
                                                	return itemCopy;
                                        	}

                                        	else if (inventory->next->next->next->next != NULL) {
                                                	if (strcmp(inventory->next->next->next->next->name, searchName) == 0) {
                                                        	struct Item *itemCopy = item(inventory->next->next->next->next->name,
                                                        	inventory->next->next->next->next->description,
                                                        	inventory->next->next->next->next->itemNumber, NULL);
                                                        	return itemCopy;
                                                	}

                                                	else if (inventory->next->next->next->next->next != NULL) {
                                                        	if (strcmp(inventory->next->next->next->next->next->name, searchName) == 0) {
                                                                	struct Item *itemCopy = item(inventory->next->next->next->next->next->name,
                                                                	inventory->next->next->next->next->next->description,
                                                                	inventory->next->next->next->next->next->itemNumber, NULL);
                                                                	return itemCopy;
                                                        	}
                                                	}
                                        	}
                                	}
				}
			}
		}
	}
	return NULL;
}

//Used to get the name of the room answer based on the roomAnswer number parameter
char* getRoomAnswer(struct Room *randomRoomList[9], int roomAnswer) {
	for (int i = 0; i < 9; i++) {
		if (randomRoomList[i]->roomNumber == roomAnswer) {
			return randomRoomList[i]->description;
		}
	}
	return NULL;
}

//Used to get the name of the item answer based on the itemAnswer number parameter
char* getItemAnswer(struct Item *inventory, struct Item *randomItemList[6], int itemAnswer) {
for (int i = 0; i < 6; i++) {
                if (randomItemList[i]->itemNumber == itemAnswer) {
                        return randomItemList[i]->name;
                }

		struct Item *inventoryClue = searchInventoryNumber(inventory, itemAnswer);

		if (inventoryClue != NULL) {
			return inventoryClue->name;
		}
        }
        return NULL;
}

//Used to generate a clue statement based on the room and item answers
void generateClue(char* roomAnswer, char* itemAnswer) {
	printf("\nClues: \n");

	if (strcmp(roomAnswer, "Library") == 0) {
		printf("The victim was known to be an avid reader.\n");
	}
	else if (strcmp(roomAnswer, "Kitchen") == 0) {
                printf("The victim's cooking was considered to be largely unrivaled.\n");
        }
	else if (strcmp(roomAnswer, "Balcony") == 0) {
                printf("The victim had a habit of meditating outside.\n");
        }
	else if (strcmp(roomAnswer, "Study") == 0) {
                printf("The victim spent most of the time working.\n");
        }
	else if (strcmp(roomAnswer, "Basement") == 0) {
                printf("The victim was known to be highly reclusive.\n");
        }
	else if (strcmp(roomAnswer, "Bathroom") == 0) {
                printf("The victim was slightly obsessed with proper hygiene.\n");
        }
	else if (strcmp(roomAnswer, "Artroom") == 0) {
                printf("The victim had recently begun to take art classes.\n");
        }
	else if (strcmp(roomAnswer, "Bedroom") == 0) {
                printf("The victim had contracted a strong fever before dying.\n");
        }
	else if (strcmp(roomAnswer, "Attic") == 0) {
                printf("The victim was not seen in any of the main rooms before dying.\n");
        }

	if (strcmp(itemAnswer, "Plate") == 0) {
		printf("There where broken pieces of glass found near the body.\n");
	}
	else if (strcmp(itemAnswer, "Broomstick") == 0) {
                printf("The body was covered in dust when it was found.\n");
        }
	else if (strcmp(itemAnswer, "Dictionary") == 0) {
                printf("There were pieces of paper in body's hand.\n");
        }
	else if (strcmp(itemAnswer, "Knife") == 0) {
                printf("There was a large hole in the body's back when it was found.\n");
        }
	else if (strcmp(itemAnswer, "Needle") == 0) {
                printf("There were numerous punctures in the body's neck.\n");
        }
	else if (strcmp(itemAnswer, "Cigar") == 0) {
                printf("The body had a strong stench of smoke when it was found.\n");
        }
}

//Used for the clueCHARACTER command
int clueCHARACTER(char* characterName, struct Room *randomRoomList[9], int avatarLocation, int roomAnswer, int characterAnswer, int itemAnswer, struct Item *inventory) {
	int matchCount = 0;
	int i;
	int swapCheck = 0;
	for (i = 0; i < 9; i++) {
		if (randomRoomList[i]->characters != NULL) {
			if (strcmp(randomRoomList[i]->characters->name, characterName) == 0) {
				move_character(randomRoomList, avatarLocation, i);
				swapCheck = 1;
				break;
                	}
		}
	}

	if (swapCheck != 1) {
		printf("\nCharacter not found.\n");
		return -1;
	}

	if (randomRoomList[avatarLocation]->roomNumber == roomAnswer) {
		printf("\nRoom Match\n");
                matchCount++;
	}

	if (randomRoomList[avatarLocation]->characters != NULL) {
		if (randomRoomList[avatarLocation]->characters->characterNumber == characterAnswer) {
 	              	printf("\nCharacter Match\n");
                	matchCount++;
		}
	}

	if (randomRoomList[avatarLocation]->items != NULL) {
		if (randomRoomList[avatarLocation]->items->itemNumber == itemAnswer) {
                	printf("\nItem Match\n");
  	            	matchCount++;
        	}
	}

	struct Item *correctItem = searchInventoryNumber(inventory, itemAnswer);
	if (correctItem != NULL) {
		printf("\nItem Match\n");
                matchCount++;
	}

        return matchCount;
}

//Used for the inventory command
void printInventory(struct Item *inventory) {
	struct Item *temp = inventory;
	printf("Inventory: ");
	while (temp != NULL) {
		printf("%s, ", temp->name);
		temp = temp->next;
	}
	printf("\n");
}

//Used to check if the given item name resides in the avatar's inventory
int inventoryListCheck(char* itemName, char* inventoryList[6]) {
	for (int i = 0; i < 6; i++) {
		if (strcmp(inventoryList[i], itemName) == 0) {
			return 1;
		}
	}
	return 0;
}

//Used to delete an element in the inventory array
void deleteInventoryElement(char* inventoryList[6], int deleteIndex) {
        inventoryList[deleteIndex] = NULL;
        int i;
        for (i = deleteIndex; i < 5; i++) {
                inventoryList[i] = inventoryList[i+1];
        }

        inventoryList[i] = NULL;
}

//Used to generate random room numbers
void generateRandomArray(int randomArray[9]) {
        time_t t;

        srand((unsigned) time(&t));

        int numberCheck[9] = {0,0,0,0,0,0,0,0,0};
        int i = 0;
        while ((i < 9)) {
                int random = ((rand() % 9) + 1);
                if (numberCheck[random - 1] != 1) {
                        randomArray[i] = random;
                        numberCheck[random - 1] = 1;
                        i++;
                }
        }
}

//Used to generate random item numbers
void generateRandomItemArray(int randomArray[6]) {
        int numberCheck[6] = {0,0,0,0,0,0};
        int i = 0;
        while ((i < 6)) {
                int random = ((rand() % 6) + 1);
                if (numberCheck[random - 1] != 1) {
                        randomArray[i] = random;
                        numberCheck[random - 1] = 1;
                        i++;
                }
        }
}

//Used to generate random character numbers
void generateRandomCharacterArray(int randomArray[5]) {
        int numberCheck[5] = {0,0,0,0,0};
        int i = 0;
        while ((i < 5)) {
                int random = ((rand() % 5) + 1);
                if (numberCheck[random - 1] != 1) {
                        randomArray[i] = random;
                        numberCheck[random - 1] = 1;
                        i++;
                }
        }
}

//Connect rooms randomly
void shuffleRooms(struct Room *roomList[9], struct Room *randomRoomList[9]) {

        for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                        if (roomList[j]->roomNumber - 1 == i) {
                                randomRoomList[i] = roomList[j];
                                break;
                        }
                }
        }
}

//Shuffles items randomly
void shuffleItems(struct Item *itemList[6], struct Item *randomItemList[6]) {

        for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                        if (itemList[j]->itemNumber - 1 == i) {
                                randomItemList[i] = itemList[j];
                                break;
                        }
                }
        }
}

//Shuffles items randomly
void shuffleCharacters(struct Character *characterList[5], struct Character *randomCharacterList[5]) {

        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                        if (characterList[j]->characterNumber - 1 == i) {
                                randomCharacterList[i] = characterList[j];
                                break;
                        }
                }
        }
}

//Connects rooms in shuffled array
void connectRooms(struct Room *randomRoomList[9]) {

	//First room exits
        room_exit_east(randomRoomList[0], randomRoomList[1]);
        room_exit_south(randomRoomList[0], randomRoomList[1]);

        //Second room exits
        room_exit_west(randomRoomList[1], randomRoomList[0]);
        room_exit_south(randomRoomList[1], randomRoomList[4]);
        room_exit_east(randomRoomList[1], randomRoomList[2]);

        //Third room exits
        room_exit_west(randomRoomList[2], randomRoomList[1]);
        room_exit_south(randomRoomList[2], randomRoomList[5]);

        //Fourth room exits
        room_exit_north(randomRoomList[3], randomRoomList[0]);
        room_exit_east(randomRoomList[3], randomRoomList[4]);
        room_exit_south(randomRoomList[3], randomRoomList[6]);

        //Fifth room exits
        room_exit_north(randomRoomList[4], randomRoomList[1]);
        room_exit_east(randomRoomList[4], randomRoomList[5]);
        room_exit_south(randomRoomList[4], randomRoomList[7]);
        room_exit_west(randomRoomList[4], randomRoomList[3]);

	//Sixth room exits
        room_exit_north(randomRoomList[5], randomRoomList[2]);
        room_exit_west(randomRoomList[5], randomRoomList[4]);
        room_exit_south(randomRoomList[5], randomRoomList[8]);

        //Seventh room exits
        room_exit_north(randomRoomList[6], randomRoomList[3]);
        room_exit_east(randomRoomList[6], randomRoomList[7]);

        //Eighth room exits
        room_exit_north(randomRoomList[7], randomRoomList[4]);
        room_exit_east(randomRoomList[7], randomRoomList[8]);
        room_exit_west(randomRoomList[7], randomRoomList[6]);

        //Ninth room exits
        room_exit_north(randomRoomList[8], randomRoomList[5]);
        room_exit_west(randomRoomList[8], randomRoomList[7]);
}

//Places items in random rooms
void placeItems(struct Room *randomRoomList[9], struct Item *randomItemList[6]) {
	for (int i = 0; i < 6; i++) {
		randomRoomList[i]->items = randomItemList[i];
	}
}

//Places characters in random rooms
void placeCharacters(struct Room *randomRoomList[9], struct Character *randomCharacterList[5]) {
        for (int i = 0; i < 5; i++) {
                randomRoomList[i]->characters = randomCharacterList[i];
        }
}

void main(int argc, char *argv[]) {

	//Rooms
	int roomNumbers[9] = {0,0,0,0,0,0,0,0,0};
	generateRandomArray(roomNumbers);

	struct Room *room1 = room("Library", NULL, NULL, roomNumbers[0], NULL, NULL, NULL, NULL);
	struct Room *room2 = room("Kitchen", NULL, NULL, roomNumbers[1], NULL, NULL, NULL, NULL);
	struct Room *room3 = room("Balcony", NULL, NULL, roomNumbers[2], NULL, NULL, NULL, NULL);
	struct Room *room4 = room("Study", NULL, NULL, roomNumbers[3], NULL, NULL, NULL, NULL);
	struct Room *room5 = room("Basement", NULL, NULL, roomNumbers[4], NULL, NULL, NULL, NULL);
	struct Room *room6 = room("Bathroom", NULL, NULL, roomNumbers[5], NULL, NULL, NULL, NULL);
	struct Room *room7 = room("Artroom", NULL, NULL, roomNumbers[6], NULL, NULL, NULL, NULL);
	struct Room *room8 = room("Bedroom", NULL, NULL, roomNumbers[7], NULL, NULL, NULL, NULL);
	struct Room *room9 = room("Attic", NULL, NULL, roomNumbers[8], NULL, NULL, NULL, NULL);

	struct Room *roomList[9] = {room1, room2, room3, room4, room5, room6, room7, room8, room9};
	struct Room *randomRoomList[9];

	shuffleRooms(roomList, randomRoomList);

	connectRooms(randomRoomList);


	//Items
	int itemNumbers[6] = {0,0,0,0,0,0};
	generateRandomItemArray(itemNumbers);

	//struct Item *item(char* name, char* description, struct Item *next)
	struct Item *item1 = item("Plate", "Shiny plate with a peculiar smell.", itemNumbers[0], NULL);
	struct Item *item2 = item("Broomstick", "Broomstick covered with detailed markings.", itemNumbers[1], NULL);
	struct Item *item3 = item("Dictionary", "Dictionary with most pages ripped out.", itemNumbers[2], NULL);
	struct Item *item4 = item("Knife", "Knife covered in blood.", itemNumbers[3], NULL);
	struct Item *item5 = item("Needle", "Needle recently cleaned.", itemNumbers[4], NULL);
	struct Item *item6 = item("Cigar", "Half-smoked cigar", itemNumbers[5], NULL);

	struct Item *itemList[6] = {item1, item2, item3, item4, item5, item6};
	struct Item *randomItemList[6];

	shuffleItems(itemList, randomItemList);

	placeItems(randomRoomList, randomItemList);


	//Characters
	int characterNumbers[5] = {0,0,0,0,0};
        generateRandomCharacterArray(characterNumbers);

        //struct Character *character(char* name, char* description, int characterNumber, struct Item *next)
        struct Character *character1 = character("Butler", "Grumpy old butler with a tendency to leave tasks unfinished.", characterNumbers[0], NULL);
        struct Character *character2 = character("Maid", "Anxious maid who's too adamant about helping you find the killer.", characterNumbers[1], NULL);
        struct Character *character3 = character("Cheff", "Kind cheff known for spending much of his time reading.", characterNumbers[2], NULL);
        struct Character *character4 = character("Doctor", "Meticulous doctor with a keen eye for detail.", characterNumbers[3], NULL);
        struct Character *character5 = character("Tutor", "Strict tutor known for having a short temper.", characterNumbers[4], NULL);

        struct Character *characterList[5] = {character1, character2, character3, character4, character5};
        struct Character *randomCharacterList[5];

        shuffleCharacters(characterList, randomCharacterList);

        placeCharacters(randomRoomList, randomCharacterList);


	//PlayerAvatar
	int avatarLocation = 1;

	//INVENTORY
	struct Item *inventory = NULL;
	char* inventoryList[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	int inventoryIndex = 0;


	int roomAnswer = ((rand() % 9) + 1);
	int characterAnswer = ((rand() % 5) + 1);
	int itemAnswer = ((rand() % 6) + 1);

	//Game Start
	printf("\nCLUE\n");
        printf("\nOh no! There has been murder!\nIt's your job to solve this mystery...\n");

	//Game Loop
	int i = 0;
	while (i < 10) {
		int clueMatchCount = 0;
		char playerInput[100];
		printf("\nEnter a command (enter 'help' to see command list): ");
		scanf("%s", playerInput);
		printf("\n");

		//Help command
		if (strcmp(playerInput, "help") == 0) {
			help();
		}

		//List command
		else if (strcmp(playerInput, "list") == 0) {
			list(randomRoomList, randomItemList, randomCharacterList);
		}

		//Look command
		else if (strcmp(playerInput, "look") == 0) {
			look(randomRoomList, avatarLocation);
		}

		//goDIRECTION commands
		else if (strcmp(playerInput, "go") == 0) {
			char direction[5];
			printf("Go where (NORTH, WEST, EAST, or SOUTH)?: ");
			scanf("%s", direction);

			if (strcmp(direction, "WEST") == 0) {
				if (goDIRECTION(avatarLocation, "WEST") != -1) {
					avatarLocation = goDIRECTION(avatarLocation, "WEST");
				}
				else {
					continue;
				}
                	}

                	else if (strcmp(direction, "NORTH") == 0) {
				if (goDIRECTION(avatarLocation, "NORTH") != -1) {
                        		avatarLocation = goDIRECTION(avatarLocation, "NORTH");
				}
				else {
					continue;
				}
			}

	                else if (strcmp(direction, "EAST") == 0) {
				if (goDIRECTION(avatarLocation, "EAST") != -1) {
					avatarLocation = goDIRECTION(avatarLocation, "EAST");
				}
				else {
					continue;
				}
                	}

	                else if (strcmp(direction, "SOUTH") == 0) {
         	                if (goDIRECTION(avatarLocation, "SOUTH") != -1) {
					avatarLocation = goDIRECTION(avatarLocation, "SOUTH");
				} else {
					continue;
				}
                	}

			else {
				printf("\nInvalid location.\n");
				continue;
			}
		}

		//takeITEM command
		else if (strcmp(playerInput, "take") == 0) {
			printf("take what (item)?: ");
			char itemTaken[100];
			scanf("%s", itemTaken);
			char* itemTakenCopy = itemTaken;

			if (randomRoomList[avatarLocation]->items != NULL) {
				if (strcmp(itemTakenCopy, randomRoomList[avatarLocation]->items->name) == 0) {
                                	add_item(&inventory, randomRoomList[avatarLocation]->items);
                                	inventoryList[inventoryIndex] = randomRoomList[avatarLocation]->items->name;
                                	inventoryIndex++;
                                	randomRoomList[avatarLocation]->items = NULL;
                        	}
			}

		}

		//dropITEM command
		else if (strcmp(playerInput, "drop") == 0) {
			printf("drop what (item)?: ");
			char itemDropped[100];
                        scanf("%s", itemDropped);
                        char* itemDroppedCopy = itemDropped;

			struct Item *item_drop = searchInventory(inventory, itemDropped);

			if (item_drop != NULL) {
				if ((inventoryListCheck(itemDroppedCopy, inventoryList) == 1) && (randomRoomList[avatarLocation]->items == NULL)) {
                                	struct Item *itemCopy = item(item_drop->name, item_drop->description, item_drop->itemNumber, NULL);

					randomRoomList[avatarLocation]->items = itemCopy;
					int elementIndex = 0;
                                	for (int i = 0; i < 6; i++) {
                                        	if (inventoryList[i] == NULL) {
                                        		break;
                                        	}
                                        	else if (strcmp(inventoryList[i], item_drop->name) == 0) {
                                                	elementIndex = i;
                                        	}
                                	}
                                	deleteInventoryElement(inventoryList, elementIndex);
                                	inventoryIndex--;
                                	drop_item(&inventory, item_drop->name);
                        	}
				else {
					printf("\nError: Room already full or item not in inventory.\n");
				}
			}
		}

		//Inventory command
		else if (strcmp(playerInput, "inventory") == 0) {
			printInventory(inventory);
		}

		//clueCHARACTER command
		else if (strcmp(playerInput, "clue") == 0) {
			generateClue(getRoomAnswer(randomRoomList, roomAnswer), getItemAnswer(inventory, randomItemList, itemAnswer));

			printf("\nWho did it (name)?: ");
			char characterInput[100];
                        scanf("%s", characterInput);
                        char* characterInputCopy = characterInput;

			clueMatchCount = clueCHARACTER(characterInputCopy, randomRoomList, avatarLocation, roomAnswer, characterAnswer, itemAnswer, inventory);

			i++;

			if (clueMatchCount == 3) {
				//Winning state message
				printf("\nCongrats! You have solved the mystery!\n\n");
				i = 0;
				break;
			}
		}

		//quit command
		else if (strcmp(playerInput, "quit") == 0) {
			break;
		}

		//In case the user input does not match any commands
		else {
			printf("\nInvalid command\n");
			continue;
		}
	}

	//Loosing state message
	if (i == 10) {
		printf("\nYou have run out of clues... The killer roams free...\n\n");
	}
}
