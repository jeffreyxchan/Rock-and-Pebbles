// CS 31 Fall 2015
// Programming Assignment 5
// Rock On
// by Jeffrey Chan 2015

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cctype>
using namespace std;

int loadWords(char words[][7], int maxWords);
int manageOneRound(const char words[][7], int nWords, int wordnum);
int randInt(int min, int max);
const int MAXWORDS = 9000;
const int MAXWORDLEN = 6;

int main()
{
	char wordList[MAXWORDS][MAXWORDLEN + 1];
	int nWords = loadWords(wordList, MAXWORDS); // load up wordList and get number of words
	if (nWords < 1) // if no words were loaded
	{
		cout << "No words were loaded, so I can't play the game." << endl;
		return 1;
	}
	
	cout << "How many rounds do you want to play? "; // getting number of rounds
	int numberofRounds;
	cin >> numberofRounds;
	if (numberofRounds <= 0) // if number of rounds is not positive
	{
		cout << "The number of rounds must be positive." << endl;
		return 1;
	}
	cin.ignore(10000, '\n');

	cout << endl; // skip a line in the interface

	int total = 0; // set variables to hold average, min, and max for later
	int min = 0;
	int max = 0;
	for (int k = 1; k <= numberofRounds; k++) // repeat for all the rounds
	{
		cout << "Round " << k << endl; // print out round number
		int secretWord = randInt(0, nWords - 1); // generate positiong of secret word
		int secretWordLen = strlen(wordList[secretWord]); // get length of secret word
		cout << "The secret word is " << secretWordLen << " letters long." << endl; // tell user how long the word is
		int roundScore = manageOneRound(wordList, nWords, secretWord); // play round
		cout << "You got it in " << roundScore << " tries." << endl; // print out tries
		cout.setf(ios::fixed);
		cout.precision(2);
		total = total + roundScore;
		if (k == 1)                  // on first round, min is the roundScore
			min = roundScore;
		if (roundScore < min)       // on every other round, replace min with roundScore if roundScore < min
			min = roundScore;
		if (roundScore > max)       // replace max with roundScore if roundScore > max
			max = roundScore;
		cout << "Average: " << static_cast<double>(total)/k << ", minimum: " << min << ", maximum: " << max << endl;
		cout << endl; // skip a line for interface style
	}
}

int manageOneRound(const char words[][7], int nWords, int wordnum)
{
	// Error Statements
	if (nWords <= 0 || wordnum < 0 || wordnum >= nWords)
		return -1;

	// Going through all the attempts at getting the secret word
	int score = 0;
	for (;;)
	{
		int rocks = 0;
		int pebbles = 0;
		cout << "Probe word: ";
		char probeWord[200];
		cin.getline(probeWord, 199);

		// Error Messages for Probe Word
		bool notgoodInput = false;
		for (int j = 0; j != strlen(probeWord); j++)
		{
			if (!isalpha(probeWord[j]) || !islower(probeWord[j]) || strlen(probeWord) < 4 || strlen(probeWord) > 6)
			{
				cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
				notgoodInput = true;
				break;
			}
		}
		if (notgoodInput)
			continue;

		// Essentially the lookup function
		bool found = false;
		for (int k = 0; k != nWords; k++) // go through all the words in words array
		{
			if (strcmp(words[k], probeWord) == 0)
				found = true;
		}
		if (!found)
		{
			cout << "I don't know that word." << endl;
			continue;
		}

		// Determine which is the shorter/longer word between probeWord and words[wordnum]
		char shorterWord[MAXWORDLEN + 1];
		if (strlen(probeWord) < strlen(words[wordnum]))
			strcpy(shorterWord, probeWord);
		else
			strcpy(shorterWord, words[wordnum]);
		
		char rocksandPebbles[MAXWORDLEN + 1] = "------"; // create array for rocks and pebbles

		// Algorithm for filling rocksandPebbles with r's
		for (int k = 0; k != strlen(shorterWord); k++) // go through both words
		{
			if (words[wordnum][k] == probeWord[k]) // if the letters match up at the same position
				rocksandPebbles[k] = 'r'; // assign 'r' for rock to corresponding positiong in r&p array
		}

		// Algorithm for filling rocksandPebbles with p's
		for (int i = 0; i != strlen(words[wordnum]); i++) // use double for loop for permuation
		{
			if (rocksandPebbles[i] == 'r') // dont observe positions already labeled with rock
				continue;
			for (int m = 0; m != strlen(probeWord); m++) // go through probeWord
			{
				if (rocksandPebbles[m] == 'r' || rocksandPebbles[m] == 'p') // dont observe positions already labeled with rock or pebble
					continue;
				if (words[wordnum][i] == probeWord[m])
				{
					rocksandPebbles[m] = 'p'; // asign p for pebble to position in r&p array corresponding to matched letter in probeWord
					break;
				}
			}
		}

		for (int k = 0; k != MAXWORDLEN + 1; k++)  // go through the rocksandPebbles array
		{
			if (rocksandPebbles[k] == 'r')         // count the number of rocks
				rocks++;
			if (rocksandPebbles[k] == 'p')         // count the number of pebbles
				pebbles++;
		}
		
		score++; // every time you go through this loop (which is an attempt), increase score by 1

		if (rocks == strlen(words[wordnum]) && pebbles == 0)  // if user got the word, return the number of tries
			return score;
		else
			cout << "Rocks: " << rocks << ", Pebbles: " << pebbles << endl;  // if they didnt, print out this information
	}
}
