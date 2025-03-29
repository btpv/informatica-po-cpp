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
  // to be guessed word put in the variable
  ifstream file("lingo0.in");
  string answer;
  getline(file, answer);

  // all the possible words with the same first letter as the answer
  ifstream file2("worden.dat");
  char firstLetter = answer[0];
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

  // gets the guess from the player
  ifstream file4("lingo.in");
  string guess;
  getline(file4, guess);
  for (char& letter : guess) {
    letter = toupper(letter);
  }

  // shows what is correct and wrong
  cout << checkLetters(answer, guess) << endl;

  return 0;
}
