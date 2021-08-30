#include <iostream>
#include "game_state.h"

using namespace std;

int main()
{
    cout << "Starting a game of hangman" << endl;
    GameState w2;
    w2.start();
    GameState w;
    
    string word = w.start();
    char guess;
    while(true){
        cout << "#### Playing Hangman! ####\n" << endl;
        while(w.status() > 0){
            w.print(cout);
            cout << "Word: " << word << endl;
            cout << "Guess a character" << endl;
            cin >> guess;
            word = w.makeGuess(guess);
        }
        w.print(cout);
        
        char ans = 'n';
        while(ans != 'y' && ans != 'Y'){
            cout << "Play again? Y/N" << endl;
            cin >> ans;   
            if (ans == 'N' || ans == 'n')
            {
                return(0);
            }
        }
        word = w.reset();
    }

}