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
#include <unistd.h>
using namespace std;
const string reset = "\033[0m";
const string items[16] = { "cheese","cucumber","salad","melon","bread","milk","chips","cookies","pork","ham","tomatoes","potatoes","carrots","pizza","banana","somthing" };
int itemPositions[16] = { 4,5,7,8,18,19,21,22,35,36,38,39,46,47,49,50 };
bool basket[4][16] = { {false} };
int basketPositions[4] = { 6,20,37,48 };
const string playercolors[4] = { "\033[31m","\033[32m","\033[33m","\033[34m" };
int playerPositions[4] = { 0 };
int players;
int turn =0;
int turnStep = 0;

string setLength(string str, int length) {
    if (str.length() < length) {
        return str + string(length - str.length(), ' ');
    } else {
        return str.substr(0, length);
    }
}
string setLength(int num, int length) {
    return setLength(to_string(num), length);
}
bool isInputAvailable() {
    fd_set fds;
    struct timeval timeout = {0, 0}; // No wait time

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout) > 0;
}
void drawboard(int turn) {
    string board = "";
    board += "\033[s";
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
            board += backgroundColor + forgroundColor + "|" + ((i * 8 + j + 1) < 10 ? " " : "") + to_string(currentPosition) + "|" + reset + "  ";
        }
        switch (i) {
        case 0:
            for (int j = 0; j < players; j++) {
                board += playercolors[j] + "player " + to_string(j + 1) + " (" + to_string(playerPositions[j]) + ")\t" + reset;
            }
            break;
        default:
            for (int j = 0; j < players; j++) {
                string item = "";
                int position = 0;
                for (int k = lastPlayerBasketIndex[j]; k < 16; k++) {
                    if (basket[j][k]) {
                        lastPlayerBasketIndex[j] = k + 1;
                        item = items[k];
                        position = itemPositions[k];
                        break;
                    }
                }
                board += playercolors[j] + setLength(item, 9);
                if (position > 0) {
                    board += "(" + setLength(position, 2) + ")";
                }
                board += "\t" + reset;
            }
        }
        board += "\n";
    }
    cout << board + "\033[u";
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
    while (true) {
        drawboard(turn&players);
        // isInputAvailable()
        // wait a second
        sleep(1 / 5);
    }

    return 0;
}