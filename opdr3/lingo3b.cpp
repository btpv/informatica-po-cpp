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

  string firstWord = words[0];
  // the correct letters and wrong letters
  string results = checkLetters(secretWord, firstWord);
  vector<char> letters_in_secret_word;
  vector<char> letters_not_in_secret_word;

  // puts the letters in the secrect word into a vector
  // puts the letters that are not in the secret word into the other vector
  for (int i = 0; i < results.length(); i++) {
    if (results[i] == '+' || results[i] == '/') {
      letters_in_secret_word.push_back(firstWord[i]);
    } else {
      letters_not_in_secret_word.push_back(firstWord[i]);
    }
  }

  // correct letter but wrong position are put into a vector
  vector<char> correct_letter_wrong_position;
  vector<int> correct_letter_wrong_position_index;
  for (int i = 0; i < results.length(); i++) {
    if (results[i] == '/') {
      correct_letter_wrong_position.push_back(firstWord[i]);
      correct_letter_wrong_position_index.push_back(i);
    }
  }

  vector<string> remaining_words;
  // checks for the remaning possible words
  for (string word : words) {
    bool wrong_letter = false;
    int correct_letters = 0;
    for (char letter : letters_in_secret_word) {
      if (word.find(letter) != string::npos) {
        correct_letters++;
      }
    }
    for (char letter : letters_not_in_secret_word) {
      if (word.find(letter) != string::npos) {
        wrong_letter = true;
        break;
      }
    }
    for (int i = 0; i < correct_letter_wrong_position.size(); i++) {
      if (word[correct_letter_wrong_position_index[i]] ==
        correct_letter_wrong_position[i]) {
        wrong_letter = true;
        break;
      }
    }
    if (!wrong_letter && correct_letters == letters_in_secret_word.size()) {
      remaining_words.push_back(word);
    }
  }

  cout << remaining_words.size() << endl;

  return 0;
}