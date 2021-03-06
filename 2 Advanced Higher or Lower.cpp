/*

Hey--fair warnings: (1) This is probably the worst code that you will see in your life, (2) I took 'spaghetti code' quite personally, 
(3) The variable and function names does not really make sense, and (4) This code is a mix of my logic and other advanced, Discord programmers. So
when you see a vector and/or some too-advanced-for-me functions, it was their idea. 

But it works, except for the range guess (when you buy the range guess in the shop and you use it using the [4] menu in the main menu, the program won't work).

So basically:

You would guess a number generated by the system. But I added a few other features:

1. Pointing system
2. The shop
3. The items in the shop:
  a. Intelligent Guess (permanent, but not until you close the console :) ) - where the system tells you more accurate guidance. Instead of the original 
     "Higher," or "Lower," it will tell you things like "That is too high! Try lowering it by 30," "You're close! Lower," etc...
  b. Range Gues - where the system will tell you the range of the random-generated value. Ex: the value is 4, thus: "The value is between: 1 - 10," the 
     the value is 25, thus: "The value is between 20 - 30." But I am having a hard time with this feature.

May God guide you in this forest.

*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


int firstNum, secondNum, numPowerups, range, difference, cost, points, val, guess, tries = 1;
char arr[2];
bool moreIntelligentSystem = false;
bool rangeGuessInUse = false;
int rangeGuesses;
char usrInput;

int again();
void intelligentFGuess();
void pointingSys();
void menu();
void permaPowerupsMenu();
void useablePowerupsMenu();
void fGuess();
void shop();
void rangeGuess();

void checkerRange() {
	if (rangeGuessInUse == true) {
		rangeGuess();
	}
}
void rangeGuess() {

	std::vector <int> g1(std::to_string(val).length());
	g1 = { val };
	firstNum = g1[g1.size()];

	if (g1.size() == 1) {
		std::cout << "The number is between: 0 - 10";
	}
	else if(g1.size() == 2) {
		firstNum = g1[0];
		std::cout << "The number is between: " << firstNum << "0" << "-" << firstNum + 1 << "0";
	}
	

	std::cout << firstNum << std::endl << secondNum;
	/*for (int i = 0; i < std::to_string(val).length(); i++) {
		std::cout << g1[i];
	}*/
	
	/*firstNum = g1[0];
	std::cout << firstNum;*/
}

void usePowerupsMenu() {
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "\n";
	std::cout << "Welcome to Powerups!";
	std::cout << "\nOptions: \n\tUse Range Guess" << " (" << numPowerups << ") [1]" << "\n\tExit to Menu [2]";

	std::cout << "\n>";
	while (std::cin >> usrInput) {
		if (usrInput == '1') {
			if (numPowerups == 0) {
				std::cout << "Sorry, you don't have any more <Ranged Guess>. You can buy more at shop. \n";
				usePowerupsMenu();
			}
			else {
				numPowerups -= 1;
				std::cout << "<Range Guess> is now in use. Remaining <Range Guess>: " << numPowerups;
				rangeGuessInUse = true;
				usePowerupsMenu();
			}
			
		}
		else if (usrInput == '2') {
			menu();
		}
	}
}

void checker() {
	if (moreIntelligentSystem == true) {
		intelligentFGuess();
	}
	else if (moreIntelligentSystem == false) {
		fGuess();
	}
}

void intelligentFGuess() {
	checkerRange();
	std::cout << "Enter guess: ";
	while (std::cin >> guess) {
		if (guess == val) {
			std::cout << "Number of tries: " << tries << std::endl;
			tries = 1;
			pointingSys();
			again();
		}
		else if (guess > val) {
			difference = abs(val - guess);
			if (difference >= 30) {
				std::cout << "That's too high! Try lowering by 30.\n";
			}
			else if (difference < 30 && difference >= 20) {
				std::cout << "A bit high. Try lowering by 20.\n";
			}
			else
				std::cout << "You're Close! Lower. \n";
			++tries;
			checker();
		}
		else if (guess < val) {
			difference = abs(val - guess);
			if (difference >= 30) {
				std::cout << "That's too low! Try raising it by 30.\n";
			}
			else if (difference < 30 && difference >= 20) {
				std::cout << "A bit low. Try raising it by 20.\n";
			}
			else
				std::cout << "You're close! Higher. \n";
			++tries;
			checker();
		}
	}
}


