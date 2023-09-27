#include <iostream>
#include <vector>
using namespace std;

//Constants
string ANSWER = "melons";
vector<string> HANGMEN = {
	      "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========", 

        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",

        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",

        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========", 

        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",

        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",

        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="};
int lives = 6;
bool correct;

void guessResult(char guess, string& result) {
  correct = false;
	for(int i = 0; i < ANSWER.length(); i++) {
		if (ANSWER[i] == guess){
			result[i] = guess;
      correct = true;
		} 
	}
   if (correct == false)
    {
      lives--;
      cout << lives <<" left" << endl;
    }
	cout << result << endl;

}
int main() {
	string player;
	char guess;
	string inprog = "______";

	cout << "Welcome to Hangman!!" << endl;
	cout << HANGMEN[6] << endl;
	cout << "\n~~~~~~~~~\n";
	cout << "Enter PLAYER name: ";
	cin >> player;
	cout << "Hello, " << player << "!\nThe word is 6 letters long.\nEnter your first guess: ";
	while(true) {
		cin >> guess;
		cout << "Your guess: " << guess << endl;
		guessResult(guess, inprog);	
    if (lives == 0)
    {
      cout << "You Lost!";
      break;
    }
		if(inprog==ANSWER) {
			cout << "You win!\n Thanks for playing!\n";
			break;
		}
	}



}