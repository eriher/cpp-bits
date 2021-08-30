#include "game_state.h"
using namespace std;

const string header = "################\n################\n  ======|\n  |\n";
const string body [] =  { "  O	\n"," /","|","\\\n"," / ","\\ \n" };

GameState::GameState(const std::string& file_name) :file_name(file_name) { srand(time(NULL)); };
GameState::GameState(){GameState("words.txt");}
const string GameState::get_word()
{
	return words[rand() % words.size()];
}

const string GameState::start()
{
	read_words();
	return reset();
}

const string GameState::reset()
{
	attempts = 6;
	history.clear();
	word = get_word();
	guess = string(word.size(), '-');
	return guess;
}

ostream& GameState::print(ostream& out)
{
	out << header;	
	for (int i = 0; i < 6-attempts; i++) {
		out << body[i];
	}
	for (int i = 0; i < attempts; i++) {
		out << endl;
	}
	out << endl;
	if (attempts == 0) {
		out << "GAME OVER" << endl;
		out << "Word was: " << word << endl;
	}
	else if (guess == word) {
		out << "Congratulations! YOU WIN!" << endl;
		out << "Word was: " << word << endl;
	}
	else {
		out << "history: ";
		for (char s : history)
			out << s << ", ";
		out << endl;
		out << endl;
	}
	out << endl;
	return out;
}

string GameState::makeGuess(const char c)
{
	history.push_back(c);
	bool match = false;
	for (string::size_type i = 0; i < word.size(); i++) {
		if (word[i] == c) {
			guess[i] = c;
			match = true;
		}
	}
	if (!match) {
		attempts--;
	}
	return guess;
}

const int GameState::word_count() {
	return words.size();
}

int GameState::status() {
	if (guess == word)
		return 0;
	return attempts;
}

void GameState::read_words()
{
	words.clear();
	string line;
	fstream myfile;
	myfile.open(file_name);
	if(myfile){
		while (getline(myfile, line)) {
			if(line.length() >= 5)
				words.push_back(line);
		}
		myfile.close();
	}
	else{
		cout << "Word file not found!" << endl;
	}
}

