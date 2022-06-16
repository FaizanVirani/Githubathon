/*
Name: Nancy, Ananya, Renee, Faizan
Program Name: Final Project
Date: 6/9/22
Extra: using files
*/
#include "Functions.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main() {
	bool runAgain = false;
	cout << "✧ Mafia Madness ✧";

  string answerHolder = ""; // Makes error trapping ints easier
	string name = "";     
  // Name of user
  cout << "\nEnter your first name (case sensitive!): ";
	getline(cin, name);
	cout << "Enter your last name (case sensitive!): ";
	getline(cin, answerHolder);
  name = name.append(answerHolder);
	do {
		
		string lines;

		bool accountExists = accounts(); // Checks if the account exists

		int answerChoice; // Answer to the menu prompts
		int boolToInt;    // Manually sets value to 0 (true) or 1 (false) based on
						  // boolean

		vector<string> copyFile;
		setName(name);

		fstream lol("Names.txt");
		while (getline(lol, lines)) {
			if (lines.find(name) != std::string::npos) {
				break;
			}
		}
		lol.close();

		if (lines.find(name) != std::string::npos) {
			if(!(name.find(".txt") != std::string::npos)) {
        name = name.append(".txt");
      }
      
			ifstream copier(name);
			if (copier.is_open()) {
				while (getline(copier, lines)) {
					copyFile.push_back(lines);
				}
				copier.close();
			}
		} else {
      ofstream o;
      o.open("Names.txt", std::ios_base::app); // append instead of overwrite
      o << name << endl; 
      
      if(!(name.find(".txt") != std::string::npos)) {
        name = name.append(".txt");
      }
      ofstream outfile (name);
      outfile.close();
    }

    if(copyFile.size() > 0) {
      accountExists = true;
    } else {
      accountExists = false;
    }
		cout << "\n\nWhat would you like to do? Enter the number corresponding to "
			"your choice:\n";

		if (accountExists) {

			do {
				cout << "\t1) Make a new game\n\t2) Resume an existing game\n\t3) "
					"Quit\n";
				getline(cin, answerHolder);
			} while (!validInt(answerHolder) || stoi(answerHolder) > 3 ||
				stoi(answerHolder) < 1);
			boolToInt = 0;
			answerChoice = stoi(answerHolder);

		}
		else {

			do {
				cout << "\t1) Make a new game\n\t2) Quit\n";
				getline(cin, answerHolder);
			} while (!validInt(answerHolder) || stoi(answerHolder) > 3 ||
				stoi(answerHolder) < 1);
			boolToInt = 1;
			answerChoice = stoi(answerHolder);
		}

		switch (boolToInt) {
		case 0: {
      exchangeSort(copyFile);
			if (answerChoice == 1) {
				setPoints(0);
				int randomNumber = randomize();
				if (randomNumber % 2 == 1) {
					cout << "\nYou were assigned the random role of Mafia!";
					mafia(1, name, 0);
				}
				else {
					cout << "\nYou were assigned the random role of Citizen!";
					citizen(1, name, 0);
				}
				break;
			}
			else if (answerChoice == 2) {
				for (int i = 0; i < copyFile.size(); i++) {
					cout << "\n" << i + 1 << ":" << endl;
					cout << "\tPoints: "
						<< copyFile[i].substr(copyFile[i].find(":") + 1,
							copyFile[i].find(";") -
							copyFile[i].find(":") - 1)
						<< endl;
					cout << "\tStage: " << copyFile[i].substr(copyFile[i].find(";") + 1)
						<< endl;
					cout << "\tRole: " << copyFile[i].substr(0, copyFile[i].find(":"))
						<< endl;
				}

				do {
					cout << "\nPlease enter the number corresponding with the game you would like to resume: ";
					getline(cin, answerHolder);
				} while (!validInt(answerHolder) || stoi(answerHolder) > 3 ||
					stoi(answerHolder) < 1);
				string stage = copyFile[stoi(answerHolder) - 1];

				if (stage.substr(0, stage.find(":")) == "Mafia") {
					mafia(stoi(stage.substr(stage.find(";") + 1)), name, stoi(stage.substr(stage.find(":") + 1,
							stage.find(";") -
							stage.find(":") - 1)));
				}
				else {
					citizen(stoi(stage.substr(stage.find(";") + 1)), name, stoi(stage.substr(stage.find(":") + 1,
							stage.find(";") -
							stage.find(":") - 1)));
				}
				break;
			}
			else if (answerChoice == 3) {
				cout << "Thanks for playing!";
				break;
				return 0;
			}
		}
		case 1:
			if (answerChoice == 1) {
				setPoints(0);
				int randomNumber = randomize();
				if (randomNumber % 2 == 1) {
					cout << "\nYou were assigned the random role of Mafia!";
					mafia(1, name, 0);
				}
				else {
					cout << "\nYou were assigned the random role of Citizen!";
					citizen(1, name, 0);
				}
				break;
			}
			else if (answerChoice == 2) {
				cout << "Thanks for playing!";
				break;
				return 0;
			}
		}

		cout << "\nPress y/Y to return to main menu. Any other character to quit: ";
		getline(cin, answerHolder);
		if (answerHolder == "y" || answerHolder == "Y") {
			runAgain = true;
		}
		else {
			runAgain = false;
		}
	} while (runAgain);
}