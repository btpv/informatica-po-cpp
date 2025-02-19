#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("opdr1.txt");
    string word, currentWord;
    // set word to the first line since that is the word to check against
    getline(infile, word);
    int charactersInWord[26] = { 0 };
    // count characters in the correct word
    for (char character : word) {
        charactersInWord[character - 'a']++;
    }
    vector<string> testedWords;
    int wordCount = 0;
    int uniqueGoodWordCount = 0;
    int duplicateWordCount = 0;
    int badWordCount = 0;
    // read every other words and check them
    while (getline(infile, currentWord)) {
        if (currentWord == "STOP") {
            break;
        }
        wordCount++;
        // if the current word is already checked once count is as a duplicate
        if (find(testedWords.begin(), testedWords.end(), currentWord) != testedWords.end()) {
            duplicateWordCount++;
        }
        // if the current word is longer then the current word count word as a bad word because if its longer it cant be made from the same letters
        else if (currentWord.length() > word.length()) {
            badWordCount++;
        } else // otherwise check if the current word can be made from the same letters as the word
        {
            int currentTestCharactersInWord[26];
            // copy the array of characters so we can make changes to it with out it interfearing with later words
            copy(charactersInWord, charactersInWord + 26, currentTestCharactersInWord);
            // check if all characters in the current word are in the correct word
            for (char character : currentWord) {
                if (currentTestCharactersInWord[character - 'a'] > 0) {
                    currentTestCharactersInWord[character - 'a']--;
                } else {
                    badWordCount++;
                    break;
                }
            }
        }
        // add current words to the tested words for duplicate detection
        testedWords.push_back(currentWord);
    }
    // if a word is not duplicated and is not a bad word it must be correct and unique
    uniqueGoodWordCount = wordCount - duplicateWordCount - badWordCount;
    cout << wordCount << endl;           // Total words
    cout << uniqueGoodWordCount << endl; // Unique good words
    cout << duplicateWordCount << endl;  // Same words
    cout << badWordCount << endl;        // Bad words
    infile.close();
    return 0;
}