/*
https://en.wikipedia.org/wiki/ANSI_escape_code
*/
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
const string reset = "\033[0m";
const string playercolors[4] = { "\033[31m","\033[32m","\033[33m","\033[34m" };
const string items[16] = { "cheese","cucumber","salad","melon","bread","milk","chips","cookies","pork","ham","tomatoes","potatoes","carrots","pizza","banana","paprika" };
const int itemPositions[16] = { 4,5,7,8,18,19,21,22,35,36,38,39,46,47,49,50 };
const int basketPositions[4] = { 6,20,37,48 };
const int forgetPositions[3] = { 13,26,41 };
//TODO: make it work
const int thingPositions[2][3] = { {16,17,55},{32,42,-1} };
bool basket[4][16] = { {false} };
int playerPositions[4] = { 0 };
int playerWait[4] = { 0 };
int players;
int turn = 0;
int turnStep = 0;
string infoline = "";

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
    struct timeval timeout = { 0, 0 };

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &timeout) > 0;
}
string block(bool draw) {
    return draw ? "████" : "    ";
}
int diceRoll = 0;
void drawboard(int turn, int turnStep) {
    string board = "\033[s\033[0J";

    // draw a grid of numbers 
    if (turnStep == 0) {
        diceRoll = (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count() / 100) % 6 + 1;
    }
    int lastPlayerBasketIndex[4] = { 0 };
    for (int i = 0; i < 8; i++) {
        //draw the board
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
                backgroundColor = "\033[2m";
            } else if (find(basketPositions, basketPositions + 4, currentPosition) != basketPositions + 4) {
                backgroundColor = "\033[7m";
            } else if (find(forgetPositions, forgetPositions + 3, currentPosition) != forgetPositions + 3) {
                backgroundColor = "\033[4m";
            } else if (currentPosition == 32) {
                backgroundColor = "\033[1;3;7m";
            } else if (currentPosition == 59) {
                backgroundColor = "\033[1;7m";
            }

            board += backgroundColor + forgroundColor + "|" + ((i * 8 + j + 1) < 10 ? " " : "") + to_string(currentPosition) + "|" + reset + "  ";
        }
        // draw the shopping lists
        if (i == 0) {
            for (int j = 0; j < players; j++) {
                board += playercolors[j] + "player " + to_string(j + 1) + " (" + setLength(playerPositions[j], 2) + ")\t" + reset;
            }
        } else {
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
                } else {
                    board += string(4, ' ');
                }
                board += "\t" + reset;
            }
        }
        // draw the dice
        // if (turnStep == 0 || turnStep == 1) {
        board += playercolors[turn];
        if (i < 2) {
            board += block(diceRoll > 1) + string(10, ' ') + block(diceRoll > 3);
        } else if (i > 2 && i < 5) {
            board += block(diceRoll > 5) + string(3, ' ') + block(diceRoll & 1) + string(3, ' ') + block(diceRoll > 5);
        } else if (i > 5) {
            board += block(diceRoll > 3) + string(10, ' ') + block(diceRoll > 1);
        } else {
            board += string(18, ' ');
        }
        // }
        switch (i) {
        case 0:
            board += reset + "\t" + "\033[2m" + "shopping item";
            break;
        case 1:
            board += reset + "\t" + "\033[7m" + "trow again";
            break;
        case 2:
            board += reset + "\t" + "\033[4m" + "forget something go back 4 steps";
            break;
        case 3:
            board += reset + "\t" + "\033[1;3;7m" + "wait 2 turns";
            break;
        case 4:
            board += reset + "\t" + "\033[1;7m" + "start over";
            break;
        case 5:
            board += reset + "\t" + "\033[1;3m" + "chose to move";
            break;
        case 7:
            board += reset + "\t" + setLength(infoline, 64);
        }

        board += reset + "\n";
    }
    //go back to the beginning
    cout << board + "\033[u";
    return;
}
int main() {
    srand(time(0));
    for (int i = 0; i < 16; i++) {
        int currentItem = rand() % 16;
        while (basket[i % 4][currentItem]) {
            currentItem = rand() % 16;
        }
        basket[i % 4][currentItem] = true;
    }
    cout << "how many players 2-4" << endl;
    cin >> players;
    cout << "\033[2A"; // remove those lines again
    cout << "\033[0J";
    if (players < 2 || players > 4) {
        cout << "Invalid number of players. Please enter a number between 2 and 4." << endl;
        return 1;
    }
    while (true) {
        auto start = chrono::high_resolution_clock::now();
        drawboard(turn % players, turnStep);
        if (isInputAvailable()) {
            string input;
            getline(cin, input);
            turnStep++;
        }
        if (turnStep == 1) {
            diceRoll = rand() % 6 + 1;
            drawboard(turn % players, turnStep);
            sleep(1);
            turnStep++;
        }
        if (turnStep == 2 || turnStep == 5) {
            playerPositions[turn % players] += diceRoll;
            for (int forgetPosition : forgetPositions) {
                if (playerPositions[turn % players] == forgetPosition) {
                    playerPositions[turn % players] -= 4;
                }
            }
            if (playerPositions[turn % players] == 59) {
                playerPositions[turn % players] = 0;
            }
            for (int i = 0; i < players; i++) {
                if (turn % players != i) {
                    if (playerPositions[i] == playerPositions[turn % players]) {
                        playerPositions[i] = 0;
                    }
                }
            }
            for (int i = 0; i < 16; i++) {
                if (basket[turn % players][i] && playerPositions[turn % players] == itemPositions[i]) {
                    basket[turn % players][i] = false;
                }
            }
            for (int basketPosition : basketPositions) {
                if (playerPositions[turn % players] == basketPosition) {
                    turn--;
                }
            }
            if (playerPositions[turn % players] == 32 && turnStep != 5 && playerWait[turn % players] < 0) {
                playerWait[turn % players] += 2;
            }
            if (turnStep != 5) {
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (playerPositions[turn % players] == thingPositions[i][j]) {
                            turnStep++;
                            break;
                        }
                    }
                }
            }
            if (playerPositions[turn % players] > 64) {
                for (int i = 0; i < 16; i++) {
                    if (basket[turn % players][i]) {
                        playerPositions[turn % players] -= 64;
                    }
                }
            }
            if (playerPositions[turn % players] > 64) {
                infoline = "player " + to_string(turn % players + 1) + " wins";
                drawboard(turn % players, turnStep);
                cout << "\n\n\n\n\n\n\n\n";
                return 1;
            }
            turnStep++;
        }
        while (turnStep == 4) {
            int k = -1;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 3; j++) {
                    if (playerPositions[turn % players] == thingPositions[i][j]) {
                        k = i;
                        break;
                    }
                }
            }
            infoline = "Enter the new position for player " + to_string(turn % players + 1) + " (";
            for (int thingPos : thingPositions[k]) {
                if (thingPos > 0) {
                    infoline += to_string(thingPos) += ",";
                }
            }
            infoline.pop_back();
            infoline += ") ";
            drawboard(turn % players, turnStep);
            cout << "\033[s\n\n\n\n\n\n\n\n";
            int newPos;
            cin >> newPos;
            cout << "\033[u";
            infoline = "";
            if (find(thingPositions[k], thingPositions[k] + 3, newPos) != thingPositions[k] + 3) {
                playerPositions[turn % players] = newPos;
                diceRoll = 0;
                turnStep++;
            }
        }
        if (turnStep > 5 || turnStep == 3) {
            turnStep = 0;
            while (isInputAvailable()) {
                string input;
                getline(cin, input);
            }
            turn++;
            if (playerWait[turn % players] >= 0) {
                playerWait[turn % players]--;
                if (playerWait[turn % players] == 0) {
                    turn++;
                }
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        auto remaining_time = 100 - elapsed;
        if (remaining_time > 0) {
            this_thread::sleep_for(chrono::milliseconds(remaining_time));
        }
    }

    return 0;
}