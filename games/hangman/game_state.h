#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>


class GameState
{
	std::vector<std::string> words;
	std::string file_name;
	std::vector<std::string> state;
	std::vector<char> history;
	std::string word;
	std::string guess;
	int attempts;

	public:
	    GameState();
		GameState(const std::string&);
		
		const std::string start();
		const std::string reset();
		std::ostream& print(std::ostream& out);
		std::string makeGuess(const char c);
		int status();
		
		

	private:
		const int word_count();
		const std::string get_word();
		void read_words();

	private: 
		
};

