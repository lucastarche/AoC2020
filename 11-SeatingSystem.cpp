//Day 11: Seating System
#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void getInput(vector<string> &seats) {
    ifstream in("inputs/11-input.txt");
    for (string buf; in >> buf;) {
        seats.push_back(buf);
    }
    in.close();
}

vector<string> iterationP1(const vector<string> &seats) {
    int n = (int)seats.size();
    int m = (int)seats[0].size();

    vector<string> res(n, string(m, ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seats[i][j] == '.') {
                res[i][j] = '.';
                continue;
            }

            int amount = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (seats[x][y] == '#') amount++;
            }

            if (seats[i][j] == 'L' && amount == 0) {
                res[i][j] = '#';
            }
            else if (seats[i][j] == '#' && amount >= 4) {
                res[i][j] = 'L';
            }
            else {
                res[i][j] = seats[i][j];
            }
        }
    }

    return res;
}

int solveP1(vector<string> seats) {
    vector<string> buf = iterationP1(seats);
    while (buf != seats) {
        seats = buf;
        buf = iterationP1(buf);
    }

    int n = (int)seats.size();
    int m = (int)seats[0].size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seats[i][j] == '#') ans++;
        }
    }
    return ans;
}

vector<string> iterationP2(const vector<string> &seats) {
    int n = (int)seats.size();
    int m = (int)seats[0].size();

    vector<string> res(n, string(m, ' '));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seats[i][j] == '.') {
                res[i][j] = '.';
                continue;
            }

            int amount = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                while (x >= 0 && y >= 0 && x < n && y < m && seats[x][y] == '.') {
                    x = x + dx[k];
                    y = y + dy[k];
                }
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (seats[x][y] == '#') amount++;
            }

            if (seats[i][j] == 'L' && amount == 0) {
                res[i][j] = '#';
            }
            else if (seats[i][j] == '#' && amount >= 5) {
                res[i][j] = 'L';
            }
            else {
                res[i][j] = seats[i][j];
            }
        }
    }

    return res;
}

int solveP2(vector<string> seats) {
    vector<string> buf = iterationP1(seats);
    while (buf != seats) {
        seats = buf;
        buf = iterationP2(buf);
    }

    int n = (int)seats.size();
    int m = (int)seats[0].size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (seats[i][j] == '#') ans++;
        }
    }
    return ans;
}

int main() {
    vector<string> seats;
    getInput(seats);

    cout << "P1: " << solveP1(seats) << '\n';
    cout << "P2: " << solveP2(seats) << '\n';
}