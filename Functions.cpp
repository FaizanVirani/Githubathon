/*
//Codes for Color test \
// foreground background
// black 30 40
// red 31 41
// green 32 42
// Orange 33 43
// blue 34 44
// magenta 35 45
// cyan 36 46
// white 37 47
//"\x1b[35m
*/

#include <fstream>
#include "Functions.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

class playerInformation {
	//declares variables 
public:
  void setPoints(int p) {
    points = p;
  }
  int getPoints() {
    return points;
  }

  void setName(string n) {
    fullName = n;
  }
  string getName() {
    return fullName;
  }
private:
  double points;
	string fullName;
};

bool accounts() {
	ifstream cars;
	cars.open("Names.txt");

	string c = "";
	getline(cars, c);
	if (c.length() > 0) {
		cars.close();
		return true;
	}
	return false;
}

bool validInt(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (!isdigit(a[i])) {
			return false;
			break;
		}
	}
	return true;
}

bool validDouble(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (!isdigit(a[i]) && to_string(a[i]) != "46") {
			return false;
			break;
		}
	}
	return true;
}

void mafia(int start, string name, int points) {
	string answerHolder = "";
	int answerChoice;
	int boolToInt;
	playerInformation player;
	bool gameRun = true;

	do {
		switch (start) {
		case 1: //WRITE THE STORY HERE****
			do {
				cout << "\nWelcome to \x1b[31mMafia\x1b[37m Madness! You have been bestowed the role of \x1b[31mMafia\x1b[0m, congrats! The round is starting, it is now time for you to choose who you would like to kill: [1] Marco [2] Kristian [3] Karen \n";
				getline(cin, answerHolder);
			} while (!validInt(answerHolder) || stoi(answerHolder) > 3 || stoi(answerHolder) < 1);
			boolToInt = 0;
			answerChoice = stoi(answerHolder);
			switch (answerChoice) {
			case 1:
				cout << "\nLooks like you chose to kill Marco, interesting. I wonder how?... Oh! You went to her house and attacked her? Nice!";
				start = 2; gameRun = true;
				writeToFile("Mafia", start, name, points);
				break;
			case 2:
				cout << "\nOooo Kristian, an interesting choice. You stalk out her house waiting for the right time to strike. You peek through the window to see all the lights have turned off. You jump through one of the open windows and sneakily walk up the stairs. You see that Kristian is lying on her bed asleep. You carry her to the roof and then throw her off. RIP Kirstian! LOL!  " << endl;
				start = 4; gameRun = true;
				writeToFile("Mafia", start, name, points);
				break;
			case 3:
				cout << "\nYou choose to kill Karen....valid choice. You watch as Karen goes into the grocery store. After she walks in, you run over to her car and start cutting her brakes. You watch as Karen gets into he r car and drives away. She is driving home when she realizes her brakes are not working. Karen ends up driving off the cliff and died. RIP Karen! LOL!" << endl;
				start = 5;
				writeToFile("Mafia", start, name, points);
				break;
			}

			break;

		case 2:
			do {
				cout << "\nIt's now time for the \x1b[32mCitizens\x1b[0m to Vote on who they think the \x1b[31mMafia \x1b[0mis...It's time for you to plead your case...Will you [1] Cry and say it's not you [2] Blame it on Kristian\n";
				getline(cin, answerHolder);

			} while (!validInt(answerHolder) || stoi(answerHolder) > 3 || stoi(answerHolder) < 1);
			boolToInt = 0;
			answerChoice = stoi(answerHolder);

			switch (answerChoice) {
			case 1:
				cout << "\nEveryone said you were being too emotional and pointed you out as the \x1b[31mMafia \x1b[0m and you died LOL :) It's your fault for crying.";
				gameRun = false;
				writeToFile("Mafia", start, name, points);
				break;
			case 2:
				cout << "\nYou blamed it on Kristian and everyone was convinced! Kristian was voted out.";
				points += 10;
        start = 3;
				writeToFile("Mafia", start, name, points);
				break;
			}
			break;

		case 3:
			do {
				cout << "\nNight falls once again, you've survived another day. It's time for the next round. Choose your next target... [1] Marco [2] Karen?\n";
				getline(cin, answerHolder);
			} while (!validInt(answerHolder) || stoi(answerHolder) > 2 || stoi(answerHolder) < 1);
			boolToInt = 0;
			answerChoice = stoi(answerHolder);
			switch (answerChoice) {
			case 1:
				cout << "\nYou killed Marco! However the doctor saved Marco and YOU LOST AHHAHAHAHHAHHAH! Better luck next time...";
				gameRun = false;
				start = -1;
				writeToFile("Mafia", start, name, points);
				break;

			case 2:
				cout << "\nYou killed Karen! Congratulations, YOU WON!";
				break;
			}
			points += 10;
			start = -1; gameRun = false;
			writeToFile("Mafia", start, name, points);
			break;
		case 4:
			do {
				cout << "\nIt's now time for the \x1b[32mCitizens \x1b[0mto Vote on who they think the \x1b[31mMafia\x1b[0m is...No one is yet to find you suspicious...Who will you vote for?   [1] Marco [2] Karen?\n";
				getline(cin, answerHolder);

			} while (!validInt(answerHolder) || stoi(answerHolder) > 3 || stoi(answerHolder) < 1);
			boolToInt = 0;
			answerChoice = stoi(answerHolder);

			switch (answerChoice) {
			case 1:
				cout << "\nOMG!! You managed to convince Karen to vote out Marco and YOU WON!! Your actually such a baddie!";
				points += 10;
				gameRun = false;
        start = -1;
				writeToFile("Mafia", start, name, points);
				break;

			case 2:
				cout << "\nOMG!! You didn't convince Marco, so both of them voted you out and YOU DIED!! \x1b[32mCitizens \x1b[0mWon!!";
				gameRun = false;
				start = -1;
				writeToFile("Mafia", start, name, points);
				break;
			}
			break;
		case 5:
			cout << "\nThe suspicion in the room falls on you, everyone knows that you and Karen had a fling... Looks like you made the wrong move...";
			gameRun = false;
			start = -1;
			writeToFile("Mafia", start, name, points);
			break;
		}
	} while (gameRun);

  cout << endl << "GAME SUMMARY\n----------------------------------------\nScore: " << points << endl << "Final Stage: " << start << endl << "Role: Mafia\n\n";
}

