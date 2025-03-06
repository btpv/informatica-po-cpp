#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

void brij4_decoder(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Fout bij het openen van het bestand." << endl;
        return;
    }

    string letterbrij;
    file >> letterbrij;
    file.close();

    unordered_map<char, int> letter_count;
    string boodschap = "";

    for (char letter : letterbrij) {
        letter_count[letter]++;
        if (letter_count[letter] % 3 == 0) {
            boodschap += letter;
        }
    }

    cout << boodschap << endl;
}

int main() {
    brij4_decoder("brij.in");
    return 0;
}
