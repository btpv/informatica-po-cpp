#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string steen;
  vector<string> stenen;
  ifstream file1("orde.in");
  while (getline(file1, steen)) {
    stenen.push_back(steen);
  }

  int aantal_zetten = 0;
  int aantal_X = 0;
  int aantal_O = 0;
  int score = 0;

  for (string steen : stenen) {
    for (char zet : steen) {
      if (zet == 'X') {
        aantal_X++;
        if (aantal_O != 0) {
          score += pow((aantal_O - 1), 2);
          aantal_O = 0;
        }
      } else if (zet == 'O') {
        aantal_O++;
        if (aantal_X != 0) {
          score += pow((aantal_X - 1), 2);
          aantal_X = 0;
        }
      }
    }
    if (aantal_zetten % 6 == 0) {
      if (aantal_X != 0) {
        score += pow((aantal_X - 1), 2);
        aantal_X = 0;
      } else if (aantal_O != 0) {
        score += pow((aantal_O - 1), 2);
        aantal_O = 0;
      }
    }
  }

  cout << score << endl;
  return 0;
}