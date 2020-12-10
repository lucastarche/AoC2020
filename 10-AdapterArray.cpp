//Day 10: Adapter Array
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<int> &adapters) {
    ifstream in("inputs/10-input.txt");
    for (int buf; in >> buf;) {
        adapters.push_back(buf);
    }
    in.close();
}

int solveP1(const vector<int> &adapters) {
    int dif1 = 0, dif3 = 0;
    for (int i = 0; i < (int)adapters.size() - 1; i++) {
        if (abs(adapters[i] - adapters[i + 1]) == 1) {
            dif1++;
        }
        else if (abs(adapters[i] - adapters[i + 1]) == 3) {
            dif3++;
        }
    }
    return dif1 * dif3;
}

long long solveP2(const vector<int> &adapters) {
    int n = (int)adapters.size();
    vector<long long> ways(n);
    ways[0] = 1LL;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n && adapters[j] - adapters[i] <= 3; j++) {
            ways[j] += ways[i];
        }
    }

    return ways[n - 1];
}

int main() {
    vector<int> adapters;
    getInput(adapters);

    adapters.push_back(0);
    sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters[(int)adapters.size() - 1] + 3);

    cout << "P1: " << solveP1(adapters) << '\n';
    cout << "P2: " << solveP2(adapters) << '\n';
}