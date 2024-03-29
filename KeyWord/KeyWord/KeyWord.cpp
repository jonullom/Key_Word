// KeyWord.cpp 
// Jon Ullom
// Assignment05
// 24-OCT-18
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	//This set up the fields used in the program//
	enum fields { WORD, HINT, NUM_FIELDS };
	//This sets the limit of words to be jumbled//
	const int NUM_WORDS = 10;
	//This sets up the variable words as both a strig and as a constant. It allows the field of words to be used with 
	//their hints//
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"mideast","Craddle of Civilization"},
		{"iraq","Home of Saddam"},
	    {"bomb","I go boom"},
		{"insurgent","Another name for bad guys in the GWOT"},
		{"enemy","Not a friendly"},
		{"location","Where someone is"},
		{"money","How all things are financed"},
		{"anthrax","Deadly white powder in the mail"},
		{"plane","Airborn conveyance"},
		{"jihad","Muslim holy war"}

	};
	//This is the beginning of the section of the code that jumbles the word for the user to decypher//
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	//This is where the word to be jumbled is stored to be compared against guess//
	string theWord = WORDS[choice][WORD];
	//This is where the hint is stored to be called when the user enter hint//
	string theHint = WORDS[choice][HINT];
	//This is the variable where the jumbled word is stored to be used in the simulation//
	string jumble = theWord;
	//This is the variable to store length of the word to be used in the code that jumbles the word//
	int length = jumble.size();
	int index1 = (rand() % length);
	int index2 = (rand() % length);
	char temp = jumble[index1];
	// This tracks the number of attempts to tell the user how many times it took them to get it right//
	int attempts = 1;
	//This is the variable that stores the character to either continue or not//
	char again = 'y';
	//This is the while loop to continue the simulator//
	while (again == 'y')
	{
		//This is the beginning of the section of the code that jumbles the word for the user to decypher//
		srand(static_cast<unsigned int>(time(0)));
		//This randomly chooses the word to be jumbled//
	    choice = (rand() % NUM_WORDS);
		//This is where the word to be jumbled is stored to be compared against guess//
		string theWord = WORDS[choice][WORD];
		//This is where the hint is stored to be called when the user enter hint//
		string theHint = WORDS[choice][HINT];
		//This is the variable where the jumbled word is stored to be used in the simulation//
		string jumble = theWord;
		//This is the variable to store length of the word to be used in the code that jumbles the word//
		length = jumble.size();
		//This is the for loop that jumbles the word//
		for (int i = 0; i < length;i++)
		{
			//The next five lines are used to jumble the word by breaking it down into individual letters
			//and scrambling the order in which they are output to the user on the screen//
			index1 = (rand() % length);
			index2 = (rand() % length);
			temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}

		cout << "\t\t\tWelcome to KeyWords:\n";
		cout << "\t\t\tCode Breaker Training Simulation.\n";
		for (int x = 0; x < 3; x++)
		{ 
			//This is the beginning of the section of the code that jumbles the word for the user to decypher//
			srand(static_cast<unsigned int>(time(0)));
			//This randomly chooses the word to be jumbled//
			choice = (rand() % NUM_WORDS);
			//This is where the word to be jumbled is stored to be compared against guess//
			string theWord = WORDS[choice][WORD];
			//This is where the hint is stored to be called when the user enter hint//
			string theHint = WORDS[choice][HINT];
			//This is the variable where the jumbled word is stored to be used in the simulation//
			string jumble = theWord;
			//This is the variable to store length of the word to be used in the code that jumbles the word//
			length = jumble.size();
			//This is the for loop that jumbles the word//
			for (int i = 0; i < length; i++)
			{
				//The next five lines are used to jumble the word by breaking it down into individual letters
				//and scrambling the order in which they are output to the user on the screen//
				index1 = (rand() % length);
				index2 = (rand() % length);
				temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'quit' to quit the simulator.\n\n";
		cout << "Your word is: " << jumble;
		//This takes and stores the string of characters from the user's guess of the word//
		string guess;
		cout << "\n\nYour guess:";
		cin >> guess;
		//This is the while loop that compares the users guess with jumbled word to see if it's the correct word.
		//This while loop also allows the user to call the variables: quit to exit the program and hint to give the
		//user a hint about the word they are trying to decypher//
		while ((guess != theWord) && (guess != "quit"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				++attempts;
				cout << "Sorry, that is not correct.";
			}

			cout << "\n\nYour guess:";
			cin >> guess;
		}
		//This if statement tells the program what to do if the guessed word is equal to the word that has been
		//jumbled.//
		if (guess == theWord)
		{
			cout << "\nYou have correctly identified the word in "<<attempts<<".\n";
			
		}
		
		}
		cout << "Continue? (y or n)";
		cin >> again;
	}
	cout << "\nThank you for using KeyWords for your training needs.";
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