void citizen(int start, string name, int points) {
	playerInformation player;
	bool gameRun = true;
	string answerHolder = "";
	int answerChoice;
	int boolToInt;
	do {
		switch (start) {
		case 1: //****WRITE THE STORY HERE****
			cout << "\nWelcome to \x1b[31mMafia\x1b[0m Madness! You have been bestowed the role of \x1b[32mCitizen\x1b[0m, congrats! The round is starting, it is now time for you to go to sleep........ ";
			do {
				cout << "\nYou have awoken. Turns out that your fellow \x1b[32mcitizen\x1b[0m named Marco has been pushed out of his bedroom window and died. Now it is time to choose a suspect: [1] Karen or [2] Kristian\n";
				getline(cin, answerHolder);

			} while (!validInt(answerHolder) || stoi(answerHolder) > 2 || stoi(answerHolder) < 1);
			boolToInt = 0;
			answerChoice = stoi(answerHolder);
			switch (answerChoice) {
			case 1:
				cout << "\nYou have made the choice of choosing Karen as the suspect. ";
				srand(time(NULL));
				answerChoice = (rand() % 2) + 1;
				switch (answerChoice) {
				case 1:
					cout << "\nThe other \x1b[32mcitizens \x1b[0mhave agreed with you. You all vote Karen out.";
					gameRun = true; start = 2; writeToFile("Citizen", start, name, points);
					break;
				case 2:
					cout << "\nThe other \x1b[32mcitizens \x1b[0mdo not believe you. They doubt you and decided to vote you out. You are now dead...LOL!";
					gameRun = false; start = -1; writeToFile("Citizen", start, name, points);
					break;
				}
				break;
				break;
			case 2:
				cout << "\nYou have made the choice of choosing Kristian as the suspect.";
				gameRun = true; start = 3; points += 10; writeToFile("Citizen", start, name, points);
				break;
			}
		case 2:
			cout << "\nNight falls again... and a new round begins. You suspect that the \x1b[31mMafia\x1b[0m is Kristian but you head to bed. Unfortunately the \x1b[31mMafia \x1b[0mchooses you as their target. GAME OVER!!!!!!!";
			gameRun = false; start = -1;
			writeToFile("Citizen", start, name, points);
			break;
		case 3:
			cout << "\nEveryone suspects you, you should not have done this, GAME OVER!!!";
			gameRun = false; start = -1;
			writeToFile("Citizen", start, name, points);
			break;
		}
	} while (gameRun);

  cout << endl << "GAME SUMMARY\n----------------------------------------\nScore: " << points << endl << "Final Stage: " << start << endl << "Role: Citizen\n\n";
}

void writeToFile(string type, int position, string name, int points) {
	playerInformation player;
	vector<string> copyFile;
	string lines;

	fstream slay;
	slay.open(name);
	if (slay.is_open()) {
		while (getline(slay, lines)) {
			copyFile.push_back(lines);
		}
		slay.close();
	}
  string abc = (type + ":" + to_string(points) + ";" + to_string(position));

  if(copyFile.size() == 0) {
    copyFile.push_back(abc);
  }
  for(int i = 0; i < copyFile.size(); i++) {
    int d = abc.find(";");
    string def = abc.substr(0, d);
    if(copyFile[i].find(def) != std::string::npos) {
      copyFile[i] = abc;
      break;
    }

    if(i == copyFile.size() - 1 || i == copyFile.size()) {
      copyFile.push_back(abc);
    }
  }

  for(int i = 0; i < copyFile.size(); i++) {
    if (copyFile[i].substr(copyFile[i].find(";") + 1) == "-1") {
      copyFile.erase(copyFile.begin()+i);
    }
    
  }
	ofstream wipe(name);
	wipe.close();

	fstream rewrite(name, std::ios::app);
	if (rewrite.is_open()) {
		for (int i = 0; i < copyFile.size(); i++) {
			rewrite << copyFile[i] << endl;
		}
		rewrite.close();
	}
}

void setName(string name) {
	playerInformation player;
	player.setName(name);
}

void setPoints(double points) {
	playerInformation player;
	player.setPoints(points);
}

int randomize()
{
	srand(time(0));
	return rand();
}

void exchangeSort(vector <string> &num)
  {
    int i, j;
    string temp; // holding variable
    int numLength = num.size(); 
    for (i=0; i < (numLength -1); i++) // element to be compared
      {
        for(j = (i+1); j < numLength; j++) // rest of the elements
           {
              if (num[i] < num[j]) // descending order
                 {
                    temp= num[i]; // swap
                    num[i] = num[j];
                    num[j] = temp;
                 }
            }
       }
  }