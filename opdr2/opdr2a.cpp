#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

string verwerk_woord(const string& woord) {
    set<char> unieke_letters;

    // Verzamel unieke letters in hoofdletters
    for (char c : woord) {
        if (isalpha(c)) {
            unieke_letters.insert(toupper(c)); 
        }
    }

    // Converteer set naar string
    return string(unieke_letters.begin(), unieke_letters.end());
}

int main() {
    ifstream invoer("WOORD.IN");
    string woord;

    if (invoer.is_open()) {
        invoer >> woord;
        invoer.close();
    } else {
        cerr << "Fout bij openen van WOORD.IN" << endl;
        return 1;
    }

    cout << verwerk_woord(woord) << endl;
    return 0;
}
