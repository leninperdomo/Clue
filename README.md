# Clue
This a text adventure game version of the popular Clue game developed in C.

Video Demonstration URL: https://youtu.be/Ohb1NvnMF5I

The goal of this project was to create a text adventure game for Clue using the C programming language. In the game, players use text commands to control characters, influence the environment, and navigate a virtual world. The game was completed using the constitutional components of dynamic programming, which include dynamic allocation, memory deallocation, and memoization.

This game utilizes 9 rooms which are all of the room structure type defined in rooms.c. the rooms 
are connected in a 3 x 3 matrix using the connectRooms method in adventure.c. To generate random room numbers and paths,
some arrays were created and filled with numbers from 1-9, 1-6, and 1-5 using the generateRandomArray, generateRandomItemList, 
and generateRandomCharacterList methods defined in adventure.c. These random values were used to identify and connect all the
rooms, items, and characters randomly. The game uses 5 different characters each of the structure type character
found in characters.c. Clue also contains 6 different items which are of the structure type item in items.c.
Both the characters and items are assigned randomly to each room at the start of the game. The values generated in the
random arrays were used to define each answer arbitrarily at the start of the game. Each room structure contains a 
linked list of item structures. An iventory variable of the item type was used to represent a linked list of the 
avatar's inventory. The array locations determined what rooms each avatar was found in. The scanf function was 
utilized to get user input that would control each of the game's commands. The takeITEM, dropITEM, and goDIRECTION 
commands were implemented using the linked lists afforded by the structures created for the program. The game automatically 
ends and displays a message accordingly if the avatar matches the item, character, and room in a single clue
command. If the player fails to do so after ten tries, the game ends and displays a different message. In order to win, 
the player must match all the clues with the clue statement printed based on the item and room answer. The clue 
statement displayed depends on the randomly generated answer and is the key to winning the game.

Enjoy!
