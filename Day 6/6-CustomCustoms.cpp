//Day 6: Custom Customs
#include <bits/stdc++.h>

using namespace std;

void getInput(vector<string> &groups, vector<int> &amount) {
    ifstream in("6-input.txt");
    int n = 0;
    groups.push_back("");
    amount.push_back(0);
    for (string buf; getline(in, buf);) {
        if (buf == "") {
            groups.push_back(buf);
            amount.push_back(0);
            n++;
        }   
        else {
            groups[n] += buf;
            amount[n]++;
        }
    }
    in.close();
}

int solveP1(const vector<string> &groups) {
    int ans = 0;
    for (auto g : groups) {        
        sort(g.begin(), g.end());
        auto end = unique(g.begin(), g.end());
        g.erase(end, g.end());
        ans += (int)g.size();
    }
    return ans;
}

int solveP2(vector<string> &groups, const vector<int> &amount) {
    int ans = 0;
    for (int i = 0; i < (int)groups.size(); i++) {
        sort(groups[i].begin(), groups[i].end());
        int curr = 1;
        for (int j = 1; j < (int)groups[i].size(); j++) {
            if (groups[i][j] == groups[i][j - 1]) curr++;
            else {
                if (curr == amount[i]) ans++;
                curr = 1;
            }
        }
        if (curr == amount[i]) ans++;
    }
    return ans;
}

int main() {
    vector<string> groups;
    vector<int> amount;
    getInput(groups, amount);

    cout << "P1: " << solveP1(groups) << '\n';
    cout << "P2: " << solveP2(groups, amount) << '\n';
}