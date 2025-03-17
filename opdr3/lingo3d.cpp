#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// checks if the letters are in the correct position or if they are in the word
string checkLetters(string word, string guess) {
  string result = "";
  for (int i = 0; i < word.length(); i++) {
    if (guess[i] == word[i]) {
      result += "+";
    } else if (word.find(guess[i]) != string::npos) {
      result += "/";
    } else {
      result += ".";
    }
  }
  return result;
}

int main() {
  // secret word put in the variable
  ifstream file("lingo.in");
  string secretWord;
  getline(file, secretWord);

  // all the possible words with the same first letter as the answer
  ifstream file2("worden.dat");
  char firstLetter = secretWord[0];
  string word;
  vector<string> words;
  while (getline(file2, word)) {
    if (word[0] == firstLetter) {
      words.push_back(word);
    }
  }
  sort(words.begin(), words.end());

  // the woordenlijst that the player can use to see which words are possible
  ofstream file3("woordenlijst.dat");
  for (string word : words) {
    file3 << word << endl;
  }

  vector<char> letters_in_secret_word;
  for (int i = 1; i < secretWord.length(); i++) {
    if (secretWord[i] != firstLetter) {
      letters_in_secret_word.push_back(secretWord[i]);
    }
  }

  vector<string> w;
  for (string word : words) {
    string results = checkLetters(secretWord, word);
    if (results == "+....") {
      w.push_back(word);
    }
  }
  words = w;

  vector<string> remaining_words;
  for (string word : words) {
    bool contains_other_letter = false;
    for (char letter : letters_in_secret_word) {
      if (word.find(letter) != string::npos) {
        contains_other_letter = true;
        break;
      }
    }
    if (!contains_other_letter) {
      remaining_words.push_back(word);
    }
  }

  ofstream file4("lingo3d.uit");
  for (string word : remaining_words) {
    file4 << word << endl;
  }
  file4 << "klaar" << endl;

 ifstream file5("lingo3d.uit");
  string output;
  while(getline(file5, output)) {
    cout << output << endl;
  }

  return 0;
}