void pointingSys() {

	if (tries == 1) {
		points += 5;
	}
	else if (tries > 1 && tries <= 3) {
		points += 3;
	}
	else if (tries > 3 && tries <= 10) {
		points += 2;
	}
	else {
		++points;
	}
}


void permaPowerupsMenu() {
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "\nWelcome to Permanent Powerups!";
	std::cout << "\nAvailable Items: \n\tMore Intelligent System [1] \n\tExit to Shop [2]";

	std::cout << "\n>";
	while (std::cin >> usrInput) {
		if (usrInput == '1') {

			cost = 15;
			if (cost > points) {
				std::cout << "Sorry, your points are not enough.\n";
			}
			else if (cost <= points) {
				if (moreIntelligentSystem == true) {
					std::cout << "You already have <More Intelligent System>.";
				}
				else {
					std::cout << "You now have <More Intelligent System>!";
					moreIntelligentSystem = true;
					points -= cost;
				}
			}
		}
		else if (usrInput == '2') {
			shop();
		}

		std::cout << "\n>";
	}
}

void useablePowerupsMenu() {
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "\nWelcome to Useable Powerups!";
	std::cout << "\nAvailable Items: \n\tRange Reveal [1] \n\tExit to Shop [2]";

	std::cout << "\n>";
	while (std::cin >> usrInput) {
		if (usrInput == '1') {

			cost = 15;
			if (cost > points) {
				std::cout << "Sorry, your points are not enough.\n";
			}
			else {
				numPowerups+=1;
				std::cout << "+1 <Range Guess>. Current <Range Guess>: " << numPowerups;
				points -= cost;
			}
		}
		else if (usrInput == '2') {
			shop();
		}

		std::cout << "\n>";
	}
}

void shop() {
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "\nWelcome to Shop!";
	std::cout << "\nOptions: \n\tPermanent Powerups [1] \n\tUseable Powerups [2] \n\tBack to Menu [0]";

	std::cout << "\n>";
	while (std::cin >> usrInput) {
		if (usrInput == '1') {
			permaPowerupsMenu();
		}
		else if (usrInput == '2') {
			useablePowerupsMenu();
		}
		else if (usrInput == '0') {
			std::cout << "----------------------------------------------------" << std::endl;
			std::cout << "\n";
			menu();
		}
		std::cout << "\n>";
	}
}


void menu() {
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "\n";
	std::cout << "Welcome to Higher/Lower!";
	std::cout << "\nOptions: \n\tPlay [1] \n\tShop [2] \n\tCheck Points [3] \n\tUse Powerups [4] \n\tQuit [5]";
	
	std::cout << "\n>";
	while (std::cin >> usrInput) {
		if (usrInput == '1') {
			std::srand(time(NULL));
			val = rand() % 25 + 1;
			std::cout << "----------------------------------------------------" << std::endl;
			std::cout << "\n";
			//std::cout << val; //testing
			checker();
		}
		else if (usrInput == '2') {
			shop();
		}
		else if (usrInput == '3') {
			std::cout << "You currently have: " << points << " points.";
		}
		else if (usrInput == '4') {
			usePowerupsMenu();
		}
		else if (usrInput == '5') {
			exit(0);
		}
		std::cout << "\n>";
	}
}

void fGuess() {
	checkerRange();
	std::cout << "Enter guess: ";
	while (std::cin >> guess) {
		if (guess == val) {
			std::cout << "Number of tries: " << tries << std::endl;
			tries = 1;
			pointingSys();
			again();
		}
		else if (guess > val) {
			std::cout << "Lower \n";
			++tries;
			checker();
		}
		else if (guess < val) {
			std::cout << "Higher \n";
			++tries;
			checker();
		}
	}
}

int main()
{
	points = 999999;
	menu();
}

int again() {
	menu();
	return 0;
}



/*
TODOs:

USEABLE POWERUPS: 
- Range Reveal (15 pts)

PERMANENT POWERUPS:
- Reveals if it's too high or low, instead of the casual "Higher," or "Lower,"; "You're close! Just a little <higher or lower>" (50 pts)

- RANGE fGuess
*/
