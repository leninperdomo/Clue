# Clue
This a text adventure game version of the popular Clue game developed in C.

Video Demonstration URL: https://youtu.be/Ohb1NvnMF5I

This game utilizes 9 rooms which are all of the room structure type defined in rooms.c. the rooms 
are connected in a 3 x 3 matrix using the connectRooms method in adventure.c. To generate random room numbers and paths,
I created arrays filled with numbers from 1-9, 1-6, and 1-5 using the generateRandomArray, generateRandomItemList, 
and generateRandomCharacterList methods in adventure.c. These random values were used to identify and connect all the
rooms, items, and characters randomly. The game uses 5 different characters each of the structure type character
defined in characters.c. Clue also contains 6 different items which are of the structure type item defined in items.c.
Both the characters and items are assigned randomly to each room at the start of the game. The values generated in the
random arrays were used to define each answer arbitrarily at the beginning of the game. Each room 
structure contains a linked list of item structures. A variable iventory of the structure type item was used
to represent a linked list of the avatar's inventory. The array locations determined what rooms each avatar was found in.
The scanf function was utilized to get user input that would control each of the game's commands. The takeITEM, dropITEM,
and goDIRECTION commands were implemented by using the linked lists afforded by the structures created for the program. The game
automatically ends and displays a message accordingly if the avatar matches the item, character, and room in a single clue
command. If the player fails to do so after ten tries, the game finishes automatically and displays a different message.
In order to win, the player must match all the clues with the clue statement printed based on the item and room answer.
The clue statement that is printed is related to the random answer and is the key to winning the game.

Enjoy!
