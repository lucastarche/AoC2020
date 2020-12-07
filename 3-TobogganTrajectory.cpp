//Day 3: Toboggan Trajectory
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<string> &map) {
    ifstream in("inputs/3-input.txt");
    for (string buf; getline(in, buf);) {
        map.push_back(buf);
    }
    in.close();
}

int amount(const vector<string> &map, int right, int down) {
    int n = (int)map.size();
    int m = (int)map[0].size();

    int ans = 0;
    for (int x = 0, y = 0; x < n; x = x + down) {
        if (map[x][y] == '#') ans++;

        y = (y + right) % m;
    }    
    return ans;
}

//Part 1: Easy. Modified to allow for P2 as well. function amount() runs in O(n).
int solveP1(const vector<string> &map) {
    return amount(map, 3, 1);
}

//Part 2: Same as P1, but less ad-hoc. Also, doesnt fit in an int so careful with that.
long long solveP2(const vector<string> &map) {
    vector<pair<int, int>> queries = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };

    long long ans = 1;
    for (auto q : queries) {
        ans *= (long long)amount(map, q.first, q.second);
    }
    return ans;
}

int main() {
    vector<string> map;
    getInput(map);
    if (map.empty()) {
        cerr << "Couldnt open file" << '\n';
        return 1;
    }

    cout << "P1: " << solveP1(map) << '\n';
    cout << "P2: " << solveP2(map) << '\n';
}