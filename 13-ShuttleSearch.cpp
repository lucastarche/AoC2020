//Day 13: Shuttle Search
#include <bits/stdc++.h>

using namespace std;

void getInput(int &time, vector<pair<int, int>> &buses) {
    ifstream in("inputs/13-input.txt");
    in >> time;

    string buf;
    in >> buf;
    in.close();

    stringstream s(buf);
    int idx = -1;
    for (buf; getline(s, buf, ',');) {
        idx++;
        if (buf == "x") continue;
        buses.push_back({stoi(buf), idx});
    }
}

int solveP1(int time, const vector<pair<int, int>> &buses) {
    int ans = 1<<30, ansID = 0;
    
    for (auto x : buses) {
        int bus = x.first;
        if (ans % bus == 0) {
            ans = 0;
            ansID = bus;
        }
        else {
            if (ans > bus - time % bus) {
                ans = bus - time % bus;
                ansID = bus;
            }

        }
    }

    return ans * ansID;
}

typedef long long LL;

LL solveP2(const vector<pair<int, int>> &buses) {
    vector<pair<LL, LL>> arr;
    for (auto x : buses) {
        arr.push_back({(LL)x.first, (LL)x.second});
    }
    
    LL curr = arr[0].first;
    LL time = 0;
    LL offset = 0;
    for (int i = 1; i < (int)arr.size(); i++) {
        offset = 0;
        while (true) {
            if ((time + arr[i].second) % arr[i].first == 0) {
                if (offset == 0) {
                    offset = time;
                }
                else {
                    curr = time - offset;
                    break;
                }
            }
            
            time += curr;
        }
    }

    return offset;
}

int main() {
    int time;
    vector<pair<int, int>> buses;
    getInput(time, buses);

    cout << "P1: " << solveP1(time, buses) << '\n';
    cout << "P2: " << solveP2(buses) << '\n';
}