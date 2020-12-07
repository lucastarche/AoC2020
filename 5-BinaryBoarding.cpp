//Day 5: Binary Boarding
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<string> &tickets) {
    ifstream in("inputs/5-input.txt");
    for (string buf; in >> buf;) {
        tickets.push_back(buf);
    }
    in.close();
}

int getID(const string &s) {
    int rowL = 0, rowR = 128;
    for (int i = 0; i < 7; i++) {
        int mid = (rowL + rowR) / 2;
        if (s[i] == 'F') {
            rowR = mid;
        }
        else {
            rowL = mid;
        }
    }

    int colL = 0, colR = 8;
    for (int i = 7; i < 10; i++) {
        int mid = (colL + colR) / 2;
        if (s[i] == 'L') {
            colR = mid;
        }
        else {
            colL = mid;
        }
    }

    return rowL * 8 + colL;
}

int solveP1(const vector<string> &tickets) {
    int ans = 0;
    for (auto t : tickets) {
        int curr = getID(t);
        ans = max(ans, curr);
    }
    return ans;
}

int solveP2(const vector<string> &tickets) {
    vector<int> seats;
    for (auto t : tickets) {
        seats.push_back(getID(t));
    }
    
    sort(seats.begin(), seats.end());

    for (int i = 0; i < (int)seats.size() - 1; i++) {
        if (seats[i] + 2 == seats[i + 1]) {
            return seats[i] + 1;
        }
    }
    
    return -1;
}

int main() {
    vector<string> tickets;
    getInput(tickets);

    cout << "P1: " << solveP1(tickets) << '\n';
    cout << "P2: " << solveP2(tickets) << '\n';
}