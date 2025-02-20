#include <iostream>
using namespace std;
const string items[16] = { "cheese","cucumber","salad","melon","bread","milk","chips","cookies","pork","ham","tomatoes","potatoes","carrots","pizza","idk","figure it out yourself" };
void drawboard() {
    // draw a grid of numbers 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << "|" << ((i * 8 + j + 1) < 10 ? " " : "") << i * 8 + j + 1 << "|  ";
        }
        cout << endl;
    }
}
int main() {
    srand(time(0));
    drawboard();
    cout << "how many players 2-4" << endl;
    int players;
    cin >> players;
    if (players < 2 || players > 4) {
        cout << "Invalid number of players. Please enter a number between 2 and 4." << endl;
        return 1;
    }
    bool basket[4][16] = { {false} };
    for (int i = 0; i < 16; i++) {
        basket[i % 4][rand() % 16] = true;
    }
    for (int i = 0; i < players; i++) {
        cout << "Player " << i + 1 << " has the following items:" << endl;
        for (int j = 0; j < 16; j++) {
            if (basket[i][j]) {
                cout << items[j] << endl;
            }
        }
        cout << endl;
    }

    return 0;
}