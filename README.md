# Clue
This a text adventure game version of the popular Clue game developed in C.

Video Demonstration URL: https://youtu.be/Ohb1NvnMF5I

My game utilizes 9 rooms which are all of the structure room I defined in rooms.c. I connected the rooms 
in a 3 x 3 matrix using the connectRooms method in adventure.c. I generated three arrays filled with random 
numbers from 1-9, 1-6, and 1-5 with generateRandomArray, generateRandomItemList, and generateRandomCharacterList 
in adventure.c. I then used these random values to identify and connect all the rooms, items, and characters randomly.
My game uses 5 different characters each of the structure type character defined in characters.c. The game
also contains 6 different items which are of the structure type item defined in items.c. Both the 
characters and items are assigned randomly to each room at the start of the game. I used the values in the
random arrays I generated to set defined each answer randomly at the beginning of the game. Each room 
structure contains a linked list of item structures. Used variable iventory of the structure type item
to represent a linked list of the avatar's inventory. I also used array locations to define the avatar's location
in each room. I used the scanf function to get user input that would control each of the game's commands. I implemented the
takeITEM, dropITEM, and goDIRECTION commands by using the linked lists afforded by the structures I created. The game
automatically ends and displays a message accordingly if the avatar matches the item, character, and room in a single clue
command. If the player fails to do so after ten tries, the game automatically ends and displays a different message.
In order to win, the player must match all the clues with the clue statement printed based on the item and room answer.
The clue statement that's printed is related to the random answer and is the key to winning the game.

Enjoy!
