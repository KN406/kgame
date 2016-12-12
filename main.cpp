#include <gmock\gmock.h>
#include <gtest\gtest.h>
#include <iostream>

#include "BowlingGame.h"

using namespace testing;
using namespace std;

int main(int argc, char* argv[]) {

	InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	system("pause");

	string sequence = "";
	BowlingGame *game;

	try {
		while (sequence != "q") {

			system("cls");

			cout << endl << "BOWLING GAME KATA" << endl << endl;
			cout << ">> Enter throws sequence: (example: '-/X123456789', 'q' to quit)" << endl << endl;

			cin >> sequence;

			if (sequence != "q") {

				game = new BowlingGame();
				game->setSequence(sequence);

				cout << endl << ">> Your score is " << game->getScore() << endl << endl;

				delete game;
			}
			else
				cout << endl << ">> Goodbye" << endl << endl;

			system("pause");
		}
	}
	catch (exception &e)
	{
		cout << endl << e.what() << endl << endl;
		system("pause");
	}
	
	return 0;
}