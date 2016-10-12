// utilities.cpp

#define _CRT_SECURE_NO_DEPRECATE

#include "utilities.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <random>
#include <utility>
using namespace std;

//***  On a Windows system, if you replace the file name below with the
//***  name of some other file, use / in the string instead of \ (e.g.,
//***  "C:/CS31/Project5/mywordfile.txt").

const char WORDFILENAME[] = "C:/Users/Jeffrey/Documents/Visual Studio 2015/Projects/CS 31 Project 5/Debug/libraryOfWords.txt";

int loadWords(char words[][MAXWORDLEN + 1], int maxWords)
{
	ifstream wordfile(WORDFILENAME);
	if (!wordfile)
	{
		cout << "Cannot open " << WORDFILENAME << "!" << endl;
		return -1;
	}
	const int MAXFILELINELEN = 10000;
	char line[MAXFILELINELEN];
	int numWords = 0;
	while (wordfile.getline(line, MAXFILELINELEN))
	{
		if (numWords == maxWords)
		{
			cout << "Using only the first " << numWords << " words from "
				<< WORDFILENAME << "." << endl;
			break;
		}

		// Store only words with of the right number of lower case letters

		int k;
		for (k = 0; islower(line[k]); k++)
			;

		// The following two lines fix a potential issue for non-Windows
		// users and are harmless for Windows users.

		if (line[k] == '\r')
			line[k] = '\0';

		if (line[k] == '\0'  &&  k >= MINWORDLEN  &&  k <= MAXWORDLEN)
		{
			strcpy(words[numWords], line);
			numWords++;
		}
	}
	return numWords;
}

// Return random int from min to max, inclusive
int randInt(int min, int max)
{
	if (max < min)
		swap(max, min);
	static random_device rd;
	static mt19937 generator(rd());
	static uniform_int_distribution<> distro(min, max);
	return distro(generator);
}