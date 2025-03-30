#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Functie om te tellen hoeveel letters gelijk zijn op dezelfde positie
int count_matching_letters(const string& a, const string& b) {
    int count = 0;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    // Woordenlijst inlezen
    ifstream wordfile("woordenlijst.txt");
    vector<string> words;
    string word;

    while (wordfile >> word) {
        words.push_back(word);
    }

    // Invoerwoord inlezen
    ifstream infile("WOORD.IN");
    string start_word;
    infile >> start_word;


    // Vectoren voor vorige en huidige woorden
    vector<string> prevwords = { start_word };
    vector<string> currentwords;
    vector<vector<string>> trapeziums;

    // Zoekproces
    while (!prevwords.empty()) {
        currentwords.clear();
        vector<string> trapezium;

        for (const string& w : words) {
            for (const string& prev : prevwords) {
                if (count_matching_letters(w, prev) == w.size() - 1) {
                    currentwords.push_back(w);
                    trapezium.push_back(w);
                }
            }
        }

        if (!trapezium.empty()) {
            trapeziums.push_back(trapezium);
        }

        prevwords = currentwords;
    }

    // Uitvoer naar bestand
    ofstream outfile("PUZZEL2B");
    if (!trapeziums.empty()) {
        for (const string& w : trapeziums.back()) {
            outfile << w << endl;
        }
    }

    outfile << "stop" << endl;

    return 0;
}
