/*
         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
*/
#include <iostream>
#include <algorithm>
using namespace std;
const string reset = "\033[0m";
const string items[16] = { "cheese","cucumber","salad","melon","bread","milk","chips","cookies","pork","ham","tomatoes","potatoes","carrots","pizza","idk","f you" };
int itemPositions[16] = { 4,5,7,8,18,19,21,22,35,36,38,39,46,47,49,50 };
bool basket[4][16] = { {false} };
int basketPositions[4] = { 6,20,37,48 };
const string playercolors[4] = { "\033[31m","\033[32m","\033[33m","\033[34m" };
int playerPositions[4] = { 0 };
int players;
void drawboard() {
    // draw a grid of numbers 
    int lastPlayerBasketIndex[4] = { 0 };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int currentPosition = i * 8 + j + 1;
            string forgroundColor = "";
            string backgroundColor = "";
            for (int k = 0; k < players; k++) {
                if (playerPositions[k] == currentPosition) {
                    forgroundColor = playercolors[k];
                    break;
                }
            }
            if (find(itemPositions, itemPositions + 16, currentPosition) != itemPositions + 16) {
                backgroundColor = "\033[45m";
            } else if (find(basketPositions, basketPositions + 4, currentPosition) != basketPositions + 4) {
                backgroundColor = "\033[46m";
            }
            cout << backgroundColor << forgroundColor << "|" << ((i * 8 + j + 1) < 10 ? " " : "") << currentPosition << "|" << reset << "  ";
        }
        switch (i) {
        case 0:
            for (int j = 0; j < players; j++) {
                cout << playercolors[j] << "player " << j + 1 << " (" << playerPositions[j] << ")\t";
            }
            break;
        default:
            for (int j = 0; j < players; j++) {
                string item = "";
                for (int k = lastPlayerBasketIndex[j]; k < 16; k++) {
                    if (basket[j][k]) {
                        lastPlayerBasketIndex[j] = k+1;
                        item = items[k];
                        break;
                    }
                }
                cout << playercolors[j] << item + string(16-item.length(),' ');
            }
        }
        cout << endl;
    }
}
int main() {
    srand(time(0));
    cout << "how many players 2-4" << endl;
    cin >> players;
    cout << "\033[2A"; // remove those lines again
    cout << "\033[0J";
    if (players < 2 || players > 4) {
        cout << "Invalid number of players. Please enter a number between 2 and 4." << endl;
        return 1;
    }
    for (int i = 0; i < 16; i++) {
        int currentItem = rand() % 16;
        while (basket[i % 4][currentItem]) {
            currentItem = rand() % 16;
        }
        basket[i % 4][currentItem] = true;
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
    for (int i = 0; i < 4; i++) {
        playerPositions[i] = rand() % 64;
        cout << playerPositions[i] << endl;
    }
    drawboard();

    return 0;
}