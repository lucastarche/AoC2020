//Day 12: Rain Risk
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<pair<char, int>> &instructions) {
    ifstream in("inputs/12-input.txt");
    for (string buf; in >> buf;) {
        char type = buf[0];
        int val = stoi(buf.substr(1));
        instructions.push_back({type, val});
    }
    in.close();
}

int solveP1(const vector<pair<char, int>> &instructions) {
    int x = 0, y = 0, rot = 0;

    for (auto i : instructions) {
        switch(i.first) {
            case 'N':
                x += i.second;
                break;
            case 'S':
                x -= i.second;
                break;
            case 'E':
                y += i.second;
                break;
            case 'W':
                y -= i.second;
                break;
            case 'R':
                rot += i.second;
                rot %= 360;
                break;
            case 'L':
                rot -= i.second;
                rot = (rot + 360) % 360;
                break;
            case 'F':
                if (rot == 0) {
                    y += i.second;
                }
                else if (rot == 90) {
                    x -= i.second;
                }
                else if (rot == 180) {
                    y -= i.second;
                }
                else if (rot == 270) {
                    x += i.second;
                }
        }
    }

    return abs(x) + abs(y);
}

int solveP2(const vector<pair<char, int>> &instructions) {
    int x = 0, y = 0, wx = 1, wy = 10;

    for (auto i : instructions) {
        switch(i.first) {
            case 'N':
                wx += i.second;
                break;
            case 'S':
                wx -= i.second;
                break;
            case 'E':
                wy += i.second;
                break;
            case 'W':
                wy -= i.second;
                break;
            case 'R':
                for (int j = 0; j < i.second / 90; j++) {
                    swap(wx, wy);
                    wx = -wx;
                }
                break;
            case 'L':
                for (int j = 0; j < i.second / 90; j++) {
                    swap(wx, wy);
                    wy = -wy;
                }
                break;
            case 'F':
                x += i.second * wx;
                y += i.second * wy;
                break;
        }
    }

    return abs(x) + abs(y);
}

int main() {
    vector<pair<char, int>> instructions;
    getInput(instructions);

    cout << "P1: " << solveP1(instructions) << '\n';
    cout << "P2: " << solveP2(instructions) << '\n';
}