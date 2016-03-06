# Rock On!
## Description
This project is a simple game coded in C++. It's word-guessing game in which the program chooses
a secret word between 4-6 letters (from a pre-selected list of words) and the player has to guess the word
in order to win. This project tested our abilities and mechanics with C strings, the C string library, and 
functions.

## How to Play
If you're interested in playing the game for yourself, stick around and read this section. It'll touch
upon how to run the game (if you don't already know how) and the instructions for the game.

##### How to Run the Game
Download the zip file for the repo. Once you extract all the files from the zip file, you should
be able to nagivate into the 'Debug' folder. Within there, you should be able to find the 
Project 5.exe file. Double click on that to get started with playing the game.
<br><br>
Note: Once the game ends, the exe file will immediately close. Like some of my other projects,
I might one day implement a 'Play Again' feature so that people won't have to double-click the exe
file every time they want to play the game.

##### Instructions
The game starts off by asking you how many rounds of the game you want to play. After you have input
the number of rounds you want to play, the game will select a word from its list of words
and tell you how many letters are in the word. If you're interested in which words the game is given,
it's contained in the libraryOfWords.txt file within the same Debug folder. From here, you can keep guessing
the world until you guess it correctly. Until then, the game will give you two clues: the number of rocks and pebbles
within you guess. The number of rocks tell you how many letters within your guess are in the right position. The
number of pebbles tells you how many letters within your guess are correct, but are in the wrong position. You can use these
clues to guess the word.
<br><br>
Once you have guess the word, the game will print out some useful statistics for the player, signaling the end of 
the round. If there are still more rounds to play, it will immediately start the next round and choose a new word. If
there aren't more rounds to play, the game will exit immediately. Become a master at this game, and you'll become
a Geological HERO! Best of luck and have fun!
