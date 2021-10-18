
#include <iostream>
#include <time.h>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

string createUnderlines(string word);

bool findLetter(string &entry, string word, char shot);

int main() {
    string words[] = {"kura", "piec", "duch", "mietek"};
    srand(time(NULL));
    int wordNum = rand() % 4;
    cout << wordNum <<endl;
    int toGuess = words[wordNum].size();
    int lives = 11;
    char shot;
    string entry = createUnderlines(words[wordNum]);
    cout << "Witaj w prostym wisielcu!" << endl;

    while(lives > 0 && toGuess > 0) {
        cout << "Ilosc zyc: " << lives  << endl;
        cout << entry << endl;
        cin >> shot;

        if(!findLetter(entry, words[wordNum], shot)){
            --lives;
        }
        else{
            --toGuess;
        }

        cout << endl << endl;
    }

    if(lives > 0) {
        cout << "Gratulacje, zgadles haslo!!" << endl;
    } else {
        cout << "Przegrales :(" <<endl;
    }

    return 0;
}

string createUnderlines(string word) {
    string output;
    for(int i = 0; i < word.size(); ++i) {
        output += "_ ";
    }
    return output;
}

bool findLetter(string &entry, string word, char shot) {
    for(int i = 0; i < word.size(); ++i) {
        if(word[i] == shot) {
            entry[2 * i] = word[i];
            return true;
        }
    }
    return false;
}